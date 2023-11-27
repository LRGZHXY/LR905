#include <stdio.h>
#define N 4
int Add(const int a[],const int b[],int c[],int n)
{
    for(int i=0;i<N;i++)
    {
        c[i]=a[i]+b[i];
    }
}
void Printf(const int d[],int n)
{
    for(int i=0;i<N;i++)
    {
        printf("%-3d",d[i]);
    }
    printf("\n");
}
int main()
{
    int a[N]={2,4,5,8};
    int b[N]={1,0,4,6};
    int c[N]={0};
    Printf(a,N);
    Printf(b,N);
    Add(a,b,c,N);
    Printf(c,N);
    return 0;
}
