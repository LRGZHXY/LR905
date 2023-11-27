#include <stdio.h>
int main()
{
    int n,flag=1;
    double Sum=0;
    printf("Please enter a number (<= 0 to quit): ");
    while((scanf("%d",&n)==1)&&(n>0))
    {
        double sum1=0.0;
        double sum2=0.0;
        for(int i=1;i<=n;i++)
        {
            sum1+=1.0/i;
            sum2+=(1.0/i)*flag;
            flag*=-1;
        }
        printf("1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ...");
        printf("sums are %lf\n",sum1);
        printf("1.0 - 1.0/2.0 + 1.0/3.0 - 1.0/4.0 + ...");
        printf("sums are %lf\n",sum2);
        Sum=sum1+sum2;
        printf("the sum is %lf\n",Sum);
        printf("\nYou can enter again (<= 0 to quit): ");
    }
    printf("Done.\n");
    return 0;
}