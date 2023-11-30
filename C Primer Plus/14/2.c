#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#define NUM 4
int showmenu(void)
{
    int ch;
    puts("+-----------------------+");
    puts("|a)double         b)half|");
    puts("|c)square         d)sqrt|");
    puts("|q)quit                 |");
    puts("+-----------------------+");
    printf("Please you choose: ");
    while(ch=get_first(),NULL==strchr("abcdq",ch))
    {
        printf("Please enter a,b,c,d or q: ");
    }
    return ch;
}
double twice(double x)
{
    return 2.0*x;
}
double half(double x)
{
    return x/2.0;
}
double square(double x)
{
    return x*x;
}
void eatline(void)
{
    while(getchar()!='\n')
    {
        continue;
    }
    return 0;
}
int get_first(void)
{
    int ch;
    do
    {
        ch=tolower(getchar());
    } while (isspace(ch));
    eatline();
    return ch;  
}
void show(int i,double x,double (*pf[NUM])(double))
{
    x=(*pf[i])(x);
    printf("After operating: %g\n\n",x);
}
int main()
{
    int choice;
    double number;
    double(*pf[NUM])(double)={twice,half,square,sqrt};
    while((choice=showmenu())!='q')
    {
        printf("Please enter a number: ");
        while(scanf("%lf",&number)!=1)
        {
            eatline();
            printf("Please enter again: ");
        }
        switch(choice)
        {
         case 'a':
         {
            show(0,number,pf);
            break;
         }  
         case 'b':
         {
            show(1,number,pf);
            break;
         }
         case 'c':
         {
            show(3,number,pf);
         }
         case 'd':
         {
            show(4,number,pf);
         }
        }
    }
    printf("Done.\n");
    return 0;
}








 

 


