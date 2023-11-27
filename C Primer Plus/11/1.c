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

