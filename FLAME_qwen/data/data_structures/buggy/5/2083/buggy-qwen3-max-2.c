#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int coe;
    int pow;
    struct Node *next;
};

int main() {
    int i=0,n,a,k=0,time=0;
    char c;
    struct Node *head,*p,*q,*p0,*headd,*qq,*pp,*x,*y,*z;
    head=p=q=NULL;
    headd=pp=qq=NULL;
    z=y=x=NULL;
    do{
        scanf("%d%d%c",&a,&n,&c);
    
        time++;
        q =  (struct Node *)malloc(sizeof(struct Node));
        q->coe = a; q->pow = n; q->next = NULL;
        if( head == NULL) 
             head = p = q;
       else {
            p->next = q;
            p = p->next;
       }

    }while(c!='\n');
    scanf("%d%d%c",&a,&n,&c); // @@ [This line reads the first term of the second polynomial but assumes there is at least one term. If the second polynomial is empty (which shouldn't happen per problem, but logic fails if input ends here), it causes issues. More critically, if the second polynomial has only one term, the following `do-while` loop won't execute because `c` might already be '\n', skipping multiplication entirely.]
    do{
        scanf("%d%d%c",&a,&n,&c);
        k++;
        if(k==1){

            p=head;
            for(int i=0;i<time;i++){
            qq =  (struct Node *)malloc(sizeof(struct Node));
        
            qq->coe =p->coe *a;
            qq->pow =p->pow +n;
            qq->next =NULL;
            p=p->next ;
            if(headd==NULL){
                headd=pp=qq;
            }
            else{
            
            pp->next =qq;
            pp=pp->next ;
        }
    }
    }
        else{

            p=head;
        for(i=0;i<time;i++){
        
        
            z =  (struct Node *)malloc(sizeof(struct Node));
            z->next =NULL;
            z->coe =p->coe *a;
            z->pow =p->pow +n;
        
            p=p->next ;
        
    
            
        
    
        for(pp=headd;pp!=NULL;p0=pp,pp=pp->next){ // @@ [The loop condition uses `pp=headd`, but `p0` is uninitialized when `pp==headd`. If insertion happens at the end (`pp==NULL`), `p0` may be used uninitialized, leading to undefined behavior. Also, the insertion logic doesn't handle the case where the new term has the smallest exponent correctly because `p0` isn't guaranteed to be set before the loop ends.]
            if(z->pow >pp->pow  ){
                if(pp==headd){
                    z->next =headd;
                    headd=z;
                    break;
                }
                else{
                    z->next =pp;
                    p0->next =z;
                    break;
                }
            }
            else if(z->pow ==pp->pow ){
                pp->coe +=z->coe ;
                free(z); // @@ [Missing `free(z)` here leads to memory leak, but more importantly, the program continues to use `z` after this point in the loop termination check, which is incorrect. However, the critical error is that after `break`, the code after the loop checks `if(pp==NULL)` and uses `p0`, but if we broke due to match or insertion, `pp` is not NULL, so it's skipped. But if no insertion happened (e.g., term should go at end), the loop exits with `pp==NULL`, but `p0` was never assigned in the first iteration if `headd` was NULL — but `headd` isn't NULL here because k>1. Still, the traversal logic is flawed.]
                break;
            }
        
        if(pp==NULL)p0->next=z; // @@ [This line is inside the for-loop, but it should be outside. As written, it executes on every iteration where `pp` hasn't become NULL yet, which is wrong. It should only run once after the loop if no insertion occurred. This misplaced line causes incorrect linking and potential crashes.]
    }
            
        }
            
        }
            
    }while(c!='\n');
    
     for(pp=headd; pp!=NULL; pp=pp->next)
         printf("%d %d ", pp->coe,pp->pow);

    
    
    
}