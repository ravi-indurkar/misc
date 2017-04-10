#include <stdio.h>
#include <assert.h>

typedef unsigned char byte_t;
typedef unsigned long data_t;

static data_t
mul_by_02(data_t data)
{
	data_t retval;

	retval = ((data & 0x7f7f7f7f) << 1) ^
		(((data & 0x80808080) - ((data & 0x80808080) >> 7)) &
		0x1d1d1d1d);
	
	return retval;
}

static data_t
mul_by_power_of_02(unsigned power, data_t data)
{
	for (; power != 0; power--) {
		data = mul_by_02(data);
	}
	return data;
}

static data_t
mul(byte_t byte, data_t data)
{
	data_t retval = 0;

	while (1) {
		if (byte & 0x01) {
			retval ^= data;
		}
		byte >>= 1;
		if (byte == 0) {
			break;
		}
		data = mul_by_02(data);
	}
	return retval;
}


static byte_t powers_of_02[256];
static byte_t inverse[256];

static void
init_tables(void)
{
	unsigned x, y;

	powers_of_02[0] = 1;
	for (x = 1; x != 256; x++) {
		powers_of_02[x] = mul_by_02(powers_of_02[x - 1]);
	}

	inverse[0] = 0;
	inverse[1] = 1;
	for (x = 2; x != 256; x++) {
		assert(x < 256);
		inverse[x] = x;
		for (y = 0; y != 253; y++) {
			inverse[x] = mul(inverse[x], x);
		}
	}
}

// Classic RAID 6 algorithms using N data disks + P + Q.

typedef struct {
	byte_t num_data_disks;
	data_t data[255];
	data_t p;
	data_t q;
} stripe_t;

static data_t
P_from_stripe(const stripe_t *stripe)
{
	unsigned disk;
	data_t retval;

	assert(stripe->num_data_disks != 0);

	retval = stripe->data[0];
	for (disk = 1; disk != stripe->num_data_disks; disk++) {
		retval ^= stripe->data[disk];
	}
	return retval;
}

static data_t
Q_from_stripe(const stripe_t *stripe)
{
	unsigned disk;
	data_t retval;

	assert(stripe->num_data_disks != 0);

	retval = stripe->data[stripe->num_data_disks - 1];
	for (disk = stripe->num_data_disks - 1; disk != 0; disk--) {
		retval = mul_by_02(retval);
		retval ^= stripe->data[disk - 1];
	}

	return retval;
}

static enum {
	STRIPE_OK,		// Stripe is OK
	STRIPE_BAD,		// Stripe is bad in two or more ways
	STRIPE_BAD_P,		// Stripe is OK, except for P
	STRIPE_BAD_Q,		// Stripe is OK, except for Q
	STRIPE_BAD_D,		// Stripe is OK, except for one data disk
}
stripe_analyze(const stripe_t *stripe, unsigned *disk)
{
	data_t p_prime, q_prime;

	p_prime = P_from_stripe(stripe);
	q_prime = Q_from_stripe(stripe);

	if (p_prime == stripe->p) {	
		if (q_prime == stripe->q) {
			return STRIPE_OK;
		}
		return STRIPE_BAD_Q;
	}
	if (q_prime == stripe->q) {
		return STRIPE_BAD_P;
	}

	unsigned x;
	data_t pattern = p_prime ^ stripe->p;
	data_t q_diff = q_prime ^ stripe->q;

	for (x = 0; x != stripe->num_data_disks; x++) {
		if (pattern == q_diff) {
			break;
		}
		pattern = mul_by_02(pattern);
	}
	if (x < stripe->num_data_disks) {
		*disk = x;
		return STRIPE_BAD_D;
	}
	return STRIPE_BAD;
}

static void
stripe_display(const stripe_t *stripe)
{
	unsigned disk;

	for (disk = 0; disk != stripe->num_data_disks; disk++) {
		if (disk < 10) {
			printf("  D%u:", disk);
		} else if (disk < 100) {
			printf(" D%u:", disk);
		} else {
			printf("D%u:", disk);
		}
		printf("%08lx", stripe->data[disk]);
		if (disk % 6 == 5) {
			printf("\n");
		}
	}
	printf("   P:%08lx   Q:%08lx  ", stripe->p, stripe->q);
	switch (stripe_analyze(stripe, &disk)) {
	case STRIPE_OK:
		printf("Everything consistent.\n");
		break;
	case STRIPE_BAD:
		printf("Two or more problems.\n");
		break;
	case STRIPE_BAD_P:
		printf("P is inconsistent.\n");
		break;
	case STRIPE_BAD_Q:
		printf("Q is inconsistent.\n");
		break;
	case STRIPE_BAD_D:
		printf("D%u is inconsistent.\n", disk);
		break;
	default:
		assert(0);
	}
}


static void
stripe_init(stripe_t *stripe, unsigned num_data_disks, data_t data)
{
	unsigned disk;

	assert(num_data_disks != 0);
	assert(num_data_disks < 256);

	stripe->num_data_disks = num_data_disks;
	for (disk = 0; disk != num_data_disks; disk++) {
		stripe->data[disk] = data;
	}
	stripe->p = data;
	stripe->q = data;
}

static void
stripe_check(const stripe_t *stripe)
{
	assert(P_from_stripe(stripe) == stripe->p);
	assert(Q_from_stripe(stripe) == stripe->q);
}


static void
stripe_partial_write(stripe_t *stripe, unsigned disk, data_t data)
{
	data_t diff;

	assert(disk < stripe->num_data_disks);
	diff = stripe->data[disk] ^ data;
	stripe->data[disk] = data;
	stripe->p ^= diff;
	stripe->q ^= mul_by_power_of_02(disk, diff);

	stripe_check(stripe);
}

static void
stripe_full_write(stripe_t *stripe, data_t d0, data_t d1, data_t d2,
	data_t d3, data_t d4, data_t d5, data_t d6, data_t d7, data_t d8,
	data_t d9, data_t d10, data_t d11)
{
	assert(stripe->num_data_disks == 12);

	stripe->data[0] = d0;
	stripe->data[1] = d1;
	stripe->data[2] = d2;
	stripe->data[3] = d3;
	stripe->data[4] = d4;
	stripe->data[5] = d5;
	stripe->data[6] = d6;
	stripe->data[7] = d7;
	stripe->data[8] = d8;
	stripe->data[9] = d9;
	stripe->data[10] = d10;
	stripe->data[11] = d11;
	stripe->p = P_from_stripe(stripe);
	stripe->q = Q_from_stripe(stripe);

	stripe_check(stripe);
}

static void
stripe_corrupt_p(stripe_t *stripe, data_t diff)
{
	assert(diff != 0);
	stripe->p ^= diff;
}

static void
stripe_corrupt_q(stripe_t *stripe, data_t diff)
{
	assert(diff != 0);
	stripe->q ^= diff;
}

static void
stripe_corrupt_d(stripe_t *stripe, unsigned disk, data_t diff)
{
	assert(disk < stripe->num_data_disks);
	assert(diff != 0);
	stripe->data[disk] ^= diff;
}
static void
stripe_recover_p(stripe_t *stripe)
{
	printf("\nBefore recover p:\n");
	stripe_display(stripe);

	stripe->p = P_from_stripe(stripe);

	printf("After recover p:\n");
	stripe_display(stripe);
	stripe_check(stripe);
}

static void
stripe_recover_q(stripe_t *stripe)
{
	printf("\nBefore recover q:\n");
	stripe_display(stripe);

	stripe->q = Q_from_stripe(stripe);

	printf("After recover q:\n");
	stripe_display(stripe);
	stripe_check(stripe);
}

static void
stripe_recover_d(stripe_t *stripe, unsigned x)
{
	data_t p_prime;

	assert(x < 10);

	printf("\nBefore recover d%u:\n", x);
	stripe_display(stripe);

	stripe->data[x] = 0;
	p_prime = P_from_stripe(stripe);
	stripe->data[x] = stripe->p ^ p_prime;

	printf("After recover d%u:\n", x);
	stripe_display(stripe);
	stripe_check(stripe);
}

static void
stripe_recover_pq(stripe_t *stripe)
{
	printf("\nBefore recover p q:\n");
	stripe_display(stripe);

	stripe->p = P_from_stripe(stripe);
	stripe->q = Q_from_stripe(stripe);

	printf("After recover p q:\n");
	stripe_display(stripe);

	stripe_check(stripe);
}

static void
stripe_recover_dq(stripe_t *stripe, unsigned x)
{
	data_t p_prime;

	assert(x < 10);

	printf("\nBefore recover d%u q:\n", x);
	stripe_display(stripe);

	stripe->data[x] = 0;
	p_prime = P_from_stripe(stripe);
	stripe->data[x] = stripe->p ^ p_prime;
	stripe->q = Q_from_stripe(stripe);

	printf("After recover d%u q:\n", x);
	stripe_display(stripe);
	stripe_check(stripe);
}

static void
stripe_recover_dp(stripe_t *stripe, unsigned x)
{
	data_t q_prime;

	assert(x < 10);

	printf("\nBefore recover d%u p:\n", x);
	stripe_display(stripe);

	stripe->data[x] = 0;
	q_prime = Q_from_stripe(stripe);
	stripe->data[x] = mul(powers_of_02[255 - x], stripe->q ^ q_prime);
	stripe->p = P_from_stripe(stripe);

	printf("After recover d%u p:\n", x);
	stripe_display(stripe);
	stripe_check(stripe);
}


static void
stripe_recover_dd(stripe_t *stripe, unsigned x, unsigned y)
{
	data_t p_prime, q_prime;
	byte_t a, b;

	assert(x < y);
	assert(y < stripe->num_data_disks);

	printf("\nBefore recover d%u d%u:\n", x, y);
	stripe_display(stripe);

	stripe->data[x] = 0;
	stripe->data[y] = 0;
	p_prime = P_from_stripe(stripe);
	q_prime = Q_from_stripe(stripe);

	a = mul(powers_of_02[y - x], inverse[powers_of_02[y - x] ^ 0x01]);
	b = mul(powers_of_02[255 - x], inverse[powers_of_02[y - x] ^ 0x01]);

	stripe->data[x] = mul(a, stripe->p ^ p_prime) ^
		mul(b, stripe->q ^ q_prime);
	stripe->data[y] = stripe->p ^ p_prime ^ stripe->data[x];

	printf("Afeter recover d%u d%u:\n", x, y);
	stripe_display(stripe);
	stripe_check(stripe);
}

static void
stripe_repair(stripe_t *stripe)
{
	// FIX MSS, Should we be repairing each byte
	// so that one can handle multiple non overlapping
	// corruptions on different disks?

	unsigned disk;

	switch (stripe_analyze(stripe, &disk)) {
	case STRIPE_OK:
		stripe_check(stripe);
		break;
	case STRIPE_BAD:
		printf("Repair is impossible without more information\n");
		break;
	case STRIPE_BAD_P:
		stripe_recover_p(stripe);
		break;
	case STRIPE_BAD_Q:
		stripe_recover_q(stripe);
		break;
	case STRIPE_BAD_D:
		stripe_recover_d(stripe, disk);
		break;
	default:
		assert(0);
	}
}

// Demonstration code.

static void
demo(void)
{
	stripe_t stripe;
	data_t d10, d11;

	printf("\nInitializing array of 10 data disks, "
		"two imaginary disks, P and Q.\n");
	stripe_init(&stripe, 12, 0x0000ffff);
	stripe_recover_dd(&stripe, 10, 11);
	d10 = stripe.data[10];
	d11 = stripe.data[11];
	
	stripe_partial_write(&stripe, 3, 0xabcdef12);

	stripe_full_write(&stripe, 0xaabbccdd, 0xdd00, 0xf, 0xffffffff,
		0x303c02, 0x2332343a, 0xdad2ace, 0xabc9999, 0x0, 0xbead,
		d10, d11);
	stripe_partial_write(&stripe, 8, 0xbeafface);

	stripe_corrupt_p(&stripe, 0xabcdabcd);
	stripe_recover_p(&stripe);

	stripe_corrupt_q(&stripe, 0x96969696);
	stripe_recover_q(&stripe);

	stripe_corrupt_d(&stripe, 7, 0xcab);
	stripe_recover_d(&stripe, 7);


	stripe_corrupt_p(&stripe, 0x1111111);
	stripe_corrupt_q(&stripe, 0x2222222);
	stripe_recover_pq(&stripe);

	stripe_corrupt_d(&stripe, 5, 0x142342cc);
	stripe_corrupt_q(&stripe, 0x12345678);
	stripe_recover_dq(&stripe, 5);

	stripe_corrupt_d(&stripe, 9, 0xa5bcd61c);
	stripe_corrupt_p(&stripe, 0x12345678);
	stripe_recover_dp(&stripe, 9);

	stripe_corrupt_d(&stripe, 2, 0x12345678);
	stripe_corrupt_d(&stripe, 8, 0xaceace);
	stripe_recover_dd(&stripe, 2, 8);

	stripe_corrupt_p(&stripe, 0xbadbad);
	stripe_repair(&stripe);
	stripe_corrupt_q(&stripe, 0xdead);
	stripe_repair(&stripe);
	stripe_corrupt_d(&stripe, 5, 0xfab0000);
	stripe_repair(&stripe);
}

int
main(__attribute__ ((unused)) int argc, __attribute__ ((unused)) char **argv)
{
	init_tables();
	demo();
	return 0;
}
