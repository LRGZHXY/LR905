#include <stdio.h>
void Fib(int len)
{
    int i;
    unsigned int x,y,t;
    x=y=1;
    for(i=0;i<len;i++)
    {
        printf("%lu\n",x);
        t=x+y;
        x=y;
        y=t;
    }
    return 0;
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        Fib(n);
        printf("You can enter again(<=0 or q to quit): ");
    }
    return 0;
}