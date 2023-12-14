#include <stdio.h>

void swap(int*, int*);

int main(void) {
    int x = 1;
    int y = 2;

    printf("x: %d, y: %d\n", x, y);
    swap(&x, &y);
    printf("x: %d, y: %d\n", x, y);
}

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
