#include <stdio.h>
#include <stdlib.h>

typedef struct Term {
    int coefficient;
    int exponent;
}Term;

typedef struct Node {
    Term term;
    struct Node *next;
}Node;

typedef struct polynomial {
    int length;
    Node *head;
}Polynomial;

typedef Term ElemType;

#define ISEXPEQUAL(a, b) ((a).exponent == (b).exponent)
#define ADDEXPONENT(a, b) ((a).exponent + (b).exponent)
#define MULTICOEFFICIENT(a, b) ((a).coefficient * (b).coefficient)
#define ADDCOEFFICIENT(a, b) ((a).coefficient + (b).coefficient)

Term addterm(Term a, Term b)
{
    return (Term)
    {
        ADDCOEFFICIENT(a, b), a.exponent
    };
}

Term multiterm(Term a, Term b)
{
    return (Term)
    {
        MULTICOEFFICIENT(a, b), ADDEXPONENT(a, b)
    };
}

int compare(const void *a, const void *b)
{
    if (((Term *)a)->exponent > ((Term *)b)->exponent)
        return -1;
    else if (((Term *)a)->exponent < ((Term *)b)->exponent)
        return 1;
    else
        return 0;
}


Polynomial *init()
{
    Polynomial *p = (Polynomial *)malloc(sizeof(Polynomial));
    p->length = 0;
    p->head = (Node *)malloc(sizeof(Node));
    p->head->next = NULL;
    return p;
}

Polynomial *destory(Polynomial *p)
{
    Node *node = p->head;
    while (node != NULL) {
        Node *q = node;
        node = node->next;
        free(q);
    }
    free(p);
    return NULL;
}

void inserttail(Polynomial *p, Term term)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->term = term;
    node->next = NULL;
    Node *tail = p->head;
    while (tail->next != NULL)
        tail = tail->next;
    tail->next = node;
    p->length++;
}

void delete(Polynomial *p, Node *node)
{
    Node *q = p->head;
    while (q->next != node)
        q = q->next;
    q->next = node->next;
    free(node);
    p->length--;
}

void sort(Polynomial *p)
{
    Term *terms = (Term *)malloc(p->length * sizeof(Term));
    Node *node = p->head->next;
    for (int i = 0; i < p->length; i++) {
        terms[i] = node->term;
        node = node->next;
    }
    qsort(terms, p->length, sizeof(Term), compare);
    node = p->head->next;
    for (int i = 0; i < p->length; i++) {
        node->term = terms[i];
        node = node->next;
    }
    free(terms);
}

void merge(Polynomial *p)
{
    Node *node = p->head->next;
    while (node->next != NULL) {
        if (ISEXPEQUAL(node->term, node->next->term)) {
            node->term = addterm(node->term, node->next->term);
            Node *q = node->next;
            node->next = q->next;
            free(q);
            p->length--;
        }
        else {
            node = node->next;
        }
    }
}

Polynomial *multiply(Polynomial *p, Polynomial *q)
{
    Polynomial *r = init();
    Node *node1 = p->head->next;
    while (node1 != NULL) {
        Node *node2 = q->head->next;
        while (node2 != NULL) {
            inserttail(r, multiterm(node1->term, node2->term));
            node2 = node2->next;
        }
        node1 = node1->next;
    }
    sort(r);
    merge(r);
    return r;
}

void print(Polynomial *p)
{
    Node *node = p->head->next;
    int num = p->length;
    while (node != NULL) {
        printf("%d %d", node->term.coefficient, node->term.exponent);
        node = node->next;
        if (--num)printf(" ");
    }
}

int main()
{
    Polynomial *p = init();
    Polynomial *q = init();
    while (1) {
        Term term;
        scanf("%d%d", &term.coefficient, &term.exponent);
        inserttail(p, term);
        if (getchar() == '\n')break;
    }
    while (1) {
        Term term;
        scanf("%d%d", &term.coefficient, &term.exponent); // @@ The input format for the second polynomial ends with a newline, not EOF. Using EOF here causes the loop to potentially miss the termination condition or behave incorrectly if the input stream doesn't close immediately. More critically, the problem states "input ends with a newline character". The first loop breaks on '\n'. The second loop should also break on '\n' to correctly parse the second polynomial which is on the next line(s). If the second polynomial is the last input, getchar() will return '\n' after the last number pair. Checking for EOF is incorrect for standard interactive or file input where the file ends after the newline or just contains the newline.
        inserttail(q, term);
        if (getchar() == EOF)break; // @@ Should check for '\n' instead of EOF to match the input format description and the logic used for the first polynomial.
    }
    Polynomial *r = multiply(p, q);
    print(r);
    p = destory(p);
    q = destory(q);
    r = destory(r);
    return 0;
}