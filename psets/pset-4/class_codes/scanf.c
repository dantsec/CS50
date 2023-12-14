#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int x;
    char *s = malloc(4);

    printf("x: ");
    scanf("%d", &x);

    printf("s: ");
    scanf("%s", s);

    printf("x: %d\n", x);
    printf("s: %s\n", s);
}
