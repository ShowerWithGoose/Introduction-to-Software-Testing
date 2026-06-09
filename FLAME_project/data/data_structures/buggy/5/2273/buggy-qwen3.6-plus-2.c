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
    for(o=head3->next;o!=NULL;o=o->next) // @@ The loop condition and body are incorrect for selection sort. It iterates using 'o' but modifies the list structure inside, leading to skipped elements or infinite loops. Also, it prints inside the loop which disrupts the sorting logic if not careful, but the main issue is that it doesn't correctly sort all elements before printing or handle the list modification safely during iteration. Specifically, after removing the max element 'q', the next iteration should find the next max from the remaining list. However, the outer loop variable 'o' is not reset or managed correctly relative to the shrinking list. A standard selection sort would use a counter or check if the list is empty. Here, iterating with 'o' while removing nodes causes undefined behavior or missed nodes.
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
        free(q); // @@ Memory leak: the removed node 'q' should be freed.
        k=head3;u=k;q=head3->next;l=-1;
    }
    if(head3->next!=NULL) // @@ This condition is likely never true if the previous loop processed all nodes, or it prints the last remaining node if the loop logic was flawed. In a correct selection sort that prints and removes one node per iteration, the list should be empty after the loop. If the loop above is fixed to run exactly N times (where N is the number of nodes), this part is unnecessary. If the loop above is buggy, this might be an attempt to print the last node, but it's redundant or incorrect depending on the fix. Given the previous loop is intended to sort and print all nodes, this line is likely dead code or indicative of the sorting logic failure.
    printf("%d %d ",head3->next->t,head3->next->n);
    return 0; 
}