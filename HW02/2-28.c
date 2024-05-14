#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s {
    int data;
    struct node_s *next;
} node_t;

typedef struct Queue {
    char name[50];
    node_t *front, *rear;
    struct Queue *nextQueue;
} Queue;

Queue *headQueue = NULL; // 全局变量，用于存储队列链表的头部

Queue* CreateQueue(char* name) {
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    if (!newQueue) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    strcpy(newQueue->name, name);
    newQueue->front = NULL;
    newQueue->rear = NULL;
    newQueue->nextQueue = NULL;
    
    // 添加队列到队列链表
    if (headQueue == NULL) {
        headQueue = newQueue;
    } else {
        Queue* temp = headQueue;
        while (temp->nextQueue != NULL) {
            temp = temp->nextQueue;
        }
        temp->nextQueue = newQueue;
    }
    
    return newQueue;
}

// 用于检查队列是否存在并返回队列的指针
Queue* findQueue(char* name) {
    Queue* temp = headQueue;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            return temp;
        }
        temp = temp->nextQueue;
    }
    return NULL;
}

// 用于插入数据到队列
void EnQueue(char* name, int data) {
    Queue* queue = findQueue(name);
    if (queue == NULL) {
        printf("Queue %s isn't exist\n", name);
        return;
    }
    
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

void DeQueue(char* name) {
    Queue* queue = findQueue(name);
    if (queue == NULL) {
        printf("Queue %s isn't exist\n", name);
        return;
    }
    
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    
    node_t* tempNode = queue->front;
    queue->front = queue->front->next;
    
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    
    free(tempNode);
}

void MergeQueue(char* nameA, char* nameB) {
    Queue* queueA = findQueue(nameA);
    Queue* queueB = findQueue(nameB);
    
    if (queueA == NULL || queueB == NULL) {
        printf("Queue %s isn't exist\n", queueA == NULL ? nameA : nameB);
        return;
    }
    
    if (queueA->rear != NULL) {
        queueA->rear->next = queueB->front;
    } else {
        queueA->front = queueB->front;
    }
    
    if (queueB->rear != NULL) {
        queueA->rear = queueB->rear;
    }
    
    // 删除队列B
    if (headQueue == queueB) {
        headQueue = queueB->nextQueue;
    } else {
        Queue* temp = headQueue;
        while (temp != NULL && temp->nextQueue != queueB) {
            temp = temp->nextQueue;
        }
        if (temp != NULL) {
            temp->nextQueue = queueB->nextQueue;
        }
    }
    free(queueB);
}

void PrintAllQueue() {
    if (headQueue == NULL) {
        printf("Isn't have any queue\n");
        return;
    }
    
    Queue* tempQueue = headQueue;
    while (tempQueue != NULL) {
        printf("****************************************\n");
        printf("Queue Name:%s ", tempQueue->name);
        
        int count = 0;
        node_t* tempNode = tempQueue->front;
        while (tempNode != NULL) {
            count++;
            tempNode = tempNode->next;
        }
        
        printf("Queue Size:%d Queue Element:", count);
        if (count == 0) {
            printf("Queue is empty\n");
        } else {
            tempNode = tempQueue->front;
            while (tempNode != NULL) {
                printf("%d ", tempNode->data);
                tempNode = tempNode->next;
            }
            printf("\n");
        }
        printf("****************************************\n");
        
        tempQueue = tempQueue->nextQueue;
    }
}

int main() {
    char command;
    char nameA[50], nameB[50];
    int data;

    while (scanf(" %c", &command) && command != '6') {
        switch (command) {
            case '1':
                scanf("%s", nameA);
                CreateQueue(nameA);
                break;
            case '2':
                scanf("%s %d", nameA, &data);
                EnQueue(nameA, data);
                break;
            case '3':
                scanf("%s", nameA);
                DeQueue(nameA);
                break;
            case '4':
                scanf("%s %s", nameA, nameB);
                MergeQueue(nameA, nameB);
                break;
            case '5':
                PrintAllQueue();
                break;
            default:
                printf("Invalid command\n");
        }
    }

    return 0;
}

