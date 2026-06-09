#include<stdio.h>
#include<stdlib.h>
struct node{
    long long a;
    long long power;
    struct node *next;
}*firsta, *firstb, *firstc, *p, *q, *l1, *l2, *l3;
int getWord(long long *output)
{
    char c;
    long long num = 0;
    while((c = getchar()) != ' ' && c != '\n')
        num = num*10 + c - '0';
    *output = num;
    return (c == ' ' ? 0 : 1);
}
void initlink(struct node **head)
{
    *head = p = (struct node *)malloc(sizeof(struct node *));
    int flag = 0;
    getWord(&(p->a));
    flag = getWord(&(p->power));
    p->next = NULL;
    while(!flag)
    {
        q = (struct node *)malloc(sizeof(struct node *));
        q->next = NULL;
        getWord(&(q->a));
        flag = getWord(&(q->power));
        p->next = q;
        p = p->next;
    }
}
int main()
{
    initlink(&firsta);
    initlink(&firstb);
    firstc = p = (struct node *)malloc(sizeof(struct node *));
    firstc->next = NULL;
    for(l1 = firsta; l1 != NULL; l1 = l1->next)
    {
        for(l2 = firstb; l2 != NULL; l2 = l2->next)
        {
            long long an = (l1->a)*(l2->a);
            long long powern = (l1->power)+(l2->power);
            for(l3 = firstc; l3->next != NULL; l3 = l3->next)
            {
                if(l3 == firstc)
                {
                    if(powern > l3->next->power)
                    {
                        q = (struct node *)malloc(sizeof(struct node *));
                        q->a = an;
                        q->power = powern;
                        q->next = l3->next;
                        l3->next = q;
                    }
                    else if(powern == l3->next->power)
                    {
                        l3->next->a += an;
                        break;
                    }
                }
                else
                {
                    if(l3->power > powern && l3->next->power < powern)
                    {
                        q = (struct node *)malloc(sizeof(struct node *));
                        q->a = an;
                        q->power = powern;
                        q->next = l3->next;
                        l3->next = q;
                        break;
                    }
                    else if(l3->next->power == powern)
                    {
                        l3->next->a += an;
                        break;
                    }
                }
            }
            if(l3->next == NULL)
            {
                q = (struct node *)malloc(sizeof(struct node *));
                q->a = an;
                q->power = powern;
                q->next = NULL;
                l3->next = q;
            }
        }
    }
    for(p = firstc->next; p != NULL; p = p->next)
        printf("%lld %lld ", p->a, p->power);
    return 0;
}
