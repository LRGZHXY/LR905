//  #include <stdio.h>
//  #include <math.h>
//  int main()
//  {
//     int a,b,c;
//     for(int i=0;i<3;i++)
//     {
//         scanf("%d %d %d",&a,&b,&c);
//         float x1,x2,d;
//         d=b*b-4*a*c;
//         if(d>0)
//         {
//             x1=(-b-pow(d,1/2))/(2*a);
//             x2=(-b+pow(d,1/2))/(2*a);
//             printf("有两个解，x1=%f,x2=%f",x1,x2);
//         }
//         if(d==0)
//         {
//             x1=(-b)/(2*a);
//             x2=x1;
//             printf("有唯一解，x1=x2=%f",x1=x2);
//         }
//         else if(d<0)
//         {
//             printf("无解");
//         }
//     }
//     return 0;
//  }



#include <stdio.h>
int main()
{
    char ch;
    int count=0;
    while((ch=getchar())!=EOF)
    {
        count++;
    }
    printf("%d",count);
    return 0;
}



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



#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
int main()
{
    bool inword=false;
    int ch,words=0,letter=0;
    while((ch=getchar())!=EOF)
    {
        if(ispunct(ch))
        {
            continue;
        }
        if(isalpha(ch))
        {
            letter++;
        }
        if(!isspace(ch)&&!inword)
        {
            inword=true;
            words++;
        }
        if(isspace(ch)&&inword)
        {
            inword=false;
        }
    }
    double count=letter/words;
    printf("%lf",count);
    return 0;
}
