#include <stdio.h>
#include <stdlib.h>

int feedbackLoopCount(int m) {
    int count = 0;
    while (m > 1) {
        if (m % 2 == 0) {
            m /= 2;
        } else {
            m = (m + 1) / 2;
        }
        count++;
    }
    return count;
}

void printBinary4bit(int num) {
    for (int i = 3; i >= 0; --i) {
        putchar((num & (1 << i)) ? '1' : '0');
    }
    putchar('\n');
}

int main() {
    char input[9]; // Buffer for the binary input as a strin
    int results[128]; // Array to store the results
    int resultIndex = 0; // Index for storing results

    while (1) {
        scanf("%s", input); // Read the binary input or control signal
        if (input[0] == '0') {
            // It's a delimiter, do nothing and wait for the next input
        } else if (input[0] == '-') {
            // When '-1' is encountered, print all results and exit
            for (int i = 0; i <= resultIndex; i++) {
                printBinary4bit(results[i]);
            }
            break;
        } else {
            // Convert binary string to integer and calculate feedback loop count
            int n = strtol(input, NULL, 2);
            // Store the count
            results[resultIndex++] = feedbackLoopCount(n);
        }
    }

    return 0;
}
