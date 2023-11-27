#include <stdio.h>
double LG(double a,double b)
{
    return (a-b)/(a*b);
}
int main()
{
    double a,b;
    printf("Please enter two numbers (q to quit): ");
    while(scanf("%lf %lf",&a,&b)==2)
    {
        printf("(%lf-%lf)/(%lf*%lf)",a,b,a,b);
        printf("=%g\n",LG(a,b));
        printf("You can enter again (q to quit): ");
    }
    printf("Done.\n");
    return 0;
}