#include <stdio.h>
#include <cs50.h>

int main(void) {
    // Get number 1
    int x = get_int("x: ");

    // Get number 2
    int y = get_int("y: ");

    // Divide Number 1 by Number 2
    float z = (float) x / (float) y;

    printf("%f\n", z);
}
