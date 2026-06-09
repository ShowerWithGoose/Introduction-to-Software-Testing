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
    scanf("%d" , &n); // @@ This assumes input starts with a single integer; the problem expects pairs of coefficients and exponents ending with newline. Also, n is used as both coefficient and exponent, and the loop termination condition (n!=0) is incorrect because exponent can be 0.
    while(n!=0){ // @@ The condition should be based on end-of-input, not n!=0. The polynomial terms may have coefficient 0? Problem says only non-zero coefficients, but exponent 0 is allowed. Using n!=0 will incorrectly terminate when a coefficient is 0, but coefficient 0 never appears. However, the exponent for constant term is 0, so after reading exponent 0, n becomes 0, and the loop exits prematurely.
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
        if(n!=0) scanf("%d" , &n); // @@ This attempts to read the next coefficient only if exponent is non-zero, which is wrong. For constant term (exponent 0), n becomes 0, so the next coefficient is not read, breaking the input sequence.
    }
    scanf("%d" , &n); // @@ Same issue: reads an integer for the second polynomial, but the input format does not guarantee a leading integer separate from the coefficient.
    while(n!=0){ // @@ Same termination error as first polynomial.
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
        if(n!=0) scanf("%d" , &n); // @@ Same error: skips the next coefficient if exponent is 0.
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
                    r->next=q; // @@ r may be uninitialized if the while loop never executed (e.g., when c->pow <= q->pow at the start). This leads to undefined behavior.
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