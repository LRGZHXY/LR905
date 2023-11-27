#include <stdio.h>
int main()
{
    int n,j=0,o=0;
    double sj=0,so=0;
    while(scanf("%d",&n)==1&&n)
    {
        (n%2?(++j,sj+=n):(++o,so+=n));
    }
    if(j>0)
    {
        printf("%lf\n",(float)sj/j);
    }
    if(o>0)
    {
        printf("%lf\n",(float)so/o);
    }
    return 0;
}