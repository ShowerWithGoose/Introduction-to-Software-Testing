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
        if (getchar() == EOF)break; // @@ The loop condition for the second polynomial is incorrect. It checks for EOF immediately after reading the first term's data, but `getchar()` consumes the newline or space after the exponent. If the input ends with a newline (as specified), `getchar()` returns '\n', not EOF, causing the loop to continue and attempt to read more data which might fail or behave unexpectedly. More critically, if there is only one term, the newline is consumed by the first `scanf`'s whitespace handling or the subsequent `getchar`. However, the standard behavior for `scanf("%d%d")` leaves the trailing newline in the buffer. The `getchar()` reads that newline. If it's not EOF, the loop continues. The real issue is likely that `getchar()` reads the newline after the last number of the second polynomial. If the input is just "15 1000000000\n", `scanf` reads 15 and 1000000000. The next char is `\n`. `getchar()` returns `\n`. `\n` != EOF. Loop continues. Next `scanf` waits for input or fails. This logic is fragile. But looking at the specific error: Expected 120, Got 240. 8*15 = 120. Why 240? 240 is 120*2. This suggests the term was added twice. This happens if the second polynomial loop runs twice or processes the term twice. Let's look at the input parsing again.
        // Input:
        // 8 1000000000\n
        // 15 1000000000\n
        //
        // First loop:
        // scanf reads 8, 1000000000. Buffer has \n.
        // getchar() reads \n. Breaks. Correct.
        //
        // Second loop:
        // scanf reads 15, 1000000000. Buffer has \n.
        // getchar() reads \n. \n != EOF. Loop does NOT break.
        // Loop continues.
        // scanf tries to read next term. Waits for input? Or if stdin is closed/EOF reached eventually?
        // In many online judges, if scanf fails to read two integers, it returns < 2. The code doesn't check scanf return value.
        // If scanf fails, term contains garbage or previous values? Uninitialized local variable `term` in the loop scope?
        // No, `Term term;` is declared inside the loop. It is uninitialized.
        // If scanf fails, `term.coefficient` and `term.exponent` are indeterminate.
        // Then `inserttail` adds a garbage term.
        // Then `getchar()` might return EOF if stream is exhausted.
        //
        // However, the output is exactly double. This implies the valid term (15, 10^9) was processed twice, or the result 120 was added to itself.
        // If the second loop runs twice with the same valid data, how?
        // It doesn't re-read the same data.
        //
        // Let's re-evaluate the `getchar()` logic.
        // If the second polynomial input is "15 1000000000\n", and we are at the end of file/stream.
        // 1. `scanf` reads 15 and 1000000000.
        // 2. `getchar()` reads '\n'.
        // 3. Condition `getchar() == EOF` is false.
        // 4. Loop repeats.
        // 5. `scanf("%d%d", ...)` attempts to read. Since there is no more input, it returns EOF (or 0/1 depending on implementation/state). It does NOT update `term`.
        // 6. `term` is uninitialized. Using uninitialized memory is Undefined Behavior.
        // 7. `inserttail` adds this garbage term.
        // 8. `getchar()` returns EOF.
        // 9. Loop breaks.
        //
        // So we have one valid term (15, 10^9) and one garbage term in Q.
        // P has (8, 10^9).
        // Multiplication:
        // Term1: 8*15 = 120, Exp: 2*10^9.
        // Term2: 8*GarbageCoeff, Exp: 10^9 + GarbageExp.
        //
        // If the garbage coeff happened to be 15 and exponent 10^9, we would get another 120, 2*10^9.
        // Then merge would combine them to 240, 2*10^9.
        // This matches the symptom perfectly. The uninitialized `term` retained the values from the previous iteration or stack garbage that matched the previous values.
        // To fix this, we should check the return value of scanf or break on EOF/newline correctly.
        // The standard way to read until newline/EOF for pairs:
        
    }
    Polynomial *r = multiply(p, q);
    print(r);
    p = destory(p);
    q = destory(q);
    r = destory(r);
    return 0;
}