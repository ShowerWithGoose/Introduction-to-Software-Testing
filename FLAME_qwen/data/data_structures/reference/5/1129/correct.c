#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct data
{
    long long int coe;   //系数
    long long int index; //指数
    struct data *next;
} Node, *Link;
void InsertNode(Link head, int coe, int index)
{
    Link p, q = (Link)malloc(sizeof(Node));
    p = head;
    while (p->next != NULL)
    {
        if (p->index > index && p->next->index < index)
        {
            q->next = p->next;
            q->coe = coe;
            q->index = index;
            p->next = q;
            return;
        }
        else if (p->index == index)
        {
            p->coe += coe;
            free(q);
            return;
        }
        else
        {
            p = p->next;
        }
    }
    if (p->next == NULL)
    {
        q->next = p->next;
        q->coe = coe;
        q->index = index;
        p->next = q;
        return;
    }
}
Link multlist(Link h1, Link h2)
{
    int i, j;
    Link head, node;
    Link p1, p2;
    head = (Link)malloc(sizeof(Node));
    head->next = NULL;
    head->coe = 0;
    head->index = 2100000000;
    h1 = h1->next;
    h2 = h2->next;
    p1 = h1, p2 = h2;
    while (p1 != NULL)
    {
        while (p2 != NULL)
        {
            InsertNode(head, p1->coe * p2->coe, (p1->index) + (p2->index));
            p2 = p2->next;
        }
        p2 = h2;
        p1 = p1->next;
    }
    return head;
}
void displayNode1(Link head)
{
    Link p = head->next;
    while (p != NULL)
    {
        printf("%d %d ", p->coe, p->index);
        p = p->next;
    }
};
Link newList()
{
    int i = 0;
    long long int m1, m2;
    Link head, node;
    head = (Link)malloc(sizeof(Node));
    head->next = NULL;
    while ((scanf("%lld%lld", &m1, &m2)) != EOF)
    {
        node = (Link)malloc(sizeof(Node));
        node->coe = m1;
        node->index = m2;
        node->next = head->next;
        head->next = node;
        i++;
        if (getchar() == '\n')
            break;
    }
    return head;
}
int main()
{
    int i = 0, j, k;
    Link head1, head2, head3;
    head1 = newList();
    head2 = newList();
    head3 = multlist(head1, head2);
    displayNode1(head3);
    getchar();
    return 0;
}
