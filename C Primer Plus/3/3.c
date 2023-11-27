#include <stdio.h>
int main()
{
    int n,pint,ounce,bigspoon,teaspoon;
    printf("Please you enter a number of cups: ");
    scanf("%d",&n);
    pint=n/2;
    ounce=n*8;
    bigspoon=n*16;
    teaspoon=n*48;
    printf("Pint:%d\n",pint);
    printf("Ounce:%d\n",ounce);
    printf("Bigspoon:%d\n",bigspoon);
    printf("Teaspoon:%d\n",teaspoon);
    return 0;
}