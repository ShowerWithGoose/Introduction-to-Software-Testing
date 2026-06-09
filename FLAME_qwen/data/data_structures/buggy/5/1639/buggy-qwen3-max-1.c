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
        ; // @@ [This semicolon creates an empty statement and the following block is not part of any conditional or loop, leading to incorrect logic flow. Also, this scanf reads the first term of the second polynomial but is outside any loop, causing the rest of the second polynomial to be read in a separate do-while that assumes more terms exist.]
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
        
    do{ // @@ [This do-while loop will always execute at least once, even if the second polynomial has only one term (i.e., after the initial scanf above). This causes re-reading input beyond what's available, leading to undefined behavior or incorrect parsing. The logic for reading the second polynomial is flawed because it reads the first term outside the loop and then tries to read more terms unconditionally.]
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
                    p02->next=q2; // @@ [When inserting at the head of the list (i.e., when q2->pow > head2->pow), p02 is uninitialized because the loop starts with p2=head2 and p02 is only set inside the loop body during iteration. Thus, if insertion happens before the first node, p02 is used uninitialized, leading to undefined behavior.]
                    break;
                }
                else if(q2->pow==p2->pow){
                    p2->coe+=q2->coe;
                    free(q2);
                    break;
                }
                
            }
            if(p2==NULL){
                p02->next=q2; // @@ [If head2 was NULL initially (which shouldn't happen here due to prior initialization), or if the loop never ran, p02 would be uninitialized. But more critically, if the inner for-loop runs to completion (p2 becomes NULL), p02 points to the last node, so this line is correct in that scenario. However, combined with the earlier uninitialized p02 issue during head insertion, this contributes to instability.]
            }
        
        
        }
    }while(c!='\n');
    
    for(p2=head2;p2!=NULL;p2=p2->next)
    {
        printf("%d %d ",p2->coe,p2->pow);
    }
    
    
    
    
    
    return 0;
}