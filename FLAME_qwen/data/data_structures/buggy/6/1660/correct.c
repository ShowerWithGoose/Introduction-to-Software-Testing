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
                vau++;
            }
            else if(vau==100)
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
                vau++;
            }
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
                vau--;
            }
            else
            {
                printf("%d ",p->val);
                struct node *q=head;
                for(;q->next!=p;q=q->next);
                p=q;
                q=q->next;
                vau--;
            }
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
