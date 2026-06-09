#include<stdio.h>
#include<stdlib.h>
struct node
{
    int val;
    struct node *next;
};
struct node *head=NULL;

int main()
{
    int op;
    int vau=0;
    struct node *p=NULL;
    while (1)
    {
        scanf("%d",&op);
        if(op==1)
        {
            int zhi;
            scanf("%d",&zhi);
            if(vau==0)
            {
                p=(struct node *)malloc(sizeof(struct node));
                p->val=zhi;
                p->next=NULL;
                head=p;
            }
            else if(vau==99) // @@ [Error: capacity check should be vau==100 (maximum 100 elements). Also, when this error occurs, vau will still be incremented later, causing count mismatch.]
            {
                printf("error ");
            }
            else
            {
                struct node *q=NULL;
                q=(struct node *)malloc(sizeof(struct node));
                q->val=zhi;
                p->next=q;
                q->next=NULL;
                p=p->next;
            }
            vau++; // @@ [Error: increments even on failed push (stack full or error branch), should only increment on successful push.]
        }
        else if(op==0)
        {
            if(vau==0)
            {
                printf("error ");
            }
            else if(vau==1)
            {
                printf("%d ",p->val);
                head=NULL;
                p=NULL;
                // Memory leak: the popped node is not freed.
            }
            else
            {
                printf("%d ",p->val);
                struct node *q=head;
                for(;q->next!=p;q=q->next);
                p=q; // @@ [Error: after this assignment, the original top node is lost, but it is not freed, causing memory leak.]
                q=q->next; // @@ [Error: this line is unnecessary and still does not free the popped node.]
            }
            vau--; // @@ [Error: decrements even on failed pop (empty stack), should only decrement on successful pop.]
        }
        else
        {
            break;
        }
    }
    p=head;
    while (p!=NULL)
    {
        struct node* q=p;
        p=p->next;
        free(q);
    }
    return 0;
}