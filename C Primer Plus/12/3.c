#include <stdio.h>
#include <stdlib.h>
#define n 10
#define len 1000
int main()
{
    int i,temp,a[n+1];
    unsigned int seeds;
    for(seeds=1;seeds<=n;seeds++)
    {
        printf("Time #%d:\n",seeds);
        srand(seeds);
        for(i=0;i<n+1;i++)
        {
            a[i]=0;
        }
        for(i=0;i<len;i++)
        {
            temp=rand()%10+1;
            a[temp]++;
        }
        for(i=1;i<n+1;i++)
        {
            printf("%-3d appeared %d times.\n",i,a[i]);
        }
    }
    return 0;
}

