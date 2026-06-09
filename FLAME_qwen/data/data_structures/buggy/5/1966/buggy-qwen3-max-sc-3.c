#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coef;
    int ind;
    struct Node *next;
} Node;

Node *multipoly(Node *poly1, Node *poly2) {
    Node *result = NULL;
    Node *p1 = poly1, *p2;
    Node *tmp, *tail;

    while (p1 != NULL) {
        p2 = poly2;
        while (p2 != NULL) {
            int new_coef = p1->coef * p2->coef;
            int new_ind = p1->ind + p2->ind;
            tmp = result;
            tail=NULL;
            while (tail != NULL && tail->ind > new_ind) { // @@ [Logic error: 'tail' is initialized to NULL, so the loop condition 'tail != NULL' fails immediately, preventing proper traversal to find insertion point. This causes incorrect insertion and merging logic.]
                tail = tmp;
                tmp = tmp->next;
            }

            if (tail != NULL && tail->ind == new_ind) { // @@ [Because 'tail' remains NULL due to the earlier loop not executing, this condition never triggers for merging terms with same exponent, leading to duplicate terms instead of combining coefficients.]
                tail->coef += new_coef;
            } else {
                Node *new_node = (Node *)malloc(sizeof(Node));
                new_node->coef = new_coef;
                new_node->ind = new_ind;
                if (tmp == result) {
                    new_node->next = result;
                    result = new_node;
                } else {
                    new_node->next = tmp;
                    tail->next = new_node; // @@ [If 'tail' is NULL (which it always is due to earlier bug), this line causes a segmentation fault or undefined behavior when trying to access 'tail->next'.]
                }
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    return result;
}

void freepoly(Node *poly) {
    Node *tmp;
    while (poly != NULL) {
        tmp = poly;
        poly = poly->next;
        free(tmp);
    }
}

void printpoly(Node *poly) {
    while (poly != NULL) {
        printf("%d %d ", poly->coef, poly->ind);
        poly = poly->next;
    }
    printf("\n");
}

void clear11() {
    int c = getchar();
    while (c != '\n' && c != EOF);
}

int main() {
    Node *poly1 = NULL, *poly2 = NULL;
    Node *result;

    int coef, ind;
    while (scanf("%d%d", &coef, &ind) == 2) {
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node->coef = coef;
        new_node->ind = ind;
        new_node->next = poly1;
        poly1 = new_node;

        int c = getchar();
        if (c == '\n' || c == EOF)
            break;
        ungetc(c, stdin);
    }



    while (scanf("%d%d", &coef, &ind) == 2) {
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node->coef = coef;
        new_node->ind = ind;
        new_node->next = poly2;
        poly2 = new_node;

        int c = getchar();
        if (c == '\n' || c == EOF)
            break;
        ungetc(c, stdin);
    }

    result = multipoly(poly1, poly2);

    printpoly(result);
    freepoly(poly1);
    freepoly(poly2);
    freepoly(result);

    return 0;
}