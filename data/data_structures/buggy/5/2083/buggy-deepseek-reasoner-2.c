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
    scanf("%d%d%c",&a,&n,&c); // @@ Error: First term of second polynomial is read but not processed; it is lost when the next scanf overwrites variables.
    do{
        scanf("%d%d%c",&a,&n,&c); // @@ Error: This overwrites the first term's values, causing the first polynomial term to be ignored entirely.
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
        
    
            
        
    
        for(pp=head;pp!=NULL;p0=pp,pp=pp->next){ // @@ Error: Should iterate over headd (the result list) instead of head (first polynomial). Also p0 is uninitialized on first iteration.
            if(z->pow >pp->pow  ){
                if(pp==headd){
                    z->next =headd;
                    headd=z;
                    break;
                }
                else{
                    z->next =pp;
                    p0->next =z; // @@ Error: p0 is not guaranteed to be valid on the first iteration (when pp == headd and headd is not NULL, p0 is garbage).
                    break;
                }
            }
            else if(z->pow ==pp->pow ){
                pp->coe +=z->coe ;
                break;
            }
        
        if(pp==NULL)p0->next=z; // @@ Error: This condition is never true inside the loop; also p0 may be invalid. The node should be appended after the loop.
    }
            
        }
            
        }
            
    }while(c!='\n');
    
     for(pp=headd; pp!=NULL; pp=pp->next)
         printf("%d %d ", pp->coe,pp->pow);

    
    
    
}