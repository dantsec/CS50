#include <stdio.h>
#include <cs50.h>

int main(void) {
/*
    //7f fc 7c 11 4d 2c

    int n = 50;
    int *p = &n;

    printf("%p\n", p);
    printf("%i\n", *p);
*/

    char* s = "HI!";

    printf("%s\n\n", s);

    printf("%c\n", *s);
    // actual address + sizeof(type) * index
    printf("%c\n", *(s + 0x01 * 0x01));
    printf("%c\n", *(s + 2));
}
