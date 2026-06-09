#include<stdio.h>
#include<stdlib.h>
struct Node{
    int coe;
    int pow;
    struct Node *next;
};
int main()
{
    int n;
    struct Node *ah , *bh , *ch , *a , *b , *c , *q , *p , *r;
    ah=NULL;
    bh=NULL;
    ch=NULL;
    scanf("%d" , &n);
    while(n!=0){
        q=(struct Node*)malloc(sizeof(struct Node));
        q->next=NULL;
            q->coe=n;
        scanf("%d" , &n);
            q->pow=n;
            if(ah==NULL){
                ah=q;
                a=q;    
            }
            else{
                a->next=q;
                a=a->next;
            }
        if(n!=0) scanf("%d" , &n);
    }
    scanf("%d" , &n);
    while(n!=0){
        q=(struct Node*)malloc(sizeof(struct Node));
        q->next=NULL;
            q->coe=n;
        scanf("%d" , &n);
            q->pow=n;
            if(bh==NULL){
                bh=q;
                b=q;    
            }
            else{
                b->next=q;
                b=b->next;    
            }
        if(n!=0) scanf("%d" , &n);
    }
    while(ah!=NULL){
        p=bh;
        while(p!=NULL){
            q=(struct Node*)malloc(sizeof(struct Node));
            q->next=NULL;
            q->coe=(ah->coe)*(p->coe); // @@ If the product of coefficients is 0, a zero-coefficient term is still created and inserted, which violates standard polynomial output requirements.
            q->pow=ah->pow+p->pow;
            if(ch==NULL){
                ch=q;    
            }
            else if(ch->pow<q->pow){
                q->next=ch;
                ch=q;
            }
            else{
                c=ch;
                while(c->next!=NULL && c->pow>q->pow){ // @@ r is used later in the code but is not initialized here; if the loop does not execute, r remains uninitialized, leading to undefined behavior when r->next is accessed.
                    r=c;
                    c=c->next;
                }
                if(c->pow==q->pow){
                    c->coe=c->coe+q->coe; // @@ Memory leak: q is not freed after merging coefficients. Additionally, if c->coe becomes 0 after addition, the term should be removed from the list.
                }
                else if(c->pow<q->pow){
                    q->next=c;
                    r->next=q;
                }
                else if(c->next==NULL){
                    if(c->pow>q->pow){
                        c->next=q;
                    }
                }
            }
            p=p->next;
        }
        ah=ah->next;    
    }    
    while(ch!=NULL){
        printf("%d %d " , ch->coe , ch->pow);
        ch=ch->next;
    }
    return 0;
 }