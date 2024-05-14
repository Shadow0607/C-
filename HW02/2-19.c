#include <stdio.h>

#define PI 4

typedef struct {
    char type; // C: Circle, R: Rectangle, S: Square, T: Triangle
    int data[3]; // 存储半径、边长或宽高
} Shape;

int perimeter(Shape shape) {
    int p = 0;
    switch(shape.type) {
        case 'C': // Circle
            p = 2 * PI * shape.data[0];
            break;
        case 'R': // Rectangle
            p = 2 * (shape.data[0] + shape.data[1]);
            break;
        case 'S': // Square
            p = 4 * shape.data[0];
            break;
        case 'T': // Triangle
            p = shape.data[0] + shape.data[1] + shape.data[2];
            break;
    }
    return p;
}

int main() {
    int N, totalPerimeter = 0;
    scanf("%d", &N);

    Shape shapes[N];

    for(int i = 0; i < N; i++) {
        scanf(" %c", &shapes[i].type);
        if(shapes[i].type == 'C' || shapes[i].type == 'S') {
            scanf("%d", &shapes[i].data[0]);
        } else if(shapes[i].type == 'R') {
            scanf("%d %d", &shapes[i].data[0], &shapes[i].data[1]);
        } else if(shapes[i].type == 'T') {
            scanf("%d %d %d", &shapes[i].data[0], &shapes[i].data[1], &shapes[i].data[2]);
        }
    }

    for(int i = 0; i < N; i++) {
        int p = perimeter(shapes[i]);
        printf("%d\n", p);
        totalPerimeter += p;
    }
    
    printf("%d\n", totalPerimeter);

    return 0;
}
