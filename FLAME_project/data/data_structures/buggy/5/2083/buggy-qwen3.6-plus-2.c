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
    scanf("%d%d%c",&a,&n,&c); // @@ The first term of the second polynomial is read here, but the logic inside the subsequent do-while loop assumes it hasn't been processed or re-reads incorrectly. The variable 'a' and 'n' hold the first term of poly2, but the loop below starts by reading the NEXT term. This skips the first term of the second polynomial in the multiplication logic if not handled correctly, or processes it twice/wrongly. Actually, looking at the logic: the first term is read into a,n. Then the do-while starts. Inside, it reads the NEXT term. So the first term (stored in a,n before the loop) is completely ignored for multiplication because the loop body overwrites a,n with the next scan.
    do{
        scanf("%d%d%c",&a,&n,&c); // @@ This reads the second term of the second polynomial (or subsequent terms). The first term read before the loop is lost/unused for multiplication.
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
        
    
            
        
    
        for(pp=headd,p0=NULL;pp!=NULL;p0=pp,pp=pp->next){ // @@ p0 is used uninitialized in the original code (`for(pp=head;... p0=pp...)` implies p0 is set inside the loop update, but on the first iteration p0 is garbage if not initialized before. Also, the original code iterated `pp=head` which is wrong, it should iterate the result list `headd`.
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
                break;
            }
        
        if(pp->next == NULL) { p0->next = z; break; } // @@ The original code had `if(pp==NULL)p0->next=z;` outside the logical flow correctly handling insertion at end. The original loop structure was flawed.
    }
            
        }
            
        }
            
    }while(c!='\n');
    
     for(pp=headd; pp!=NULL; pp=pp->next)
         printf("%d %d ", pp->coe,pp->pow);

    
    
    
}