#include <stdio.h>
#include <stdlib.h> // @@ Missing #include <string.h> for strtok function

// 结点结构体
typedef struct node {
    int coefficient;  // 系数
    int exponent;     // 指数
    struct node *next;
} node;

// 创建新结点
node *createnode(int coef, int exp) {
    node *newnode = (node *)malloc(sizeof(node));
    newnode->coefficient = coef;
    newnode->exponent = exp;
    newnode->next = NULL;
    return newnode;
}

// 插入结点到链表末尾
void insertnode(node **head, int coef, int exp) {
    node *newnode = createnode(coef, exp);
    if (*head == NULL) {
        *head = newnode;
    } else {
        node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newnode;
    }
}

// 多项式相乘
node *multiplypolynomials(node *poly1, node *poly2) {
    node *result = NULL;

    for (node *p1 = poly1; p1 != NULL; p1 = p1->next) {
        for (node *p2 = poly2; p2 != NULL; p2 = p2->next) {
            int coef = p1->coefficient * p2->coefficient;
            int exp = p1->exponent + p2->exponent;

            node *current = result;
            node *prev = NULL;
            while (current != NULL && current->exponent > exp) {
                prev = current;
                current = current->next;
            }

            if (current != NULL && current->exponent == exp) {
                current->coefficient += coef;
            } else {
                node *newnode = createnode(coef, exp);
                if (prev == NULL) {
                    newnode->next = result;
                    result = newnode;
                } else {
                    prev->next = newnode;
                    newnode->next = current;
                }
            }
        }
    }

    return result;
}

// 输出多项式
void printpolynomial(node *poly) {
    while (poly != NULL) {
        printf("%d %d ", poly->coefficient, poly->exponent);
        poly = poly->next;
    }
    //printf("\n");
}

int main() {
    node *poly1 = NULL;
    node *poly2 = NULL;

    int coef, exp;
    char line[100];

    // 读取第一个多项式
    fgets(line, sizeof(line), stdin);
    char *token = strtok(line, " ");
    while (token != NULL) {
        coef = atoi(token);
        token = strtok(NULL, " ");
        exp = atoi(token);
        insertnode(&poly1, coef, exp);
        token = strtok(NULL, " ");
    }

    // 读取第二个多项式
    fgets(line, sizeof(line), stdin);
    token = strtok(line, " ");
    while (token != NULL) {
        coef = atoi(token);
        token = strtok(NULL, " ");
        exp = atoi(token);
        insertnode(&poly2, coef, exp);
        token = strtok(NULL, " ");
    }

    node *result = multiplypolynomials(poly1, poly2);
    printpolynomial(result);

    return 0;
}