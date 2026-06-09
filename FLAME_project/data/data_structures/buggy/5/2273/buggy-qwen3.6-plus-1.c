#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int t;
    int n;
    struct node *next;
}node;
int main()
{
    int a,b,i,nn,l;
    char c;
    node *head1=(node *)malloc(sizeof(node));
    head1->next=NULL;
    node *rear=head1;
    while(scanf("%d %d",&a,&b))
    {
        node *newnode=(node *)malloc(sizeof(node));
        newnode->next=NULL;
        newnode->t=a;newnode->n=b;
        rear->next=newnode;
        rear=newnode;
        scanf("%c",&c);
        if(c=='\n')
        break;
    }
    node *head2=(node *)malloc(sizeof(node));
    head2->next=NULL;
    rear=head2;
    while(scanf("%d %d",&a,&b))
    {
        node *newnode=(node *)malloc(sizeof(node));
        newnode->next=NULL;
        newnode->t=a;newnode->n=b;
        rear->next=newnode;
        rear=newnode;
        scanf("%c",&c);
        if(c=='\n')
        break;
    }
    node *p,*q,*o,*u,*k;
    node *head3=(node *)malloc(sizeof(node));
    head3->next=NULL;
    rear=head3;
    for(p=head1->next;p!=NULL;p=p->next)
    {
        for(q=head2->next;q!=NULL;q=q->next)
        {    
            nn=p->n+q->n;
            l=1;
            for(o=head3->next;o!=NULL;o=o->next)
            {
                if(o->n==nn)
                {
                    o->t+=(p->t*q->t);
                    l=0;
                }
            }
            if(l==1)
            {
                node *newnode=(node *)malloc(sizeof(node));
                newnode->next=NULL;
                newnode->t=(p->t*q->t);newnode->n=nn;
                rear->next=newnode;
                rear=newnode;
            }
        }
    }
    for(o=head3->next;o!=NULL;o=o->next) // @@ The loop condition and body are incorrect for selection sort. It iterates using 'o' but modifies the list structure inside, leading to skipped elements or infinite loops. Also, it prints inside the loop which disrupts the sorting logic if not carefully handled with removal. The main issue is that this loop attempts to sort and print simultaneously but fails to correctly iterate through all elements because the list is being modified (nodes removed) while iterating with a simple for loop that expects a stable list structure.
    {
        k=head3;u=k;q=head3->next;l=-1;
        for(p=head3->next;p!=NULL;p=p->next)
        {
            if((p->n)>l)
            {
                u=k;
                q=p;
                l=q->n;
            }
            k=p;
        }
        printf("%d %d ",q->t,q->n);
        u->next=q->next;
        free(q); // @@ Memory leak: the removed node should be freed. Although not strictly a WA cause, it's good practice. More importantly, the outer loop 'for(o=...)' is invalid now because the list structure changed.
        k=head3;u=k;q=head3->next;l=-1;
    }
    if(head3->next!=NULL) // @@ This line attempts to print the last remaining element, but the previous loop logic is flawed. If the list becomes empty during the loop, this might print garbage or crash if head3->next was freed. The primary error is the sorting/printing logic above.
    printf("%d %d ",head3->next->t,head3->next->n);
    return 0; 
}