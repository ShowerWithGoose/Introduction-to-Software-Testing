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
    for(o=head3->next;o!=NULL;o=o->next)
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
        k=head3;u=k;q=head3->next;l=-1;
    }
    if(head3->next!=NULL)
    printf("%d %d ",head3->next->t,head3->next->n); // @@ [This line prints the last remaining term after the sorting loop has already printed all terms and deleted them from the list. However, by the time this line executes, head3->next is likely NULL due to the destructive selection sort above, so this prints an extra incorrect term or nothing. Also, the sorting loop itself is flawed: it deletes nodes as it prints them but runs for the original number of iterations, potentially accessing freed memory or missing terms. Moreover, zero-coefficient terms are not removed, and the sorting logic does not correctly handle duplicate exponents that may still exist due to incomplete merging.]
    return 0; 
}