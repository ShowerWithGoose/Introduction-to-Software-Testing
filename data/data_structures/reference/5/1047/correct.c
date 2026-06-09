#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct node
{
    int coef;
    int exp;
    struct node *next;
} term;
void initializePoly(term *head);
void insert(term *, term *head);
int main()
{
    term *head1 = (term *)malloc(sizeof(term));
    term *head2 = (term *)malloc(sizeof(term));
    term *output = (term *)malloc(sizeof(term));
    output->next = NULL;
    initializePoly(head1);
    initializePoly(head2);
    for (term *p = head1->next; p; p = p->next)
    {
        for (term *q = head2->next; q; q = q->next)
        {
            term *newterm = (term *)malloc(sizeof(term));
            newterm->coef = p->coef * q->coef;
            newterm->exp = p->exp + q->exp;
            newterm->next = NULL;
            insert(newterm, output);
        }
    }
    for (; output->next; output = output->next)
        printf("%d %d ", output->next->coef, output->next->exp);
    return 0;
}
void initializePoly(term *head)
{
    char s[500];
    gets(s);
    for (int i = 0; s[i]; i++)
    {
        term *p = (term *)malloc(sizeof(term));
        int n = 0;
        for (; isdigit(s[i]); i++)
            n = n * 10 + s[i] - '0';
        p->coef = n;
        while (s[i] == ' ')
            i++;
        n = 0;
        for (; isdigit(s[i]); i++)
            n = n * 10 + s[i] - '0';
        p->exp = n;
        p->next = NULL;
        head->next = p;
        head = p;
        if (!s[i])
            break;
    }
}
void insert(term *targ, term *head)
{
    if (!head->next)
        head->next = targ;
    else
    {
        term *p, *q;
        for (p = head->next, q = head; p; q = p, p = p->next)
        {
            if (p->exp == targ->exp)
            {
                p->coef += targ->coef;
                free(targ);
                break;
            }
            else if (p->exp < targ->exp)
            {
                q->next = targ;
                targ->next = p;
                break;
            }
        }
        if (!p)
            q->next = targ;
    }
}


