#include <stdio.h>
#include <cs50.h>
// round
#include <math.h>
// strcpy
#include <string.h>

int main(void) {
    // INPUT
    char text[1000];
    int counter = 0, grade = 0, count_letters = 0, count_sentences = 0, count_words = 1;

    strcpy(text, get_string("Text: "));

    // MAIN LOOP
    while(text[counter] != '\0') {

        // A - Z || a - z
        if( ( text[counter] >= 65 && text[counter] <= 90 ) || ( text[counter] >= 97 && text[counter] <= 122 ) )
            count_letters++;

        // . || ! || ?
        if( text[counter] == 33 || text[counter] == 46 || text[counter] == 63 )
            count_sentences++;

        // " "
        if ( text[counter] == 32)
            count_words++;

        counter++;
    }

    // CALC AND VALIDATION
    grade = round( 0.0588 * ( 100.0 * (float)count_letters / (float)count_words ) - 0.296 * ( 100.0 * (float)count_sentences / (float)count_words ) - 15.8 );

    if(grade < 1)
        printf("Before Grade 1\n");
    else if(grade >= 16)
        printf("Grade 16+\n");
    else
        printf("Grade %d\n", grade);

    return 0;
}
