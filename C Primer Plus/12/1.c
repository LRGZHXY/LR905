#include <stdio.h>
static int count=0;
int counter(void)
{
    return ++count;
}
int main()
{
    int i,j;
    scanf("%d",&i);
    for(j=1;j<=i;j++)
    {
        printf("count=%d\n",counter());
    }
    printf("The function called %d times.\n",count);
    return 0;
}