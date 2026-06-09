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
    // @@ The logic for handling existing terms with the same exponent is missing. 
    // The current implementation always creates a new node and inserts it, 
    // even if a term with the same exponent already exists. This leads to 
    // duplicate exponents in the result instead of summing their coefficients.
    // We need to traverse the list to check if a node with 'expn' already exists.
    // If it does, we should add 'coef' to its existing coefficient.
    // If the resulting coefficient is 0, the node should be removed.
    // If it doesn't exist, we insert a new node as currently done (but sorted).
    
    // Corrected logic sketch:
    // 1. Traverse to find if expn exists.
    // 2. If found: update coef. If coef becomes 0, delete node. Return.
    // 3. If not found: Insert new node in sorted order (descending expn).

    Polynomial q = createPolyNode(coef, expn);
    if (!*poly || (*poly)->expn < expn)
    {
        q->next = *poly;
        *poly = q;
    }
    else
    {
        while (p->next && p->next->expn >= expn)
            p = p->next;
        
        // Check if the next node has the same exponent
        if (p->next && p->next->expn == expn) {
            p->next->coef += coef;
            free(q); // Discard the newly created node as we merged it
            // Optional: If p->next->coef becomes 0, remove the node here
            if (p->next->coef == 0) {
                Polynomial temp = p->next;
                p->next = temp->next;
                free(temp);
            }
        } else {
            q->next = p->next;
            p->next = q;
        }
    }
}

Polynomial multiplyPolynomials(Polynomial poly1, Polynomial poly2)
{
    Polynomial p = poly1, q, r;
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
        scanf("%d%d%c", &coef, &expn, &ch); // 读入第一行系数和指数
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
    printf("\n");
    return 0;
}