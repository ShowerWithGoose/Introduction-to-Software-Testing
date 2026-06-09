#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct multi
{
    int xi;
    int zhi;
    struct multi *next;
} formula;

formula stock[1000];

int cmp(const void *, const void *);

int main()
{
    formula *head1, *head2, *p11, *p12, *p21, *p22;
    p11 = p12 = (formula *)malloc(sizeof(formula));
    p21 = p22 = (formula *)malloc(sizeof(formula));
    head1 = p11, head2 = p21;
    int i;
    char string1[1000], string2[1000];
    memset(string1, 0, sizeof(string1));
    memset(string2, 0, sizeof(string2));
    char *ptr1 = string1, *ptr2 = string2;
    gets(string1);
    gets(string2);

    while (*ptr1 != '\0')
    {
        sscanf(string1 + (ptr1 - string1), "%d %d", &p11->xi, &p11->zhi);
        i = 0;
        p12->next = p11;
        p12 = p11;
        p11 = (formula *)malloc(sizeof(formula));
        while (i < 2)
        {
            if (*ptr1 == ' ' || *ptr1 == '\0')
                i++;
            ptr1++;
        }
    }
    p12->next = NULL;

    while (*ptr2 != '\0')
    {
        sscanf(string2 + (ptr2 - string2), "%d %d", &p21->xi, &p21->zhi);
        i = 0;
        p22->next = p21;
        p22 = p21;
        p21 = (formula *)malloc(sizeof(formula));
        while (i < 2)
        {
            if (*ptr2 == ' ' || *ptr2 == '\0')
                i++;
            ptr2++;
        }
    }
    p22->next = NULL;

    i = 0;
    for (p12 = head1; p12 != NULL; p12 = p12->next)
    {
        for (p22 = head2; p22 != NULL; p22 = p22->next)
        {
            stock[i].xi = p12->xi * p22->xi;
            stock[i].zhi = p12->zhi + p22->zhi;
            i++;
        }
    }
    int len = i;
    qsort(stock, len, sizeof(formula), cmp);

    formula output[1000];
    int zhi_a, j = 0;
    zhi_a = stock[0].zhi;
    output[0].xi = stock[0].xi, output[0].zhi = stock[0].zhi;
    for (i = 1; i < len; i++)
    {
        if (stock[i].zhi == zhi_a)
        {
            output[j].xi += stock[i].xi;
        }
        else
        {
            j++;
            output[j].xi = stock[i].xi;
            output[j].zhi = stock[i].zhi;
            zhi_a = stock[i].zhi;
        }
    }
    len = j;

    for (i = 0; i <= len; i++)
    {
        if (output[i].xi != 0)
            printf("%d %d ", output[i].xi, output[i].zhi);
    }

    return 0;
}

int cmp(const void *x, const void *y)
{
    formula *xx = (formula *)x;
    formula *yy = (formula *)y;
    return (yy->zhi - xx->zhi);
}
