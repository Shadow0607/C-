#include <stdio.h>
#include <stdlib.h>
#define MAX_INPUTS 100 
// Function to generate Gray code
char* generateGrayCode(int n, int k) {
    // Base case for recursion
    if (n == 1) {
        char *grayCode = (char *)malloc(2 * sizeof(char));
        grayCode[0] = k + '0'; // Convert 0 or 1 to character '0' or '1'
        grayCode[1] = '\0';
        return grayCode;
    }
    
    if (k < (1 << (n - 1))) {
        char *previousGrayCode = generateGrayCode(n - 1, k);
        char *grayCode = (char *)malloc((n + 1) * sizeof(char));
        grayCode[0] = '0';
        for (int i = 0; i < n; i++) {
            grayCode[i + 1] = previousGrayCode[i];
        }
        free(previousGrayCode);
        return grayCode;
    } else {
        char *previousGrayCode = generateGrayCode(n - 1, (1 << n) - 1 - k);
        char *grayCode = (char *)malloc((n + 1) * sizeof(char));
        grayCode[0] = '1';
        for (int i = 0; i < n; i++) {
            grayCode[i + 1] = previousGrayCode[i];
        }
        free(previousGrayCode);
        return grayCode;
    }
}

int main() {
    int nkPairs[MAX_INPUTS][2];
    int count = 0;
    char input[50];
    
    while (1) {
        fgets(input, 50, stdin); // Read the input line
        if (input[0] == '-') break; // Exit loop if input is -1

        if (sscanf(input, "%d %d", &nkPairs[count][0], &nkPairs[count][1]) == 2) {
            count++;
        }
    }

    for (int i = 0; i < count; i++) {
        char *grayCode = generateGrayCode(nkPairs[i][0], nkPairs[i][1]);
        printf("%s\n", grayCode);
        free(grayCode);
    }
    
    return 0;
}