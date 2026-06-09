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
        while (current->next != NULL) { // @@ Traverses to the end of the list instead of finding the correct insertion position to maintain descending order of exponents
            current = current->next;
        }
        current->next = newNode; // @@ Appends to the tail, failing to merge like terms with the same exponent and maintain the required descending order
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
            insertNode(&result, coefficient, exponent); // @@ Calls a flawed insertion function that does not combine terms with the same exponent or sort them in descending order
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
        c = getchar(); // @@ May read a space character left in the buffer by scanf, causing incorrect loop termination or skipping input
        if(c == '\n' || c == EOF) break;
    }

    while (scanf("%d %d", &coefficient, &exponent) == 2) {
        insertNode(&poly2, coefficient, exponent);
        c = getchar(); // @@ Same issue as above, unreliable for detecting end of line due to leftover whitespace
        if(c == '\n' || c == EOF) break;
    }

    Node* result = multiply(poly1, poly2);

    Node * current = result;
    while(current != NULL)
    {
        printf("%d %d ", current->coefficient, current->exponent); // @@ Prints terms in insertion order rather than descending order, and does not filter out zero coefficients
        current = current->next;
    }
    printf("\n");

    freeNodes(poly1);
    freeNodes(poly2);
    freeNodes(result);

    return 0;
}