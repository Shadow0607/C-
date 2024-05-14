#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void forwardElimination(float mat[MAX_SIZE][MAX_SIZE+1], int n) {
    int i, j, k;
    for (i = 0; i < n - 1; i++) {
        for (k = i + 1; k < n; k++) {
            float factor = mat[k][i] / mat[i][i];
            for (j = i; j <= n; j++) {
                mat[k][j] -= factor * mat[i][j];
            }
        }
    }
}

void backSubstitution(float mat[MAX_SIZE][MAX_SIZE+1], int n, float sol[MAX_SIZE]) {
    int i, j;
    for (i = n - 1; i >= 0; i--) {
        sol[i] = mat[i][n];
        for (j = i + 1; j < n; j++) {
            sol[i] -= mat[i][j] * sol[j];
        }
        sol[i] = sol[i] / mat[i][i];
    }
}

void printEquations(float mat[MAX_SIZE][MAX_SIZE+1], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%.3f X%d ", mat[i][j], j+1);
            if (j < n-1)
                printf("+ ");
        }
        printf("= %.3f\n", mat[i][n]);
    }
}

void printSolutions(float sol[MAX_SIZE], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("X[%d] = %.3f\n", i+1, sol[i]);
    }
}

int main() {
    int n, i, j;
    float mat[MAX_SIZE][MAX_SIZE+1], sol[MAX_SIZE];

    printf("Enter the number of equations: ");
    scanf("%d", &n);

    printf("Enter the coefficients and constants:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            scanf("%f", &mat[i][j]);
        }
    }

    forwardElimination(mat, n);
    printf("Equations after forward elimination:\n");
    printEquations(mat, n);

    backSubstitution(mat, n, sol);
    printf("Solutions:\n");
    printSolutions(sol, n);

    return 0;
}
