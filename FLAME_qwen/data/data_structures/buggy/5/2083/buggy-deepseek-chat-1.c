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
    scanf("%d%d%c",&a,&n,&c); // @@ This line reads the first term of the second polynomial but does not process it as part of the multiplication loop; it only reads it and then enters the do-while loop which starts with the next term, causing the first term of the second polynomial to be skipped.
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
        
    
            
        
    
        for(pp=head;pp!=NULL;p0=pp,pp=pp->next){ // @@ The loop condition uses pp!=NULL but the loop body modifies pp and p0 incorrectly; also, the variable p0 is used uninitialized when pp==headd, and the logic for inserting in descending order is flawed because the loop iterates over head (first polynomial) instead of headd (result polynomial).
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
        
        if(pp==NULL)p0->next=z; // @@ This line is inside the for loop but after the loop body; it will never be reached because the loop condition checks pp!=NULL, so pp==NULL is false inside the loop. This should be placed after the loop to handle the case where z is inserted at the end.
    }
            
        }
            
        }
            
    }while(c!='\n');
    
     for(pp=headd; pp!=NULL; pp=pp->next)
         printf("%d %d ", pp->coe,pp->pow);

    
    
    
}