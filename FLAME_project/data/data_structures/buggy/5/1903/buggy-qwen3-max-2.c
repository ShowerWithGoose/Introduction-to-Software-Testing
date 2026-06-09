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
        scanf("%d%d", &term.coefficient, &term.exponent);
        inserttail(q, term);
        if (getchar() == EOF)break; // @@ [The program incorrectly assumes that the second polynomial ends with EOF, but the problem states both inputs end with a newline. This causes the second loop to potentially read beyond intended input or behave inconsistently. However, the primary error causing wrong answer is below.]
    }
    Polynomial *r = multiply(p, q);
    print(r);
    p = destory(p);
    q = destory(q);
    r = destory(r);
    return 0;
}
// @@ [The core error is integer overflow: using 'int' for coefficients and exponents cannot handle large values like 8*15=120 (which fits) but more importantly 1000000000+1000000000=2000000000 which is at the limit of signed int (2^31-1 = 2147483647). However, 8*15=120 is correct, but the buggy output shows 240, which suggests the real issue is in input reading: the first loop breaks on '\n', but the second loop uses getchar()==EOF. After the first polynomial's '\n', the second polynomial's input is read correctly, but after its '\n', getchar() returns '\n' not EOF, so the loop continues and reads uninitialized/garbage data, leading to extra terms. Specifically, after reading "15 1000000000\n", getchar() returns '\n', so the loop doesn't break, and the next scanf fails, leaving term with old values (possibly 15 and 1000000000 again), causing duplicate multiplication: (8x^1e9)*(15x^1e9) twice → 120+120=240. The fix is to break on '\n' for both loops.]