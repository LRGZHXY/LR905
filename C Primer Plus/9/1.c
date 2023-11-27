#include <stdio.h>
#define G 'L'
void Print(int ch,int cols,int rows)
{
    int a,b;
    for(a=1;a<=rows;a++)
    {
        for(b=1;b<=cols;b++)
        {
            putchar(ch);
        }
        putchar('\n');
    }
    return 0;
}
int main()
{
    int i,j;
    while(scanf("%d %d",&j,&i)==2)
    {
        Print(G,j,i);
    }
    return 0;
}