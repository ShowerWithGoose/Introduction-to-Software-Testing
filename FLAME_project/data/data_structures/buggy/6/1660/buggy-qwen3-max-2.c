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
            else if(vau==99)
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
            vau++; // @@ [When vau==99, "error " is printed but vau is still incremented to 100, which causes subsequent push operations to bypass the capacity check and potentially overflow the stack. The increment should only happen on successful push.]
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
                q=q->next; // @@ [The node pointed to by q (the old tail) is not freed, causing a memory leak. More critically, after this operation, p points to the new tail, but the old tail node is not actually removed from the list because nothing sets p->next = NULL. However, the main logical error here is that the popped node is not freed, but the immediate cause of incorrect output is elsewhere. The real issue affecting output correctness is in the push logic above.]
            }
            vau--; // @@ [When vau==0 and a pop is attempted, "error " is printed but vau is decremented to -1, leading to negative stack size and undefined behavior in subsequent operations. The decrement should only happen on successful pop.]
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