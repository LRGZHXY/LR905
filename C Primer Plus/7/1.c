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

