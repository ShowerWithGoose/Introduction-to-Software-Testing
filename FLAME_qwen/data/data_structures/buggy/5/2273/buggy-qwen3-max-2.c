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
    printf("%d %d ",head3->next->t,head3->next->n); @@ [This line causes duplicate printing of the last term. The outer loop already prints all terms by extracting max each time, so this extra print outputs the leftover (already printed or invalid) term again. Additionally, the sorting/deletion logic is flawed and may leave dangling pointers or incorrect state.]
    return 0; 
}