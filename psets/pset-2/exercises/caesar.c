#include <stdio.h>
#include <cs50.h>
// atoi + exit
#include <stdlib.h>
// strcpy
#include <string.h>

void usage(void);

int main(int argc, char *argv[]) {
    int index = 0, key = 0, acc = 0;
    char ciphertext[100], input[100], insert;

    // LIMITING ARGUMENTS
    if(argc != 2) {
        usage();
    } else {
        // INPUT IS ALL NUMERIC
        for(; argv[1][index] != '\0'; index++)
            if(argv[1][index] < 48 || argv[1][index] > 57)
                usage();
    }

    // INPUT
    strcpy(input, get_string("plaintext: "));

    // KEY INPUT (STR) TO INT
    key = atoi(argv[1]) % 26;

    // MAIN LOOP
    for(index = 0; input[index] != '\0'; index++) {
        // VERIFY IF INPUT[INDEX] ARE IN [a-z] || [A - Z]
        if( ( input[index] >= 65 && input[index] <= 90 ) || ( input[index] >= 97 && input[index] <= 122 ) ) {
            // COUNT TO VERIFY ACC
            if( ( ( input[index] >= 65 && input[index] <= 90 ) && (int)input[index] + key >= 90 ) || ( ( input[index] >= 97 && input[index] <= 122 ) && (int)input[index] + key >= 122 ) ) {
                acc = key - 26;
            } else {
                acc = key;
            }

            // VARIABLE TO INSERT INTO CIPHER TEXT
            insert = ((int)input[index] + acc);
        } else {
            insert = input[index];
        }

        // INSERTING TO CIPHER TEXT
        sprintf( &ciphertext[index], "%c", insert );
    }

    // OUTPUT
    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

void usage(void) {
    printf("Usage: Usage: ./caesar key\n");
    exit(1);
}
