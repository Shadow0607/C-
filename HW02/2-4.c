#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 40

int maze[MAX_SIZE][MAX_SIZE];
int path[MAX_SIZE][MAX_SIZE];
int n;

bool findPath(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= n || maze[x][y] != 0) return false;
    if (x == n-1 && y == n-1 || path[x][y] == 1) return true;
    if (maze[x][y] == 0) {
        path[x][y] = 1;

        if (findPath(x+1, y) || findPath(x, y+1) || findPath(x-1, y) || findPath(x, y-1)) return true;

        path[x][y] = 0;
    }
    return false;
}

int main() {
    printf("Enter the size of the maze (n), n < 40: ");
    scanf("%d", &n);
    printf("Enter the maze map (0 for path, 1 for wall):\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &maze[i][j]);
            path[i][j] = 0;
        }
    }

    if (findPath(1, 1)) {
        printf("Path found:\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (path[i][j] == 1) {
                    printf("# ");
                } else {
                    printf("%d ", maze[i][j]);
                }
            }
            printf("\n");
        }
    } else {
        printf("No path found!\n");
    }

    return 0;
}
