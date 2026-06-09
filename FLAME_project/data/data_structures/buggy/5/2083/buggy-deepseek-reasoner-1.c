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
    scanf("%d%d%c",&a,&n,&c); // @@ The first term of the second polynomial is read here but never used because it is overwritten by the subsequent scanf.
    do{
        scanf("%d%d%c",&a,&n,&c); // @@ This scanf overwrites the first term of the second polynomial, causing that term to be lost.
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
        
    
            
        
    
        for(pp=head;pp!=NULL;p0=pp,pp=pp->next){
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
        
        if(pp==NULL)p0->next=z;
    }
            
        }
            
        }
            
    }while(c!='\n');
    
     for(pp=headd; pp!=NULL; pp=pp->next)
         printf("%d %d ", pp->coe,pp->pow);

    
    
    
}