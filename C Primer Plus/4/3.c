#include <stdio.h>
#define GALLON_TO_LITRE 3.785
#define MILE_TO_KM 1.609
int main()
{
    double range,oil;
    printf("Please input the range you traveled(in mile): ");
    scanf("%lf",&range);
    printf("Please input the oil you spend(in gallon): ");
    scanf("%lf",&oil);
    printf("%.1lf\n",range/oil);
    printf("%.1lf",100.0*(oil*GALLON_TO_LITRE)/(range*MILE_TO_KM));
    return 0;
}