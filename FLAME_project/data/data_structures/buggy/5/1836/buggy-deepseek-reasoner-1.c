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
    scanf("%d" , &n); // @@ [The program incorrectly assumes polynomial ends with a zero exponent. Input termination is by newline, not by exponent 0.]
    while(n!=0){ // @@ [This loop condition never false for given large exponent (1000000000). Should read until newline instead.]
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
        if(n!=0) scanf("%d" , &n); // @@ [After reading exponent, this extra scanf waits for next coefficient. Since input line ends, program hangs.]
    }
    scanf("%d" , &n); // @@ [Same issue: assumes polynomial is terminated by zero exponent.]
    while(n!=0){ // @@ [Same infinite loop for large exponent in second polynomial.]
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
        if(n!=0) scanf("%d" , &n); // @@ [Same hang issue: expects more input but none exists.]
    }
    while(ah!=NULL){
        p=bh;
        while(p!=NULL){
            q=(struct Node*)malloc(sizeof(struct Node));
            q->next=NULL;
            q->coe=(ah->coe)*(p->coe);
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
                while(c->next!=NULL && c->pow>q->pow){
                    r=c;
                    c=c->next;
                }
                if(c->pow==q->pow){
                    c->coe=c->coe+q->coe;
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