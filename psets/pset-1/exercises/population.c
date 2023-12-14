#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void) {
    /*
        n / 3 born
        n / 4 die
    */

    int start = 0, end = 0, years = 0, born = 0, died = 0;

    // GET INITIAL VALUE
    do {
        start = get_int("Start size: ");
    } while(start < 9);

    // GET FINAL VALUE
    do {
        end = get_int("End size: ");
    } while(end < 9 || end < start);

    // MAIN LOOP
    while(start < end) {
        born = round(start / 3);
        died = round(start / 4);
        start = start + born - died;
        years++;
    }

    // OUTPUT
    printf("Years: %d\n", years);

    return 0;
}
