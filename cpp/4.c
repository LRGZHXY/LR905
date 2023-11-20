#include <stdio.h>
#include <string.h>
int main()
{
    char name[20];
    printf("Please enter your name: ");
    scanf("%19s",name);
    printf("a.\"%s\"\n",name);
    printf("b.\"%20s\"\n",name);
    printf("c.\"%-20s\"\n",name);
    printf("d.%*s",strlen(name)+3,name);
    return 0;
}


#include <stdio.h>
#include <string.h>
int main()
{
    char fname[20];
    char lname[20];
    int x,y;
    printf("please enter your first name: ");
    scanf("%19s",fname);
    printf("please enter your last name: ");
    scanf("%19s",lname);
    x=strlen(fname);
    y=strlen(lname);
    printf("%s %s\n",fname,lname);
    printf("%*d %*d\n",x,x,y,y);
    printf("%s %s\n",fname,lname);
    printf("%-*d %-*d\n",x,x,y,y);
    return 0;
}


#include <stdio.h>
#define GALLON_TO_LITRE 3.785
#define MILE_TO_KM 1.609
int main()
{
    double range,oil;
    printf("Please input the range you traveled(in mile): ");
    scanf("%lf",&range);
    printf("Please input the oil you spend(in gallon): ");
    scanf("%lf",&oil);
    printf("%.1lf\n",range/oil);
    printf("%.1lf",100.0*(oil*GALLON_TO_LITRE)/(range*MILE_TO_KM));
    return 0;
}



