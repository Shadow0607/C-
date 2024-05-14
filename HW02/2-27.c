#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
    int data;
    struct node_s *left;
    struct node_s *right;
} node_t;

typedef node_t* nodep_t;

void Insert(nodep_t *node, int key) {
    if (*node == NULL) {
        *node = (nodep_t)malloc(sizeof(node_t));
        if (*node == NULL) {
            printf("Memory allocation error\n");
            return;
        }
        (*node)->data = key;
        (*node)->left = (*node)->right = NULL;
    } else if (key <= (*node)->data) {
        Insert(&((*node)->left), key);
    } else {
        Insert(&((*node)->right), key);
    }
}

void Inorder(nodep_t *node) {
    if (*node != NULL) {
        Inorder(&((*node)->left));
        printf("%d ", (*node)->data);
        Inorder(&((*node)->right));
    }
}

int main() {
    char command;
    int key;
    nodep_t root = NULL;

    while (scanf(" %c", &command) && command != 'e') {
        if (command == 'p') {
            if (root == NULL) {
                printf("null\n");
            } else {
                Inorder(&root);
                printf("\n");
            }
        } else if (command == 'i') {
            scanf("%d", &key);
            Insert(&root, key);
        }
    }

    return 0;
}
