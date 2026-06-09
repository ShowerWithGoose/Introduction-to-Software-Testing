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

NodeP multi(NodeP poly1, NodeP poly2)
{
    NodeP result = NULL, new = NULL, cur = NULL, cur1 = NULL, cur2 = NULL;
    //init c
    result = (NodeP)malloc(sizeof(Node)); //c node
    result->next = NULL;
    cur = result; //current at c node
    //multi each term
    for (cur1 = poly1->next; cur1 != NULL; cur1 = cur1->next)
    {
        for (cur2 = poly2->next; cur2 != NULL; cur2 = cur2->next)
        {
            new = (NodeP)malloc(sizeof(Node));
            new->coe = cur1->coe * cur2->coe;
            new->exp = cur1->exp + cur2->exp;
            cur->next = new;
            cur = cur->next;
        }
    }
    cur->next = NULL;
    return result;
}

void check(NodeP result)
{
    NodeP cur = NULL, prev = NULL, next = NULL;
    for (cur = result->next; cur != NULL; cur = cur->next)
    {
        for (prev = cur, next = cur->next; next != NULL; prev = next, next = next->next)
        {
            if (next->exp == cur->exp)
            {
                cur->coe += next->coe;
                prev->next = next->next;
                free(next);
                next = prev->next;
            }
        }
    }
}

void sort(NodeP result)
{
    NodeP cur, tail;
    int temp;
    cur = result->next;
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
        cur = result;
    }
}

int main()
{
    NodeP poly1 = NULL, poly2 = NULL, result = NULL, next = NULL;
    poly1 = input_poly();
    poly2 = input_poly();
    result = multi(poly1, poly2);
    check(result);
    sort(result);
    for (next = result; next != NULL; next = next->next)
        if (next->coe > 0)
            printf("%d %d ", next->coe, next->exp);
    return 0;
}

