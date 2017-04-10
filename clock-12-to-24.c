#include <stdio.h>
#include <string.h>

int main()
{

	char buf[100];
	char *am;
	int hr, min, sec;

	printf("Enter time: "); scanf("%s", buf);

	am = strstr( buf, "AM");

	if (am == NULL) {
		sscanf(buf, "%2d:%2d:%2dPM", &hr, &min, &sec);
		hr += 12;
	} else {
		sscanf(buf, "%2d:%2d:%2dAM", &hr, &min, &sec);
	}
	printf("%02d:%02d:%02d\n", hr, min, sec);

}
