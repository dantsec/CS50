#include <stdio.h>
#include <cs50.c>

int main(void) {
    float x = get_float("x: ");
    float y = get_float("y: ");

    printf("%.10f\n", x / y);
}
