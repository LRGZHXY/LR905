#include <stdio.h>
#define N 5
int max_arr(const int a[],int n)
{
    int maxa=a[0];
    for(int i=1;i<n;i++)
    {
        maxa=maxa<a[i]?a[i]:maxa;
    }
    return maxa;
}
void Print(const int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
    printf("\n");
}
int main()
{
    int max;
    int arr[N]={1,2,3,4,5};
    Print(arr,N);
    max=max_arr(arr,N);
    printf("%d",max);
    return 0;
}
