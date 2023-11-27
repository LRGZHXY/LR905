#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define len 100
void sort(int a[],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]<a[j])
            {
                temp=a[j];
                a[j]=a[i];
                a[i]=temp;
            }
        }
    }
    return 0;
}
void Print(const int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%-5d ",a[i]);
        if(0==(i+1)%10)
        {
            putchar('\n');
        }
    }
    putchar('\n');
    return 0;
}
int main()
{
    int i,a[len];
    srand((unsigned int)time(0));
    for(i=0;i<len;i++)
    {
        a[i]=rand()%10+1;
    }
    Print(a,len);
    printf("\n");
    sort(a,len);
    Print(a,len);
    return 0;
}


