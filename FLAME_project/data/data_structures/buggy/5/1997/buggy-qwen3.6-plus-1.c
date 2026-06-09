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

void jisuan(ss* first, ss* second) // @@ [The function is defined with 2 parameters, but called with 3 in main. The third parameter '&jieguo' in the call causes the compilation error "too many arguments". Additionally, the logic inside uses a local 'jieguo' which is not returned or used correctly if the signature were changed. The primary fix for the compilation error is to match the definition and declaration/call. Since the function calculates and prints internally, the third argument is unnecessary.]
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
    jisuan(first, second, &jieguo); // @@ [Error: Too many arguments passed to 'jisuan'. The function 'jisuan' is defined to take only two arguments (ss* first, ss* second), but here it is called with three. The variable 'jieguo' is uninitialized and unused in main if 'jisuan' handles printing internally as per its current implementation.]
    return 0;
}