#include<stdio.h>
#include<stdlib.h>

struct Node{
    int coe;
    int pow;
    struct Node *next;
};

int main()
{
    int a,n;
    char c;
    struct Node *head,*p,*q,*p0;
    struct Node *head2,*p2,*q2,*p02;
    head=p=head2=p2=NULL;
    do{
        scanf("%d%d%c",&a,&n,&c);
        q=(struct Node*)malloc(sizeof(struct Node));
        q->coe=a;q->pow=n;q->next=NULL;
        if(head==NULL)
        {
            head=p=q;
        }
        else
        {
            p->next=q;
            p=p->next;
        }
    }while(c!='\n');
    
    
        scanf("%d%d%c",&a,&n,&c); // @@ This line reads the first term of the second polynomial but does not store it in a linked list; it only updates a and n for the subsequent loop, which incorrectly multiplies the first polynomial by this term's coefficient and exponent.
        ;
        //q->coe=a;q->pow=n;q->next=NULL;
        for(p=head;p!=NULL;p0=p,p=p->next) // @@ The variable p0 is used but never initialized before the loop; it is intended to track the previous node but is not properly managed, leading to potential undefined behavior.
        {
            q2=(struct Node*)malloc(sizeof(struct Node));
            q2->next=NULL;
            q2->coe=(p->coe)*a;
            q2->pow=(p->pow)+n;
            if(head2==NULL)
            {
                head2=p2=q2;
            }
            else
            {
                p2->next=q2;
                p2=p2->next;
            }
        }
        
    do{
        scanf("%d%d%c",&a,&n,&c);
        
        for(p=head;p!=NULL;p0=p,p=p->next) // @@ Same issue: p0 is used without proper initialization and management; the loop condition and update are flawed, causing incorrect traversal.
        {
            q2=(struct Node*)malloc(sizeof(struct Node));
            q2->next=NULL;
            q2->coe=(p->coe)*a;
            q2->pow=(p->pow)+n;
            for(p2=head2;p2!=NULL;p02=p2,p2=p2->next) // @@ p02 is used to track the previous node but is not initialized before the loop; when inserting at the beginning, p02 may be uninitialized, causing a segmentation fault or incorrect linking.
            {
                if(q2->pow>p2->pow)
                {
                    q2->next=p2;
                    p02->next=q2; // @@ If p2 is the first node (head2), p02 is NULL, causing a null pointer dereference; the code does not handle insertion at the head of the list.
                    break;
                }
                else if(q2->pow==p2->pow){
                    p2->coe+=q2->coe;
                    free(q2);
                    break;
                }
                
            }
            if(p2==NULL){
                p02->next=q2; // @@ If the loop ends because p2 becomes NULL, p02 points to the last node, but if the list is empty (head2 is NULL), p02 is uninitialized, causing undefined behavior.
            }
        
        
        }
    }while(c!='\n');
    
    for(p2=head2;p2!=NULL;p2=p2->next)
    {
        printf("%d %d ",p2->coe,p2->pow);
    }
    
    
    
    
    
    return 0;
}