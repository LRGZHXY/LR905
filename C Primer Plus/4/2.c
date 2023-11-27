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
