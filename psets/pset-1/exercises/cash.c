#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void) {
    // INPUT
    float input = 0.0;

    do {
        input = get_float("Cash: ");
    } while(input <= 0.0);

    // VARIABLES
    int total = 0, value = 0;

    // ROUND INPUT
    value = round(input * 100);

    // MAIN SECTION
    while(value > 0) {
        if(value >= 25) {
            total += 1;
            value -= 25;
        }

        if(value < 25 && value >= 10) {
            total += 1;
            value -= 10;
        }

        if(value < 10 && value >= 5) {
            total += 1;
            value -= 5;
        }

        if(value < 5 && value >= 1) {
            total += 1;
            value -= 1;
        }
    }

    // OUTPUT
    printf("%d\n", total);

    return 0;
}
