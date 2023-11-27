#include <stdio.h>
#include <ctype.h>
int main()
{
    int ch;
    unsigned int da=0;
    unsigned int xiao=0;
    unsigned int others=0;
    while((ch=getchar())!=EOF)
    {
        (isupper(ch)?++da:islower(ch)?++xiao:++others);
    }
    printf("Upper:%u\n",da);
    printf("Lower:%u\n",xiao);
    printf("Others:%u\n",others);
    return 0;
}

