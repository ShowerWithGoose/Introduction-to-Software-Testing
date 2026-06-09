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
    scanf("%d%d%c",&a,&n,&c); // @@ [This scanf reads the first term of the second polynomial but does not handle the case where the second polynomial has only one term. If the second polynomial has only one term, the following do-while loop will not execute because it checks `c != '\n'` after this initial read, but the loop condition is at the end. Thus, single-term second polynomials are never processed beyond this point.]
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
        
    
            
        
    
        for(pp=headd;pp!=NULL;p0=pp,pp=pp->next){ // @@ [The loop variable `pp` is reused from outer scope and also used as traversal pointer here, but `p0` is not initialized before the loop. If the list is empty or insertion happens at head, `p0` may be uninitialized when used in `p0->next = z;` later. Also, note that the loop condition uses `headd`, but inside the loop we compare with `headd` again — however, the real issue is that `p0` is not initialized before the loop starts, leading to undefined behavior when `pp != headd` and we reach the end (`pp == NULL`).]
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
                free(z); // @@ [Missing free(z) here leads to memory leak, but more critically, the program continues using `z` after this point in the next iteration. However, the immediate logical error is that after merging same-power terms, the allocated node `z` should be freed to avoid memory leaks, but the bigger issue is that the logic assumes all cases are handled, yet if no break occurs (e.g., due to traversal issues), it may fall through incorrectly. But the critical bug is below:]
                break;
            }
        
        if(pp==NULL)p0->next=z; // @@ [This line is inside the for-loop body but after the if-else block. It should be outside the for-loop. As written, it executes on every iteration where the conditions above don't break, which is incorrect. It should only execute if the entire loop completes without finding a matching or larger exponent. Additionally, `p0` might be uninitialized if the list was empty or if the loop never ran.]
    }
            
        }
            
        }
            
    }while(c!='\n'); // @@ [This loop never runs if the second polynomial has only one term because the first term of the second polynomial is read before the loop, and if that term ends with '\n', then c=='\n' and the loop condition fails. Hence, single-term second polynomials result in only partial processing (only the first term read before the loop), but the multiplication result is never built correctly because the do-while loop doesn't run even once for k=1 handling inside. Actually, the k=1 block is inside the loop, so if the loop doesn't run, k remains 0 and the multiplication result (headd) is never initialized. This causes undefined behavior when printing.]
    
     for(pp=headd; pp!=NULL; pp=pp->next)
         printf("%d %d ", pp->coe,pp->pow); // @@ [If the second polynomial has only one term, headd remains NULL because the do-while loop never runs, so nothing is printed. Also, if there are zero terms in either polynomial (though problem states non-zero terms), but more importantly, the logic fails to handle the first term of the second polynomial correctly.]

    
    
    
}