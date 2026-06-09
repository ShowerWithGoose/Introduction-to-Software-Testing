//polynomial
#include <stdio.h>
#include <stdlib.h>
#define SIZE 500

typedef struct Node
{
    int coe; //coefficient
    int exp; //exponent
    struct Node *next;
} Node;
typedef Node *NodeP;

NodeP input_poly()
{
    int i;
    NodeP x = NULL, cur = NULL, new = NULL;
    //init x
    x = (NodeP)malloc(sizeof(Node)); //c node
    x->next = NULL;
    cur = x; //current at c node
    //input term of x
    for (i = 1; i < SIZE; i++)
    {
        new = (NodeP)malloc(sizeof(Node));
        scanf("%d%d", &new->coe, &new->exp);
        if ('\n' == getchar()) //end of poly
        {
            cur->next = new;
            cur = cur->next;
            cur->next = NULL;
            break;
        }
        else
        {
            cur->next = new;
            cur = cur->next;
        }
    }
    return x;
}

NodeP multi(NodeP a, NodeP b)
{
    NodeP c = NULL, new = NULL, cur = NULL, cur1 = NULL, cur2 = NULL;
    //init c
    c = (NodeP)malloc(sizeof(Node)); //c node
    c->next = NULL;
    cur = c; //current at c node
    //multi each term
    for (cur1 = a->next; cur1 != NULL; cur1 = cur1->next)
    {
        for (cur2 = b->next; cur2 != NULL; cur2 = cur2->next)
        {
            new = (NodeP)malloc(sizeof(Node));
            new->coe = cur1->coe * cur2->coe;
            new->exp = cur1->exp + cur2->exp;
            cur->next = new;
            cur = cur->next;
        }
    }
    cur->next = NULL;
    return c;
}

void check(NodeP c)
{
    NodeP cur = NULL, pre = NULL, p = NULL;
    for (cur = c->next; cur != NULL; cur = cur->next)
    {
        for (pre = cur, p = cur->next; p != NULL; pre = p, p = p->next)
        {
            if (p->exp == cur->exp)
            {
                cur->coe += p->coe;
                pre->next = p->next;
                free(p);
                p = pre->next;
            }
        }
    }
}

void sort(NodeP c)
{
    NodeP cur, tail;
    int temp;
    cur = c->next;
    tail = NULL;
    if (cur == NULL || cur->next == NULL)
    {
        return;
    }
    while (cur != tail)
    {
        while (cur->next != tail)
        {
            if (cur->exp < cur->next->exp)
            {
                temp = cur->coe;
                cur->coe = cur->next->coe;
                cur->next->coe = temp;
                temp = cur->exp;
                cur->exp = cur->next->exp;
                cur->next->exp = temp;
            }
            cur = cur->next;
        }
        tail = cur;
        cur = c;
    }
}

int main()
{
    NodeP a = NULL, b = NULL, c = NULL, p = NULL;
    a = input_poly();
    b = input_poly();
    c = multi(a, b);
    check(c);
    sort(c);
    for (p = c; p != NULL; p = p->next)
        if (p->coe > 0)
            printf("%d %d ", p->coe, p->exp);
    return 0;
}

