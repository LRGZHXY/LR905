#include <stdio.h>
#include <stdlib.h>
#define len 100
int main()
{
    int ch;
    FILE*fp;
    unsigned long count=0;
    char filename[len];
    printf("Please enter a filename: ");
    scanf("%99s",filename);
    if((fp=fopen(filename,"r"))==NULL)
    {
        printf("Can't open %s\n",filename);
        exit(EXIT_FAILURE);
    }
    while((ch=getc(fp))!=EOF)
    {
        putc(ch,stdout);
        count++;
    }
    fclose(fp);
    printf("File %s has %lu characters\n",filename,count);
    return 0;
}




    