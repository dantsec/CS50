#include <cs50.h>
#include <stdio.h>

int main(void) {
/*
    int i = get_int("i: ");
    int j = get_int("j: ");

    (i == j) ? printf("same\n") : printf("different\n");
*/

    char *s = get_string("s: ");
    char *t = get_string("t: ");

    // always "different" -> compare address
    (s == t) ? printf("same\n") : printf("different\n");

    (*s == *t) ? printf("same\n") : printf("different\n");
}
