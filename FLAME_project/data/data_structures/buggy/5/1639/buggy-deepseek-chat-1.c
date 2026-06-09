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
    
    
        scanf("%d%d%c",&a,&n,&c); // @@ This line reads the first term of the second polynomial but does not store it in a linked list; it only uses it for multiplication. However, the subsequent loop for reading additional terms (the do-while loop below) will also read the first term again if there are multiple terms, causing incorrect processing. For a single-term polynomial, this works, but the logic is flawed for multi-term inputs.
        ;
        //q->coe=a;q->pow=n;q->next=NULL;
        for(p=head;p!=NULL;p0=p,p=p->next) // @@ The variable p0 is used but not initialized properly; in the first iteration, p0 is uninitialized, which can cause undefined behavior when used later (e.g., in the insertion logic). Additionally, the loop condition and update are incorrect: p0=p is executed before p=p->next, but p0 is not used correctly in the subsequent insertion code.
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
        
        for(p=head;p!=NULL;p0=p,p=p->next) // @@ Same issue as above: p0 is used uninitialized in the first iteration, and the loop structure is incorrect for tracking the previous node.
        {
            q2=(struct Node*)malloc(sizeof(struct Node));
            q2->next=NULL;
            q2->coe=(p->coe)*a;
            q2->pow=(p->pow)+n;
            for(p2=head2;p2!=NULL;p02=p2,p2=p2->next) // @@ p02 is used to track the previous node, but it is not initialized before the loop; in the first iteration, p02 is uninitialized, leading to undefined behavior when accessing p02->next.
            {
                if(q2->pow>p2->pow)
                {
                    q2->next=p2;
                    p02->next=q2; // @@ When inserting at the beginning (p2 == head2), p02 is not the previous node; this line incorrectly modifies a node that may not exist or is wrong, causing the linked list to be corrupted.
                    break;
                }
                else if(q2->pow==p2->pow){
                    p2->coe+=q2->coe;
                    free(q2);
                    break;
                }
                
            }
            if(p2==NULL){
                p02->next=q2; // @@ If the loop ends because p2 becomes NULL, p02 points to the last node, but if the list is empty (head2 == NULL), p02 is uninitialized, causing undefined behavior.
            }
        
        
        }
    }while(c!='\n');
    
    for(p2=head2;p2!=NULL;p2=p2->next)
    {
        printf("%d %d ",p2->coe,p2->pow);
    }
    
    
    
    
    
    return 0;
}