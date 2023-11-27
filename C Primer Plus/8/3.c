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