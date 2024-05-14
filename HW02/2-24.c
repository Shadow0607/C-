#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode {
    int coeff;
    int exp;
    struct PolyNode *next;
} PolyNode;

PolyNode* createNode(int coeff, int exp) {
    PolyNode* newNode = (PolyNode*)malloc(sizeof(PolyNode));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void addNode(PolyNode** poly, int coeff, int exp) {
    PolyNode* newNode = createNode(coeff, exp);
    if (*poly == NULL) {
        *poly = newNode;
    } else {
        PolyNode* temp = *poly;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

PolyNode* addPolynomials(PolyNode* poly1, PolyNode* poly2) {
    PolyNode* result = NULL;
    while (poly1 != NULL || poly2 != NULL) {
        if (poly2 == NULL || (poly1 != NULL && poly1->exp > poly2->exp)) {
            addNode(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else if (poly1 == NULL || (poly2 != NULL && poly1->exp < poly2->exp)) {
            addNode(&result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } else {
            int sum = poly1->coeff + poly2->coeff;
            if (sum != 0) {
                addNode(&result, sum, poly1->exp);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    return result;
}

void printPolynomial(PolyNode* poly) {
    while (poly != NULL) {
        printf("%d ", poly->coeff);
        poly = poly->next;
    }
    printf("\n");
}

int main() {
    PolyNode *poly1 = NULL, *poly2 = NULL;
    int n1, n2, coeff;

    // 读取第一个多项式的系数
    scanf("%d", &n1);
    for (int i = n1 - 1; i >= 0; i--) {
        scanf("%d", &coeff);
        addNode(&poly1, coeff, i);
    }

    // 读取第二个多项式的系数
    scanf("%d", &n2);
    for (int i = n2 - 1; i >= 0; i--) {
        scanf("%d", &coeff);
        addNode(&poly2, coeff, i);
    }

    // 相加两个多项式
    PolyNode* result = addPolynomials(poly1, poly2);

    // 打印结果多项式的系数
    printPolynomial(result);

    return 0;
}


