// #include <stdio.h>
// int main()
// {
//     char ch;
//     scanf("%c",&ch);
//     int length=ch-'A';
//     for(int i=0;i<=length;i++)
//     {
//         char t='A'-1;
//         for(int j=0;j<=length-i;j++)
//         {
//             printf(" ");
//         }
//         for(int j=0;j<=i;j++)
//         {
//             printf("%c",++t);
//         }
//         for(int j=0;j<i;j++)
//         {
//             printf("%c",--t);
//         }
//         printf("\n");
//     }
//     return 0;
// }



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



#include <stdio.h>
int main()
{
    int i=0;
    char s[255];
    while(scanf("%c",&s[i])&&i+1<255&&s[i]!='\n')
    {
        ++i;
    }
    for(i--;i>=0;i--)
    {
        printf("%c",s[i]);
    }
    printf("\nDone.\n");
    return 0;
}






