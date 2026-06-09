#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coefficient;  // 系数
    int exponent;     // 指数
    struct Node* next;  // 指向下一个节点的指针
} Node;


Node* createNode(int coefficient, int exponent) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node** head, int coefficient, int exponent) {
    Node* newNode = createNode(coefficient, exponent);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void freeNodes(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

Node* multiply(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node* current1 = poly1;
    while (current1 != NULL) {
        Node* current2 = poly2;
        while (current2 != NULL) {
            int coefficient = current1->coefficient * current2->coefficient;
            int exponent = current1->exponent + current2->exponent;
            insertNode(&result, coefficient, exponent); // @@ Error: Does not combine terms with same exponent; also does not maintain descending order. Should merge like terms and insert in sorted order.
            current2 = current2->next;
        }
        current1 = current1->next;
    }
    return result;
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;

    int coefficient, exponent;
    char c;
    while (scanf("%d %d", &coefficient, &exponent) == 2) {
        insertNode(&poly1, coefficient, exponent);
        c = getchar();
        if(c == '\n' || c == EOF) break; // @@ Potential issue: If input has trailing spaces, getchar may consume a space instead of newline, causing loop to continue incorrectly.
    }

    while (scanf("%d %d", &coefficient, &exponent) == 2) {
        insertNode(&poly2, coefficient, exponent);
        c = getchar();
        if(c == '\n' || c == EOF) break; // @@ Same issue as above.
    }

    Node* result = multiply(poly1, poly2); // @@ Result may contain duplicate exponents and is not sorted in descending order.

    Node * current = result;
    while(current != NULL)
    {
        printf("%d %d ", current->coefficient, current->exponent); // @@ Output order may not be descending; duplicate exponents should be combined.
        current = current->next;
    }
    printf("\n");

    freeNodes(poly1);
    freeNodes(poly2);
    freeNodes(result);

    return 0;
}