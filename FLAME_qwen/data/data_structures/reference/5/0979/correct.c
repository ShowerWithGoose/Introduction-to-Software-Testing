#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int coef;
    int exp;
    struct node *next;
} Lnode, *Pnode;

void bubble_sort_(int arr1[], int arr2[], int len)
{
    int i, j, temp1, temp2;
    for (i = 0; i < len - 1; i++)
        for (j = 0; j < len - 1 - i; j++)
            if (arr1[j] < arr1[j + 1])
            {
                temp1 = arr1[j];
                arr1[j] = arr1[j + 1];
                arr1[j + 1] = temp1;
                temp2 = arr2[j];
                arr2[j] = arr2[j + 1];
                arr2[j + 1] = temp2;
            }
}

int main()
{
    Pnode tmp = NULL, out = NULL, pre = NULL, lista = NULL, listb = NULL, r = NULL, ra = NULL, rb = NULL;
    char c;
    int coef[1000] = {0}, exp[1000] = {0};
    int i = 0, a, b, j, len, num;
    while (scanf("%d%d%c", &a, &b, &c) != EOF)
    {
        tmp = (Pnode)malloc(sizeof(Lnode));
        if (lista == NULL)
        {
            lista = tmp;
            pre = tmp;
            lista->coef = a;
            lista->exp = b;
        }
        else
        {
            pre->next = tmp;
            pre->next->coef = a;
            pre->next->exp = b;
            pre = pre->next;
        }
        if (c == '\n')
        {
            tmp->next = NULL;
            break;
        }
    }
    while (scanf("%d%d%c", &a, &b, &c) != EOF)
    {
        tmp = (Pnode)malloc(sizeof(Lnode));
        if (listb == NULL)
        {
            listb = tmp;
            pre = tmp;
            listb->coef = a;
            listb->exp = b;
        }
        else
        {
            pre->next = tmp;
            pre->next->coef = a;
            pre->next->exp = b;
            pre = pre->next;
        }
        if (c == '\n')
        {
            tmp->next = NULL;
            break;
        }
    }
    ra = lista;
    rb = listb;
    while (ra != NULL)
    {
        while (rb != NULL)
        {
            tmp = (Pnode)malloc(sizeof(Lnode));
            tmp->next = NULL;
            tmp->coef = ra->coef * rb->coef;
            tmp->exp = ra->exp + rb->exp;
            rb = rb->next;
            if (out == NULL)
            {
                out = tmp;
                pre = tmp;
            }
            else
            {
                pre->next = tmp;
                pre = tmp;
            }
        }
        ra = ra->next;
        rb = listb;
    }
    for (r = out, i = 0, len = 0; r != NULL; r = r->next, i++)
    {
        coef[i] = r->coef;
        exp[i] = r->exp;
        len++;
    }

    bubble_sort_(exp, coef, i - 1);

    for (i = 0; i < len - 1; i++)
    {
        num = 0;
        for (j = i + 1; (exp[j] == exp[i]) && (j <= len - 1); j++)
        {
            coef[i] += coef[j];
            num++;
        }
        for (j = i + 1; (j < len) && (num != 0); j++)
        {
            coef[j] = coef[j + num];
            exp[j] = exp[j + num];
        }
        if (num != 0)
        {
            len -= num;
        }
    }

    for (j = 0; j < len; j++)
    {
        printf("%d %d ", coef[j], exp[j]);
    }

    for (r = lista; r != NULL;)
    {
        pre = r;
        r = r->next;
        free(pre);
    }
    for (r = listb; r != NULL;)
    {
        pre = r;
        r = r->next;
        free(pre);
    }
    for (r = out; r != NULL;)
    {
        pre = r;
        r = r->next;
        free(pre);
    }
    return 0;
}
