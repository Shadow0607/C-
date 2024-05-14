#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

void initializeStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(Stack *s, int data) {
    if (isFull(s)) {
        printf("The Stack is full\n");
    } else {
        s->items[++s->top] = data;
    }
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("The Stack is empty\n");
        return -1;
    } else {
        return s->items[s->top--];
    }
}

int main() {
    Stack s;
    initializeStack(&s);
    
    int command, data;
    while (1) {
        scanf("%d", &command);
        switch (command) {
            case 1:
                scanf("%d", &data);
                push(&s, data);
                break;
            case 2:
                data = pop(&s);
                if (data != -1) {
                    printf("The data %d is pop\n", data);
                }
                break;
            case 3:
                return 0;
            default:
                printf("Invalid command\n");
        }
    }
    return 0;
}
