#include <stdio.h>
#include <stdlib.h>

struct unit
{
    int num;
    int index;
    struct unit *next;
};

typedef struct unit node;
typedef struct unit *pnode;

pnode insert(pnode head, int num, int index)
{
    pnode p = head, q = NULL, r = NULL;
    r = (pnode)malloc(sizeof(node));
    r->num = num;
    r->index = index;
    r->next = NULL;
    if (head == NULL)
    {
        return r;
    }
    for (p = head; p != NULL && p->index > index; q = p, p = p->next)
        ;
    if (p == NULL)
    {
        q->next = r;
        r->next = p;
    }
    else if (p->index == index)
    {
        p->num += num;
    }
    else if (p == head)
    {
        r->next = p;
        return r;
    }
    else
    {
        q->next = r;
        r->next = p;
    }
    return head;
}

int main()
{
    pnode head1 = NULL, head2 = NULL, head3 = NULL;
    int num, index, tmp = 2100000000,count=0,flag=0;
    while ((scanf("%d%d", &num, &index)) != EOF)
    {
        if (index >= tmp)
        {
            head2 = insert(head2, num, index);
            flag=1;
            break;
        }
        head1 = insert(head1, num, index);
        tmp = index;
        count++;
    }
    if(count==2&&flag==0){
        printf("%d ", head1->next->num*head1->num);
        printf("%d ", head1->next->index+head1->index);
    }
    while ((scanf("%d%d", &num, &index)) != EOF)
    {
        head2 = insert(head2, num, index);
    }
    pnode p1 = head1, p2 = head2;
    int r1, r2;
    while (p1 != NULL)
    {
        p2 = head2;
        while (p2 != NULL)
        {
            r1 = (p1->num) * (p2->num);
            r2 = (p1->index) + (p2->index);
            head3 = insert(head3, r1, r2);
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    pnode p = NULL;
    for (p = head3; p != NULL; p = p->next)
    {
        if (p->num != 0)
        {
            printf("%d ", p->num);
            printf("%d ", p->index);
        }
    }
}


