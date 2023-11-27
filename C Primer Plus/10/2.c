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