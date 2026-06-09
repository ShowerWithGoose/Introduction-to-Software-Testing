#include <stdio.h>
#include <stdlib.h>

typedef struct dxs
{
    int coeff;
    int index;
    struct dxs *next;
} dxs;

dxs *search(dxs *first, int num)
{
    dxs *p = NULL;
    for (p = first; p; p = p->next)
    {
        if (p->index == num)
        {
            return p;
        }
    }
    return NULL;
}

void BubbleSort(dxs *head)
{
    dxs *cur, *tail;
    cur = head;
    tail = NULL;
    if (cur == NULL || cur->next == NULL)
    {
        return;
    }
    while (cur != tail)
    {
        while (cur->next != tail)
        {
            if (cur->index < cur->next->index)
            {
                int temp = cur->index;
                cur->index = cur->next->index;
                cur->next->index = temp;
                int temp1 = cur->coeff;
                cur->coeff = cur->next->coeff;
                cur->next->coeff = temp1;
            }
            cur = cur->next;
        }
        tail = cur;
        cur = head;
    }
    return;
}

int main()
{
    // freopen("data.in", "r", stdin);
    int a1, a2;
    char ch;
    dxs *first1 = NULL, *tail1 = NULL, *tail2 = NULL, *tail3 = NULL, *first2 = NULL, *first3 = NULL, *p, *k, *q, *flag;
    while (scanf("%d%d%c", &a1, &a2, &ch) != EOF)
    {
        k = (dxs *)malloc(sizeof(dxs));
        k->coeff = a1;
        k->index = a2;
        k->next = NULL;
        if (first1 == NULL)
            first1 = tail1 = k;
        else
        {
            tail1->next = k;
            tail1 = tail1->next;
        }
        if (ch == '\n')
        {
            break;
        }
    }
    while (scanf("%d%d%c", &a1, &a2, &ch) != EOF)
    {
        k = (dxs *)malloc(sizeof(dxs));
        k->coeff = a1;
        k->index = a2;
        k->next = NULL;
        if (first2 == NULL)
            first2 = tail2 = k;
        else
        {
            tail2->next = k;
            tail2 = tail2->next;
        }
        if (ch == '\n')
        {
            break;
        }
    }
    for (p = first1; p; p = p->next)
    {
        for (k = first2; k; k = k->next)
        {
            flag = search(first3, p->index + k->index);
            if (flag)
            {
                flag->coeff += p->coeff * k->coeff;
            }
            else
            {
                q = (dxs *)malloc(sizeof(dxs));
                q->next = NULL;
                q->coeff = p->coeff * k->coeff;
                q->index = p->index + k->index;
                if (first3 == NULL)
                    first3 = tail3 = q;
                else
                {
                    tail3->next = q;
                    tail3 = tail3->next;
                    tail3->next = NULL;
                }
            }
        }
    }
    BubbleSort(first3);
    for (p = first3; p; p = p->next)
    {
        printf("%d %d ", p->coeff, p->index);
    }
    p = first1;
    while (p && p->next)
    {
        q = p->next;
        p->next = p->next->next;
        free(q);
    }
    p = first2;
    while (p && p->next)
    {
        q = p->next;
        p->next = p->next->next;
        free(q);
    }
    p = first3;
    while (p && p->next)
    {
        q = p->next;
        p->next = p->next->next;
        free(q);
    }
    return 0;
}
