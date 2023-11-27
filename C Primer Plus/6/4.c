#include <stdio.h>
int main()
{
    double a[8],b[8];
    for(int i=0;i<8;i++)
    {
        scanf("%lf",&a[i]);
    }
    b[0]=a[0];
    for(int i=1;i<8;i++)
    {
        b[i]=a[i]+b[i-1];
    }
    for(int i=0;i<8;i++)
    {
        printf("%-3g",a[i]);
    }
    printf("\n");
    for(int i=0;i<8;i++)
    {
        printf("%-3g",b[i]);
    }
    printf("\nDone\n");
    return 0;
}