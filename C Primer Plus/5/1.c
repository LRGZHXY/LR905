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
