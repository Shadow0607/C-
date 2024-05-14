#include <stdio.h>

void compareNumbers(const char* answer, const char* guess, int* a, int* b) {
    *a = 0; 
    *b = 0; 

    for (int i = 0; i < 4; ++i) {
        if (guess[i] == answer[i]) {
            (*a)++;
        } else {
            for (int j = 0; j < 4; ++j) {
                if (guess[i] == answer[j]) {
                    (*b)++;
                    break;
                }
            }
        }
    }
}

int main() {
    char answer[5]; 
    printf("Set the answer (4 unique digits): ");
    scanf("%4s", answer); 

    while (getchar() != '\n'); 

    char guess[5];
    int a, b; 
    while (1) {
        printf("Enter your guess (4 digits): ");
        scanf("%4s", guess);

        compareNumbers(answer, guess, &a, &b);

        printf("Guess: %s, Hint: %dA%dB\n", guess, a, b);

        if (a == 4) { 
            printf("Correct! The answer is %s.\n", answer);
            break;
        }

        while (getchar() != '\n'); 
    }

    return 0;
}
