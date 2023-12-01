#include <stdio.h>
#include <string.h>

int convert(const char *str)
{
    int sum=0,len=strlen(str);
    for(int i=len-1,exp=1;i>=0;--i,exp*=2)
    {
        sum+=(str[i]-'0')*exp;
    }
    return sum;
}

int main()
{
    const char *pbin="01001001";
    printf("binary %s is decimal %d\n",pbin,convert(pbin));
    return 0;
}




