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
        for(p3=head3;p3!=NULL;p0=p3,p3=p3->link) // @@ This loop incorrectly uses p3 as both the loop variable and the traversal pointer, and the logic for sorting/combining terms is flawed. It does not properly insert or combine terms in descending order of exponents; it only appends terms without sorting or merging like terms.
        {
            if(q3->pow > p3->pow) // @@ q3 is used here but it points to the last allocated node from the previous loop, not the current node being processed. This comparison is meaningless for sorting the entire list.
            {
                if(p3==head3)
                {
                    q3->link=head3;
                    head3=q3;
                    break;
                }
                else
                {
                    q3->link=p3;
                    p0->link=q3;
                }
            }
            else if(q3->pow==p3->pow)
            {
                p3->coe += q3->coe; // @@ This adds the coefficient of the last node (q3) to the current node, which is incorrect. It should combine terms with the same exponent from the product list, not use q3.
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