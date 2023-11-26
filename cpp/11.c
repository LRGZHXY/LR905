#include <stdio.h>
#include <ctype.h>
#define len 10
void getnchar(char str[], int n)
{
    int i = 0;
    while (i < n - 1)
    {
        str[i] = getchar();
        if (isspace(str[i]))
        {
            break;
        }
        ++i;
    }
    str[i] = '\0';
}
int main(int argc, char *argv[])
{
    char str[len];
    getnchar(str, len);
    puts(str);
    return 0;
}





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



#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int exp;
    double num, sum = 1.0;
    if (argc != 3)
    {
        printf("Usage: %s floating-point exp\n", argv[0]);
    }
    else
    {
        num = atof(argv[1]), exp = atoi(argv[2]);
        for (int i = 1; i <= exp; i++)
        {
            sum *= num;
        }
        printf("%g ^ %d is %g.\n", num, exp, sum);
    }
    return 0;
}


