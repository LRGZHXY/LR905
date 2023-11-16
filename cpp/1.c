//  #include <stdio.h>
//  int main()
//  {
//     printf("L R\n");
//     printf("L\nR\n ");
//     printf("L ");
//     printf("R");
//     return 0;
//  }

#include <stdio.h>
#include <math.h>
int main()
{
    float a,b,c,p,s;
    scanf("%f %f %f",&a,&b,&c);
    if(a+b>c&&b+c>a&&a+c>b)
    {
        p=(a+b+c)/2;
        s=sqrt(p*(p-a)*(p-b)*(p-c));
        printf("三角形面积s=%.2f",s);
    }
    else
    {
        printf("三角形不存在");
    }
    return 0;
}

 