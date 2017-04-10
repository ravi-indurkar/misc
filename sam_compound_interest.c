main()
{

int i, year=0;

float dollars, multi, answer;

printf("Enter Dollars: "); scanf("%f", &dollars);

printf("Enter multiplication-number: "); scanf("%f", &multi);


printf("Enter years: "); scanf("%d", &year);

    answer = dollars ;
    for (i=0; i<year; i++) {
        printf("Year-number=%d  amount=%9.3f\n", i, answer);
        answer = answer * multi;
    }


}
