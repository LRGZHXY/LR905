#include <stdio.h>
int main()
{
    int ch,kong,huan,others;
    kong=huan=others=0;
    while((ch=getchar())!='#')
    {
        (ch==' '?++kong:(ch=='\n'?++huan:++others));
    }
    printf("kong:%d\n",kong);
    printf("huan:%d\n",huan);
    printf("others:%d\n",others);
    return 0;
}



#include <stdio.h>
int main()
{
    int n,j=0,o=0;
    double sj=0,so=0;
    while(scanf("%d",&n)==1&&n)
    {
        (n%2?(++j,sj+=n):(++o,so+=n));
    }
    if(j>0)
    {
        printf("%lf\n",(float)sj/j);
    }
    if(o>0)
    {
        printf("%lf\n",(float)so/o);
    }
    return 0;
}



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




