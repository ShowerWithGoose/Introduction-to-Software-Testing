#include <stdio.h>
#include <stdlib.h>
struct Node{
    int coe;
    int pow;
    struct Node *link;
};
typedef struct Node *Nodeptr;
typedef struct Node Node;
int main()
{
    struct Node *head1,*head2,*head3,*q1,*q2,*q3,*p0=NULL,*p1,*p2,*p3;
    head1=p1=NULL,head2=p2=NULL,head3=p3=NULL;
    int a,n;
    char c;
    do{
        scanf("%d%d%c",&a,&n,&c);
        q1=(Nodeptr)malloc(sizeof(Node));
        q1->coe=a;
        q1->pow=n;
        q1->link=NULL;
        if(head1==NULL)
        {
            head1=p1=q1;
        }
        else
        {
            p1->link=q1;
            p1=q1;
        }
    }while(c!='\n');
    do{
        scanf("%d%d%c",&a,&n,&c);
        q2=(Nodeptr)malloc(sizeof(Node));
        q2->coe=a;
        q2->pow=n;
        q2->link=NULL;
        if(head2==NULL)
        {
            head2=p2=q2;
        }
        else
        {
            p2->link=q2;
            p2=q2;
        }
    }while(c!='\n');
        for(p1=head1;p1!=NULL;p1=p1->link)
        {
            for(p2=head2;p2!=NULL;p2=p2->link)
            {
            q3=(Nodeptr)malloc(sizeof(Node));
            q3->coe=p1->coe*p2->coe;
            q3->pow=p1->pow+p2->pow;
            q3->link=NULL;
            if(head3==NULL)
        {
            head3=p3=q3;
        }
        else
        {
            p3->link=q3;
            p3=q3;
        }
            }
        }
        for(p3=head3;p3!=NULL;p0=p3,p3=p3->link) // @@ The loop only attempts to merge the last node (q3) and does not handle other duplicates; also insertion logic causes cycles.
        {
            if(q3->pow > p3->pow) // @@ Condition uses fixed q3 (last node) for all iterations, causing incorrect comparisons and attempting to insert q3 multiple times.
            {
                if(p3==head3)
                {
                    q3->link=head3; // @@ This creates a cycle by setting q3 (already in list) to point to head3 while its predecessor still points to it.
                    head3=q3; // @@ This changes head to q3, but q3's predecessor still points to old head, causing cycle.
                    break;
                }
                else
                {
                    q3->link=p3; // @@ This creates a cycle if p3 is after q3's predecessor.
                    p0->link=q3; // @@ p0 is the node before p3, q3 is already in list; this creates a cycle or duplicate.
                }
            }
            else if(q3->pow==p3->pow) // @@ Only merges last node, and does not remove q3, resulting in duplicate exponent nodes.
            {
                p3->coe += q3->coe; // @@ Adds coefficient but does not delete or unlink q3, leaving duplicate node.
                break;
            }
        }
        for(p3=head3;p3!=NULL;p3=p3->link)
        {
        printf("%d %d ",p3->coe,p3->pow);
        }
        printf("\n");
    return 0;
}