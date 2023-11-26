#include <stdio.h>
int main()
{
    float n;
    printf("Enter a floating-point value: ");
    scanf("%f",&n);
    printf("fixed-point notation:%f\n",n);
    printf("exponential notation:%e\n",n);
    printf("p notation:%a",n);
    return 0;
}



#include <stdio.h>
#define MASS_PER_MOLE 3.0e-23
#define MASS_PER_QUART 950

int main(void)
{
    double quart;

    printf("Please enter a quart for water: ");
    scanf("%lf", &quart);
    printf("%g quart water have %e water molecules.\n", quart, quart * MASS_PER_QUART / MASS_PER_MOLE);

    return 0;
}



#include <stdio.h>
int main()
{
    int n,pint,ounce,bigspoon,teaspoon;
    printf("Please you enter a number of cups: ");
    scanf("%d",&n);
    pint=n/2;
    ounce=n*8;
    bigspoon=n*16;
    teaspoon=n*48;
    printf("Pint:%d\n",pint);
    printf("Ounce:%d\n",ounce);
    printf("Bigspoon:%d\n",bigspoon);
    printf("Teaspoon:%d\n",teaspoon);
    return 0;
}


