#include <stdio.h>
void one_three(void)
{
    printf("one\n");
    two();
    printf("three\n");
}
void two()
{
    printf("two\n");
}
int main()
{
    printf("starting now:\n");
    one_three();
    printf("done!");
    return 0;
}