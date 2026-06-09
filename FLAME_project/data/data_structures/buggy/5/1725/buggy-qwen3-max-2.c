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
        poly1 = insertNode(poly1, coef, exp); // @@ [The input reading logic inserts terms in ascending order of exponents due to the condition `cur->exp < exp` in insertNode, but the problem requires output in descending order. However, the real issue is that during input, the polynomial is built by inserting each new term using `insertNode`, which maintains ascending order by exponent. Then, multiplication uses this ascending-ordered list, and `insertNode` again inserts into result in ascending order. Finally, printing traverses from head to tail, producing ascending order, but expected output is descending.]
        if (ch == '\n') break;
    }
    while (scanf("%d%d%c", &coef, &exp, &ch) != EOF) {
        poly2 = insertNode(poly2, coef, exp); // @@ [Same issue as above: building polynomial in ascending exponent order instead of preserving input order or building in descending order.]
        if (ch == '\n') break;
    }
    Node *result = multiplyPolynomials(poly1, poly2);
    printPolynomial(result); // @@ [Prints polynomial in ascending order of exponents because the linked list is maintained in ascending order by `insertNode`, but the problem requires descending order.]
    return 0;
}