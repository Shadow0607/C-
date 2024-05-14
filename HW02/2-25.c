#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id; // 学号
    int score; // 分数
} student_t;

typedef struct node {
    student_t data;
    struct node *next;
} node_t;

typedef node_t * nodep_t;

void printList(nodep_t p) {
    if (!p) {
        printf("null\n");
    } else {
        while (p != NULL) {
            printf("%d,%d", p->data.id, p->data.score);
            if (p->next != NULL) {
                printf(",");
            }
            p = p->next;
        }
        printf("\n");
    }
}

void insertInOrder(nodep_t *p, student_t data) {
    nodep_t newNode = malloc(sizeof(node_t));
    newNode->data = data;
    newNode->next = NULL;

    // 如果链表为空或新节点的分数小于头节点的分数
    if (!*p || newNode->data.score < (*p)->data.score) {
        newNode->next = *p;
        *p = newNode;
    } else {
        nodep_t temp = *p;
        while (temp->next != NULL && temp->next->data.score <= newNode->data.score) {
            // 如果分数相同，则根据学号排序
            if (temp->next->data.score == newNode->data.score && temp->next->data.id > newNode->data.id) {
                break;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

int main() {
    char cmd;
    nodep_t head = NULL;

    while (scanf(" %c", &cmd) && cmd != 'e') {
        if (cmd == 'p') {
            printList(head);
        } else if (cmd == 'i') {
            student_t data;
            scanf("%d,%d", &data.id, &data.score);
            insertInOrder(&head, data);
        }
    }

    // Free the allocated memory
    nodep_t temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
