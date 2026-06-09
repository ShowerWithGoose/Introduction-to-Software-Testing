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
        // The original code attempts to sort/merge the list after building it linearly, 
        // but the logic is flawed. It iterates through the list using p3, but compares 
        // against q3 (which is the last node added) instead of inserting nodes properly 
        // during construction or performing a proper sort/merge afterwards.
        // Specifically, this loop only runs once effectively because of the break statements,
        // and it tries to insert 'q3' (the very last term generated) into the list, 
        // ignoring all other terms that might need merging or reordering.
        // The correct approach is to either insert each new term (q3) into the correct 
        // position in head3 immediately inside the multiplication loops, or to build 
        // the list and then sort/merge it properly.
        // Given the structure, the error is that the sorting/merging logic is outside 
        // the multiplication loops and incorrectly references q3.
        for(p3=head3;p3!=NULL;p0=p3,p3=p3->link) // @@ [The sorting/merging logic is incorrect. It should be performed during insertion or as a separate complete pass. Currently, it only processes the last generated term 'q3' against the list, failing to merge like terms or sort the entire list correctly.]
        {
            if(q3->pow > p3->pow)
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
                p3->coe += q3->coe;
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