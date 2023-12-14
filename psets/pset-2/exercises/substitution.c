#include <stdio.h>
#include <cs50.h>
// exit
#include <stdlib.h>
// strlen, strcpy
#include <string.h>
// isalpha, toupper, tolower
#include <ctype.h>

void usage(void);
int duplicates(char *, int);

int main(int argc, char *argv[]) {
    int index = 0;
    char ciphertext[100], input[100], dict[26], insert;

    // LIMITING ARGUMENTS
    if(argc != 2) {
        usage();
    } else {
        // LEN == 26 && HAVE DUPLICATES && INPUT IS ALL ALFA
        if(strlen(argv[1]) != 26)
            usage();

        if(duplicates(argv[1], index))
            usage();

        for(; argv[1][index] != '\0'; index++)
            if(!isalpha(argv[1][index]))
                usage();
    }

    // SAVING INPUT
    strcpy(input, get_string("plaintext: "));
    // SAVING DICT
    strcpy(dict, argv[1]);

    // MAIN LOOP
    for(index = 0; input[index] != '\0'; index++) {
        // INPUT [A-Z]
        if( input[index] >= 65 && input[index] <= 90 )
            insert = toupper(dict[(int)input[index] - 65]);

        // INPUT [a-z]
        else if( input[index] >= 97 && input[index] <= 122 )
            insert = tolower(dict[(int)input[index] - 97]);

        else
            insert = input[index];

        ciphertext[index] = insert;
    }

    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

void usage(void) {
    printf("Usage: Usage: ./substitution key\n");
    exit(1);
}

int duplicates(char *input, int index) {
    // CHAR OCCURENCY
    int chars[256] = {0};

    for (index = 0; input[index] != '\0'; index++) {
        char c = input[index];

        // C -> LOWER FOR CASE-INSENSITIVE
        if (c >= 'A' && c <= 'Z') {
            c = c + ('a' - 'A');
        }

        // RETURN 1 IF HAVE DUPLICATE
        if (chars[(unsigned char)c] > 0) {
            return 1;
        }

        // INC ARRAY
        chars[(unsigned char)c]++;
    }

    return 0;
}
