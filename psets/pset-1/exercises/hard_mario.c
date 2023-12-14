#include <stdio.h>
#include <cs50.h>

int main(void) {
    int stair_size = 0;

    // 1 < size < 9
    do {
        stair_size = get_int("Size: ");
    } while(stair_size <= 1 || stair_size >= 9);

    for(int i = 0; i < stair_size; i++) {

        // --------------------1st Figure-----------------------

        // print spaces
        for(int spaces = 1; spaces < stair_size - i; spaces++)
            printf(" ");

        // print #
        for(int character = 0; character < i + 1; character++)
            printf("#");

        // -----------------------------------------------------

        // separating hashes
        printf("  ");

        // --------------------2nd Figure-----------------------

        // print #
        for(int character = i + 1; character > 0; character--)
            printf("#");

        // -----------------------------------------------------

        // break line
        printf("\n");
    }

    return 0;
}
