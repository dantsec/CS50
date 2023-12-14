#include <stdio.h>
#include <cs50.h>

void meow(void);

int main(void) {
    meow();
}

void meow(void) {
    for(int i = 0; i < 3; i++) {
            printf("meow\n");
    }
}
