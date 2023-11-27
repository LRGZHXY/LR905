#include <stdio.h>
int main()
{
    int i=0;
    char s[255];
    while(scanf("%c",&s[i])&&i+1<255&&s[i]!='\n')
    {
        ++i;
    }
    for(i--;i>=0;i--)
    {
        printf("%c",s[i]);
    }
    printf("\nDone.\n");
    return 0;
}