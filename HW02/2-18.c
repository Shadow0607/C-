#include <stdio.h>
#include <stdlib.h>

#define GATEVALUE(TYPE) int(*GateValue)(int, int)
typedef struct _Gate{
    GATEVALUE();
} Gate;

int NotGateValue(int x, int unused) {
    return !x;
}

int AndGateValue(int x, int y) {
    return x && y;
}

int OrGateValue(int x, int y) {
    return x || y;
}

int EmptyGateValue(int x, int unused) {
    return x;
}

void CreateGate(Gate *obj, char gateType) {
    switch (gateType) {
        case 'N':
            obj->GateValue = NotGateValue;
            break;
        case 'A':
            obj->GateValue = AndGateValue;
            break;
        case 'O':
            obj->GateValue = OrGateValue;
            break;
        case 'E':
            obj->GateValue = EmptyGateValue;
            break;
        default:
            printf("Unknown gate type\n");
    }
}

int main(int argc, char *argv[]) {
    int X1, X2, X3;
    char P, Q, R;
    scanf("%d,%d,%d", &X1, &X2, &X3);
    scanf(" %c,%c,%c", &P, &Q, &R);

    Gate pGate, qGate, rGate;
    CreateGate(&pGate, P);
    CreateGate(&qGate, Q);
    CreateGate(&rGate, R);

    // Computing gate outputs
    int Y1 = pGate.GateValue(X1, 0);
    int PQ = qGate.GateValue(X2, Y1);
    int Y2 = PQ;
    int Y3 = rGate.GateValue(X3, PQ);

    printf("%d,%d,%d\n", Y1, Y2, Y3);

    return 0;
}
