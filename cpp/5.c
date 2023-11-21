#include <stdio.h>
#define MINUTES_PER_HOUR 60

int main()
{
    int m,hour,minutes;

    printf("Please enter a number for minute (<= 0 to quit): ");
    while(scanf("%d",&m)==1&&m>0)
    {
        hour=m/MINUTES_PER_HOUR;
        minutes=m%MINUTES_PER_HOUR;
        printf("%d minutes=%d hours and %d minutes.\n",m,hour,minutes);
        printf("You can enter again (<= 0 to quit): ");
    }
    printf("Done.");

    return 0;
}




#include <stdio.h>
#define CM_PER_INCH 2.54
#define CM_PER_FEET 30.48

int main()
{
    int feet;
    double cm,inch;

    printf("Enter a height in centimeters: ");
    while((scanf("%lf",&cm)==1)&&(cm>0))
    {
        feet=(int)(cm/CM_PER_FEET);
        inch=(cm-CM_PER_FEET*feet)/CM_PER_INCH;
        printf("%.1f cm = %d feet, %.1f inches\n", cm, feet, inch);
        printf("Enter a height in centimeters (<=0 to quit): ");
    }
    printf("bye\n");

    return 0;
}



#include <stdio.h>

void cal_temperatures(double f_t)
{
    const double f_val = 32.0;
    const double k_val = 273.16;
    double t = 5.0 / 9.0 * (f_t - f_val);
    printf("Centigrade temperature: %.2lf°C\n", t);
    printf("Fahrenheit temperature: %.2lf°C\n", f_t);
    printf("Kelvin temperature: %.2lf°C\n", t + k_val);
}

int main()
{
    double temp;

    printf("Please enter a temperature number (q to quit): ");
    while(scanf("%lf",&temp)==1)
    {
        cal_temperatures(temp);
        printf("You can enter again (q to quit): ");
    }
    printf("Done.\n");

    return 0;
}



