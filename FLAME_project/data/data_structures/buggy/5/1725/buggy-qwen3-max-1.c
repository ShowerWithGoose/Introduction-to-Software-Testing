#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coef;
    int exp;
    struct Node *next;
} Node;

Node* createNode(int coef, int exp) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->coef = coef;
    node->exp = exp;
    node->next = NULL;
    return node;
}

Node* insertNode(Node *head, int coef, int exp) {
    Node *node = createNode(coef, exp);
    if (!head) {
        return node;
    }
    Node *prev = NULL, *cur = head;
    while (cur && cur->exp < exp) {
        prev = cur;
        cur = cur->next;
    }
    if (cur && cur->exp == exp) {
        cur->coef += coef;
        free(node);
    } else {
        node->next = cur;
        if (!prev) {
            head = node;
        } else {
            prev->next = node;
        }
    }
    return head;
}

Node* multiplyPolynomials(Node *poly1, Node *poly2) {
    Node *result = NULL;
    for (Node *i = poly1; i; i = i->next) {
        for (Node *j = poly2; j; j = j->next) {
            result = insertNode(result, i->coef * j->coef, i->exp + j->exp);
        }
    }
    return result;
}

void printPolynomial(Node *head) {
    for (Node *node = head; node; node = node->next) {
        printf("%d %d ", node->coef, node->exp);
    }
    printf("\n");
}

int main() {
    Node *poly1 = NULL, *poly2 = NULL;
    int coef, exp;
    char ch;
    while (scanf("%d%d%c", &coef, &exp, &ch) != EOF) {
        poly1 = insertNode(poly1, coef, exp); // @@ [The input reading logic inserts terms in ascending order of exponents due to the condition `cur->exp < exp` in insertNode, but the problem requires output in descending order. However, the real issue is that during insertion, the list is maintained in ascending order, so the final polynomial is in ascending order, leading to wrong output order.]
        if (ch == '\n') break;
    }
    while (scanf("%d%d%c", &coef, &exp, &ch) != EOF) {
        poly2 = insertNode(poly2, coef, exp); // @@ [Same issue as above: polynomials are stored in ascending exponent order, but multiplication and printing assume or produce ascending order, while expected output is descending.]
        if (ch == '\n') break;
    }
    Node *result = multiplyPolynomials(poly1, poly2);
    printPolynomial(result); // @@ [The print function outputs terms in the order they are stored (ascending exponents), but the problem requires descending order of exponents.]
    return 0;
}