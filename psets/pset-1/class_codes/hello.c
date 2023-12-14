#include <stdio.h>
#include <cs50.h>

// clang hello.c -lcs50 -o hello

/*
    input (arguments) -> proccessment (function) -> output (side effects) /+ return values, variables
*/

int main(void) {
    // P 0X01
    // print text on screen
    // printf("Hello, World!\n");

    // P 0X02
    string answer = get_string("What's your name? ");
    // say ( join ( "hello, ", answer ) )
    printf("Hello, %s!\n", answer);
}
