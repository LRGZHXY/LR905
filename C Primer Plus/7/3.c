#include <stdio.h>
int main()
{
    int ch;
    int n=0;
    while((ch=getchar())!='#')
    {
        if(ch=='.')
        {
            putchar('!');
            n++;
        }
        else if(ch=='!')
        {
            printf("!!");
            n++;
        }
        else
        {
            putchar(ch);
        }
    }
    printf("\nTotal replace %d times.\n", n);
    return 0;
}

