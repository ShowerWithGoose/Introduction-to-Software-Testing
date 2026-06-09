#include <stdio.h>
#include <stdlib.h>

typedef struct multi
{
    int a;
    int n;
    struct multi* next;
} multi;

typedef multi* M;

M create()
{
    M list = malloc(sizeof(multi));
    list->next = NULL;
    return list;
}

void link(int l, int b, M* p)
{
    (*p)->next = malloc(sizeof(multi));
    *p = (*p)->next;
    (*p)->a = l;
    (*p)->n = b;
    (*p)->next = NULL;
}

M mult(M p, M p3)
{
    M temp = create();
    M p4 = temp;
    M p5 = p->next;
    
    while (p5 != NULL)
    {
        p4->next = malloc(sizeof(multi));
        p4 = p4->next;
        p4->a = p5->a * p3->a;
        p4->n = p5->n + p3->n;
        p5 = p5->next;
        p4->next = NULL;
    }
    
    return temp;
}

void add(M p1, M p2)
{
    M p = p1;
    p1 = p1->next;
    p2 = p2->next;
    
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->n > p2->n)
        {
            p->next = p1;
            p1 = p1->next;
        }
        else if (p1->n < p2->n)
        {
            p->next = p2;
            p2 = p2->next;
        }
        else
        {
            p1->a += p2->a;
            p->next = p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        
        p = p->next;
    }
    
    if (p1 == NULL)
        p->next = p2;
    else if (p2 == NULL)
        p->next = p1;
    else
        p->next = NULL;
}

int main()
{
    M lian1 = create();
    M lian2 = create();
    M p1 = lian1;
    M p2 = lian2;
    int tem1, tem2;
    
    while (1)
    {
        scanf("%d%d", &tem1, &tem2);
        link(tem1, tem2, &p1);
        if (getchar() == '\n')
            break;
    }
    
    while (scanf("%d%d", &tem1, &tem2) != EOF)
    {
        link(tem1, tem2, &p2);
    }
    
    M lian3 = create();
    M p3 = lian2->next;
    
    while (p3 != NULL)
    {
        add(lian3, mult(lian1, p3));
        p3 = p3->next;
    }
    
    lian3 = lian3->next;
    
    while (lian3 != NULL)
    {
        printf("%d %d\n", lian3->a, lian3->n);
        lian3 = lian3->next;
    }
    
    return 0;
}


