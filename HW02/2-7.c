#include <stdio.h>
#include <limits.h>

#define MAX_CITIES 10

int main() {
    int N;
    printf("Enter the number of cities: ");
    scanf("%d", &N);

    int distance[MAX_CITIES][MAX_CITIES];

    printf("Enter the distances between cities:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &distance[i][j]);
        }
    }

    int min_distance[MAX_CITIES];
    for (int i = 0; i < N; i++) {
        int min_val = INT_MAX;
        for (int j = 0; j < N; j++) {
            if (i != j && distance[i][j] < min_val) {
                min_val = distance[i][j];
            }
        }
        min_distance[i] = min_val;
    }

    int total_distance = 0;
    for (int i = 0; i < N; i++) {
        if (min_distance[i] != INT_MAX) {
            total_distance += min_distance[i];
        }
    }

    printf("Minimum distance from city 1 to visit all cities: %d\n", total_distance);

    return 0;
}
