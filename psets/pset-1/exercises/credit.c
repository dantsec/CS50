#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void) {
    // VARIABLES
    long card = 0;
    char manipulated_card[256];
    int right_count = 0, left_count = 0, result = 0, aux = 0, digits_len = 0;

    // INPUT
    do {
        card = get_long("Card Number: ");
    } while(card <= 0);

    // LONG TO STRING
    snprintf(manipulated_card, sizeof(manipulated_card), "%lu", card);

    // SIZE OF 'manipulated_card'
    digits_len = strlen(manipulated_card);

    // MAIN LOOP
    for(int delimiter = digits_len; delimiter > 0; delimiter -= 2) {
        // NO MULTIPLIED BY 2
        left_count += manipulated_card[delimiter - 1] - 48;

        if(delimiter - 2 < 0)
            continue;

        // MULTIPLIED BY 2
        aux = (manipulated_card[delimiter - 2] - 48) * 2;
        if(aux >= 10) {
            right_count += 1;
            right_count += (aux - 10);
        } else {
            right_count += aux;
        }
    }

    // STORE RESULT
    result = left_count + right_count;

    // VALIDATING RESULT [MOD(10) && VALID_NUMBERS && CARD_LEN]
    if(result % 10 == 0 && manipulated_card[0] - 48 == 3 && manipulated_card[1] - 48 == 4  || manipulated_card[1] - 48 == 7 && digits_len == 15)
        printf("AMEX\n");
    else if(result % 10 == 0 && manipulated_card[0] - 48 == 4 && digits_len >= 13 && digits_len <= 16)
        printf("VISA\n");
    else if(result % 10 == 0 && manipulated_card[0] - 48 == 5 && manipulated_card[1] - 48 >= 1 && manipulated_card[1] - 48 <= 5 && digits_len == 16)
        printf("MASTERCARD\n");
    else
        printf("INVALID\n");

    return 0;
}
