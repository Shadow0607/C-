#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* data = NULL;
int size = 0;

void addData(int byte) {
    char* temp = realloc(data, size + 1);
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    data = temp;
    data[size++] = byte;
}

void clearData() {
    free(data);
    data = NULL;
    size = 0;
}

void readBinaryFile(char* filename){ 
    clearData();
}

void printData() {
    printf("size=%dbytes\n", size);
    for (int i = 0; i < size; i++) {
        for (int bit = 7; bit >= 0; bit--) {
            printf("%d ", (data[i] >> bit) & 1);
        }
        printf("\n");
    }
}

void modifyBit(int n, int value) {
    int byteIndex = n / 8;
    int bitIndex = 7 - n % 8;
    if (value == 1) {
        data[byteIndex] |= (1 << bitIndex);
    } else {
        data[byteIndex] &= ~(1 << bitIndex);
    }
}

int main() {
    int choice;
    do {
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                int byte;
                while (scanf("%d", &byte) && byte != -1) {
                    addData(byte);
                }
                printData();
                break;
            }
            case 2: {
                char filename[100];
                scanf("%s", filename);
                readBinaryFile(filename);
                break;
            }
            case 3:
                printData();
                break;
            case 4: {
                int n, value;
                scanf("%d %d", &n, &value);
                modifyBit(n, value);
                printData();
                break;
            }
            case 5:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);
    
    free(data);
    return 0;
}
