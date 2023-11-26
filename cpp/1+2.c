#include <stdio.h>
int main()
{
    double n,s;
    scanf("%lf",&n);
    s=n*2.54;
    printf("%lf",s);
    return 0;
}



#include <stdio.h>

int main(void)
{
    int age = 18, days_per_year = 365;
    int days = age * days_per_year;
    
    printf("I am %d years old.\n", age);
    printf("Days are %d.\n", days);

    return 0;
}



// #include <stdio.h>
// #include <math.h>
// int main()
// {
//     float a,b,c,p,s;
//     scanf("%f %f %f",&a,&b,&c);
//     if(a+b>c&&b+c>a&&a+c>b)
//     {
//         p=(a+b+c)/2;
//         s=sqrt(p*(p-a)*(p-b)*(p-c));
//         printf("三角形面积s=%.2f",s);
//     }
//     else
//     {
//         printf("三角形不存在");
//     }
//     return 0;
// }



// #include <stdio.h>
// #define a 3.14
// int main()
// {
//     float r,s,v,b=1.25;
//     scanf("%f",&r);
//     s=a*r*r;
//     v=b*a*r*r*r;
//     printf("s=%f,v=%f",s,v);
//     return 0;
// }


 
 #include <stdio.h>
 void jolly(void)
 {
    printf("For he's a jolly good fellow!\n");
 }
 void deny(void)
 {
    printf("Which nobody can deny!\n");
 }
 int main()
 {
    jolly();
    jolly();
    jolly();
    deny();
    return 0;
 }



#include <stdio.h>
void one_three(void)
{
    printf("one\n");
    two();
    printf("three\n");
}
void two()
{
    printf("two\n");
}
int main()
{
    printf("starting now:\n");
    one_three();
    printf("done!");
    return 0;
}