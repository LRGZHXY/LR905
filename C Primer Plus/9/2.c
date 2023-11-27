#include <stdio.h>
void sort(double *a,double *b,double *c)
{
    double temp;
    if(*a>*b)
    {
        temp=*a;
        *a=*b;
        *b=temp;
    }
    if(*a>*c)
    {
        temp=*a;
        *a=*c;
        *c=temp;
    }
    if(*b>*c)
    {
        temp=*b;
        *b=*c;
        *c=temp;
    }
    return 0;
}
int main()
{
    double x,y,z;
    while(scanf("%lf %lf %lf",&x,&y,&z)==3)
    {
        sort(&x,&y,&z);
        printf("min:%lf\n",x);
        printf("middle:%lf\n",y);
        printf("max:%lf",z);
    }
    return 0;
}