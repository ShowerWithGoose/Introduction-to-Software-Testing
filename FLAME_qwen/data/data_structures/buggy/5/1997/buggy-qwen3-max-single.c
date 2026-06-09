#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

typedef struct shi
{
    int coe;
    int index;
    struct shi* next;
}ss;

void paixudayin(ss** pphead)
{
    ss* p = *pphead;
    ss* q = p->next;

    while (p != NULL)
    {
        q = p->next;
        while (q != NULL)
        {
            if (p->index == q->index)
            {
                p->coe = q->coe + p->coe;
                ss* qPrev = p;
                while (qPrev->next != q)
                {
                    qPrev = qPrev->next;
                }
                
                qPrev->next = q->next;
                q = qPrev->next;
                continue;
            }
            q = q->next;
        }
        p = p->next;
    }

    while (p != NULL) // @@ [After the previous loop, p is NULL, so this loop never runs. Sorting by exponent will not occur.]
    {
        q = p->next;
        while (q != NULL)
        {
            if (p->index < q->index)
            {
                int tmp = 0;
                tmp = p->coe;
                p->coe = q->coe;
                q->coe = tmp;
                tmp = p->index;
                p->index = q->index;
                q->index = tmp;
                continue;
            }
            q = q->next;
        }
        p = p->next;
    }

    ss* kaishi = *pphead;
    while (kaishi != NULL)
    {
        printf("%d %d ", kaishi->coe, kaishi->index);
        kaishi = kaishi->next;
    }
}

int Pushback(ss** pphead)
{
    int coe = 0;
    int index = 0;
    int ce = 0;
    while (1)
    {
        scanf("%d", &coe);
        
        scanf("%d", &index);
        ss* newnode = (ss*)malloc(sizeof(ss));
        newnode->next = NULL;
        newnode->coe = coe;
        newnode->index = index;
        if (*pphead == NULL)
            *pphead = newnode;
        else
        {
            ss* tail = *pphead;
            while (tail->next != NULL)
            {
                tail = tail->next;
            }
            tail->next = newnode;
        }
        if (ce = getchar() == '\n') // @@ [Operator precedence error: '=' has lower precedence than '==', so it's equivalent to ce = (getchar() == '\n'). This assigns 1 or 0 to ce, but more critically, the loop breaks only when newline is read immediately after the last number, which may not happen due to buffering or extra spaces. Also, the assignment should be '==' for comparison if used in condition, but logic is flawed.]
            break;
    }
    return ce;
}

void jisuan(ss* first, ss* second) // @@ [Function signature expects 2 arguments, but called with 3 in main()]
{
    ss* jieguo = NULL;
    ss *p1 = first, *p2 = second, *t = jieguo;
    while (p1 != NULL)
    {
        p2 = second;
        while (p2 != NULL)
        {
            ss* newnode = (ss*)malloc(sizeof(ss));
            newnode->coe = p1->coe * p2->coe;
            newnode->index = p1->index + p2->index;
            if (jieguo == NULL)
            {
                t = jieguo = newnode;
            }
            else
            {
                t->next = newnode;
                t = t->next;
                //free(newnode);
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    t->next = NULL; // @@ [If no terms were added (e.g., empty input), jieguo and t are NULL, leading to dereference of NULL pointer.]
    paixudayin(&jieguo);
}

int main()
{
    ss* first = NULL;
    ss* second = NULL;
    ss* jieguo;
    int m = 0;
    Pushback(&first);
    Pushback(&second);
    jisuan(first, second, &jieguo); // @@ [Calling jisuan with 3 arguments, but it's defined to take only 2. This causes a compilation error.]
    return 0;
}