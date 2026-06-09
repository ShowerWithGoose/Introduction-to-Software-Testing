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

    while (p != NULL)
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
        if (ce = getchar() == '\n')
            break;
    }
    return ce;
}

void jisuan(ss* first, ss* second)
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
    t->next = NULL;
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
    jisuan(first, second, &jieguo); // @@ [The function 'jisuan' is declared to take only two arguments (ss*, ss*), but three arguments are provided here: (first, second, &jieguo). This causes a compilation error due to mismatched function signature.]
    return 0;
}