// #include <stdio.h>
// void func(void) {
//     short a = -2;
//     unsigned int b = 1;
//     b += a;
//     int c = -1;
//     unsigned short d = c * 256;
//     c <<= 4;
//     int e = 2;
//     e = ~e | 6;
//     d = (d & 0xff) + 0x2022;
//     printf("a=0x%hx\tb=0x%x\td=0x%hx\te=0x%x\n", a, b, d, e);
//     printf("c=Ox%hhx\t\n", (signed char)c);
    
// }
#include <stdio.h>
#include <string.h>
int main(int argc, char **argv) {
    int data1[2][3] = {{0x636c6557, 0x20656d6f, 0x58206f74},
                       {0x756f7969, 0x6e694c20, 0x00000000}};
    int data2[] = {0x47207875, 0x70756f72, 0x32303220, 0x00000a32};
    char *a = (char *)data1;
    char *b = (char *)data2;
    char buf[1024];
    strcpy(buf, a);
    strcat(buf, b);
    printf("%s \n", buf);
}