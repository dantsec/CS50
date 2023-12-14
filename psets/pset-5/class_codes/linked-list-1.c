#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(void) {
    // first var -> point to begin
    node *list = NULL;

    // * because always return addr
    node *n = malloc(sizeof(node));

    // n 1
    if(n != NULL) {
        n->number = 1;
        // (*a).b == a->b
        (*n).next = NULL;
    }

    // n -> temp, now link list to n
    list = n;

    // n 2
    n = malloc(sizeof(node));

    if(n != NULL) {
        n->number = 2;
        n->next = NULL;
    }

    // list -> 1 -> 2
    list->next = n;

    // n 3
    n = malloc(sizeof(node));

    if(n != NULL) {
        n->number = 3;
        n->next = NULL;
    }

    // list -> 1 -> 2 -> 3
    list->next->next = n;

    return 0;
}
