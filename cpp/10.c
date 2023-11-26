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



#include <stdio.h>
#define N 5
void Printf(const double arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%-3g",arr[i]);
    }
    printf("\n");
}
int max_arr_index(const double arr[],int n)
{
    double max=arr[0];
    int index=0;
    for(int i=0;i<n;i++)
    {
        if(max<arr[i])
        {
            max=arr[i];
            index=i;
        }
    }
    return index;
}
int main()
{
    int max_index;
    double arr[N]={1.0,2.0,3.0,4.0,5.0};
    Printf(arr,N);
    max_index=max_arr_index(arr,N);
    printf("%d",max_index);
    return 0;
}




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

