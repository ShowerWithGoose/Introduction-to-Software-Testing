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
            else if(vau==99) // @@ Error: The maximum capacity is 100, so the stack is full when vau==100, not vau==99. This condition should be vau==100 to correctly detect a full stack.
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
            vau++; // @@ Error: vau is incremented even when the stack is full (vau==99 case), which incorrectly increases the count. This should be inside the else branch or only when push succeeds.
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
            }
            else
            {
                printf("%d ",p->val);
                struct node *q=head;
                for(;q->next!=p;q=q->next);
                p=q;
                q=q->next; // @@ Error: This line assigns q but does nothing useful; it does not free the popped node, causing a memory leak. The popped node should be freed.
            }
            vau--;
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