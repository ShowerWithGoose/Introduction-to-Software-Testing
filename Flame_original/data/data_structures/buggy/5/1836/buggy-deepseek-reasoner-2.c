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
        if(n!=0) scanf("%d" , &n); // @@ [Logic: Relies on coefficient being non-zero and exponent determining continuation; may not correctly parse all input sequences, but works for the specified format]
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
        if(n!=0) scanf("%d" , &n); // @@ [Same logic issue as first polynomial reading]
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
                while(c->next!=NULL && c->pow>q->pow){ // @@ [If condition fails immediately (e.g., single node with c->pow >= q->pow), 'r' is left uninitialized]
                    r=c;
                    c=c->next;
                }
                if(c->pow==q->pow){
                    c->coe=c->coe+q->coe; // @@ [Should check if coefficient becomes zero and remove the node; otherwise, zero‑coefficient terms appear in output]
                }
                else if(c->pow<q->pow){
                    q->next=c;
                    r->next=q; // @@ [Potential use of uninitialized 'r' when while‑loop did not execute]
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