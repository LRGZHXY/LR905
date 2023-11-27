#include <stdio.h>
#include <ctype.h>
#define len 10
char *getword(char *str)
{
    int ch;
    int n = 0;
    char *s = str;
    while ((ch = getchar()) != EOF && isspace(ch))
        continue;
    if (ch == EOF)
    {
        return NULL;
    }
    else
    {
        n++;
        *str++ = ch;
    }
    while ((ch = getchar()) != EOF && !isspace(ch) && (n < len - 1))
    {
        *str++ = ch;
        n++;
    }
    *str = '\0';
    if (ch == EOF)
    {
        return NULL;
    }
    else
    {
        while (getchar() != '\n')
            continue;
        return s;
    }
}
int main(int argc, char *argv[])
{
    char input[len];
    while (getword(input) != NULL)
    {
        puts(input);
    }
    return 0;
}