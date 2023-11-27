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
