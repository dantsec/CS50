#include <stdio.h>
#include <stdbool.h>

typedef struct node {
    int number;
    struct node *left;
    struct node *right;
} node;

bool search(node *tree, int number) {
    if(tree == NULL)
        return false;
    else if(number < tree->number)
        return search(tree->left, number);
    else if(number > tree->number)
        return search(tree->right, number)
    // else if (number == tree->number)
    // return true;
    else
        return true;
}

int main(void) {

}
