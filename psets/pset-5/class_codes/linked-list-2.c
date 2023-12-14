#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(void) {
    node *list = NULL;

    // NUMBER 1
    node *n = malloc(sizeof(node));

    if(n == NULL) {
        return 1;
    }

    n->number = 1;
    n->next = NULL;
    list = n;

    // NUMBER 2
    n = malloc(sizeof(node));

    if(n == NULL) {
        free(list);
        return 1;
    }

    n->number = 2;
    n->next = NULL;
    list->next = n;

    // NUMBER 3
    n = malloc(sizeof(node));

    if(n == NULL) {
        free(list->next);
        free(list);
        return 1;
    }

    n->number = 3;
    n->next = NULL;
    list->next->next = n;

    // ...

    // PRINT NUMBERS
    for(node *tmp = list; tmp != NULL; tmp = tmp->next) {
        printf("Number: %d\n", tmp->number);
    }

    // FREE POINTERS
    while(list != NULL) {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }

    return 0;
}
