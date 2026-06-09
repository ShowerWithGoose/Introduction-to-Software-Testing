#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode
{
    int coef;
    int expn;
    struct PolyNode *next;
} PolyNode, *Polynomial;

Polynomial createPolyNode(int coef, int expn)
{
    Polynomial p = (Polynomial)malloc(sizeof(PolyNode));
    p->coef = coef;
    p->expn = expn;
    p->next = NULL;
    return p;
}

void insertPolyNode(Polynomial *poly, int coef, int expn)
{
    Polynomial p = *poly;
    Polynomial q = createPolyNode(coef, expn);
    if (!*poly || (*poly)->expn < expn)
    {
        q->next = *poly;
        *poly = q;
    }
    else
    {
        while (p->next && p->next->expn >= expn) // @@ The condition `>=` causes the loop to skip over nodes with the same exponent instead of stopping before them. This prevents merging coefficients of like terms, resulting in duplicate exponents in the output. It should use `>` and handle equality separately to add coefficients.
            p = p->next;
        q->next = p->next;
        p->next = q;
    }
}

Polynomial multiplyPolynomials(Polynomial poly1, Polynomial poly2)
{
    Polynomial p = poly1, q, r; // @@ Variable `r` is declared but never used, which will trigger a compilation error under strict compiler flags (e.g., `-Werror=unused-variable`).
    Polynomial poly = NULL;
    while (p)
    {
        q = poly2;
        while (q)
        {
            insertPolyNode(&poly, p->coef * q->coef, p->expn + q->expn);
            q = q->next;
        }
        p = p->next;
    }
    return poly;
}

int main()
{
    Polynomial poly1 = NULL, poly2 = NULL, poly;
    int coef, expn;
    char ch;
    do
    {                                       // 创建一个带头结点的有序链表存放第一个多项式
        scanf("%d%d%c", &coef, &expn, &ch); // @@ Missing whitespace handling before `%c` may cause `ch` to capture a trailing space instead of `\n`, leading to incorrect loop termination or infinite loops. It should be `scanf(" %d %d%c", ...)` to skip whitespace.
        insertPolyNode(&poly1, coef, expn); // 插入到有序链表中
    } while (ch != '\n');
    while (scanf("%d%d", &coef, &expn) != EOF)
    {
        insertPolyNode(&poly2, coef, expn);
    }
    poly = multiplyPolynomials(poly1, poly2);
    while (poly)
    {
        printf("%d %d ", poly->coef, poly->expn);
        poly = poly->next;
    }
<think>
</think>