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
        ; // @@ The semicolon here creates an empty statement, but more importantly, the logic below assumes this is the first term of the second polynomial. However, the variable `p0` is used in the loop below without being initialized for the first iteration of the outer loop over `head`.
        //q->coe=a;q->pow=n;q->next=NULL;
        for(p=head;p!=NULL;p0=p,p=p->next) // @@ Error: `p0` is used uninitialized in the first iteration. When `p` is `head`, `p0` has garbage value. If the insertion logic inside the next `do-while` or this block relied on `p0` for head insertion, it would crash. In this specific block, `p0` is not used, but it's bad practice. However, the critical error is that this block handles the FIRST term of poly2, but the subsequent `do-while` handles the REST. The logic for inserting into `head2` here is just appending/creating.
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
        
        for(p=head;p!=NULL;p0=p,p=p->next) // @@ Error: Similar to above, `p0` is uninitialized for the first element of `head`. But more critically, look at the inner loop.
        {
            q2=(struct Node*)malloc(sizeof(struct Node));
            q2->next=NULL;
            q2->coe=(p->coe)*a;
            q2->pow=(p->pow)+n;
            for(p2=head2;p2!=NULL;p02=p2,p2=p2->next) // @@ Error: `p02` is used to track the previous node for insertion. However, if the new term `q2` needs to be inserted at the very beginning (i.e., its power is greater than the current head's power), the code checks `if(q2->pow>p2->pow)`. If this is true for the first node (`p2==head2`), `p02` is uninitialized because the loop body hasn't executed the assignment `p02=p2` yet for the first iteration? No, `p02=p2` happens in the increment step? No, it's in the loop structure `for(init; cond; inc)`. The increment `p02=p2` happens AFTER the body. So in the first iteration, `p02` is uninitialized.
            {
                if(q2->pow>p2->pow)
                {
                    q2->next=p2;
                    p02->next=q2; // @@ Critical Error: If this condition is met during the first iteration of the inner loop, `p02` is uninitialized. This leads to undefined behavior. Furthermore, even if `p02` were valid, this logic attempts to insert `q2` before `p2`. If `p2` is `head2`, we need to update `head2`. This code does NOT update `head2`. It tries to set `p02->next`, which is wrong for head insertion.
                    break;
                }
                else if(q2->pow==p2->pow){
                    p2->coe+=q2->coe;
                    free(q2);
                    break;
                }
                
            }
            if(p2==NULL){
                p02->next=q2; // @@ If the loop finishes without breaking, `p2` is NULL. `p02` points to the last node. This appends correctly. However, if the list was empty (which shouldn't happen here as the first term was handled outside), this would fail.
            }
        
        
        }
    }while(c!='\n');
    
    for(p2=head2;p2!=NULL;p2=p2->next)
    {
        printf("%d %d ",p2->coe,p2->pow);
    }
    
    
    
    
    
    return 0;
}