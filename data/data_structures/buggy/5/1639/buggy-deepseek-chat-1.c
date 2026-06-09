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
    
    
        scanf("%d%d%c",&a,&n,&c);
        ;
        //q->coe=a;q->pow=n;q->next=NULL;
        for(p=head;p!=NULL;p0=p,p=p->next)
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
        
        for(p=head;p!=NULL;p0=p,p=p->next)
        {
            q2=(struct Node*)malloc(sizeof(struct Node));
            q2->next=NULL;
            q2->coe=(p->coe)*a;
            q2->pow=(p->pow)+n;
            for(p2=head2;p2!=NULL;p02=p2,p2=p2->next)
            {
                if(q2->pow>p2->pow)
                {
                    q2->next=p2;
                    p02->next=q2; // @@ Error: When inserting at the beginning (p2 == head2), p02 is not properly initialized, leading to incorrect pointer manipulation. Additionally, after insertion, the loop should break, but the pointer p2 is not updated correctly for subsequent iterations.
                    break;
                }
                else if(q2->pow==p2->pow){
                    p2->coe+=q2->coe;
                    free(q2);
                    break;
                }
                
            }
            if(p2==NULL){
                p02->next=q2; // @@ Error: When p2 becomes NULL after traversing the list, p02 points to the last node, but q2 is not properly linked (its next is NULL), and this insertion does not handle the case where the list is empty (head2 == NULL) correctly.
            }
        
        
        }
    }while(c!='\n');
    
    for(p2=head2;p2!=NULL;p2=p2->next)
    {
        printf("%d %d ",p2->coe,p2->pow);
    }
    
    
    
    
    
    return 0;
}