#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int coef,index;
    struct node *next;
} node;
node *fp,*fq,*p,*q,*r,*ans;
int ex,ef,temp;
char c;
int cmp(const void *,const void *);
int main() {
    fp=r=NULL; // @@ Missing initialization for fq. Should be `fq = NULL` to avoid using uninitialized pointer.
    do {
        scanf("%d%d%c",&ef,&ex,&c);
        p=(node*)malloc(sizeof(node));
        p->coef=ef;
        p->index=ex;
        p->next=NULL;
        if(fp==NULL)
            fp=r=p;
        else {
            r->next=p;
            r=r->next;
        }
    } while(c!='\n');
    while(scanf("%d%d",&ef,&ex)!=EOF) { // @@ Input loop does not handle newline correctly; may cause infinite loop or miss second polynomial.
        for(p=fp; p!=NULL; p=p->next) {
            q=(node*)malloc(sizeof(node));
            q->coef=(p->coef)*ef;
            q->index=(p->index)+ex;
            q->next=NULL;
            if(fq==NULL) // @@ fq is uninitialized; this condition uses undefined value.
                fq=r=q;
            else {
                r->next=q; // @@ If fq was not NULL due to garbage, r still points to the first polynomial list, corrupting it.
                r=r->next;
            }
        }
    }
    for(r=fq->next; r!=NULL; r=r->next) { // @@ fq may be NULL, causing dereference of NULL pointer.
        for(q=fq; q->next!=NULL; q=q->next) {
            if(r->index>q->next->index) {
                temp=r->index;
                r->index=q->next->index;
                q->next->index=temp;
                temp=r->coef;
                r->coef=q->next->coef;
                q->next->coef=temp;
            }
        }
    } // @@ The sorting logic is flawed; does not guarantee descending order.
    for(q=fq; q->next!=NULL; q=q->next) { // @@ May crash if fq is NULL.
        if(q->index==q->next->index) {
            q->coef+=q->next->coef;
            r=q->next;
            q->next=r->next;
            free(r);
        }
    } // @@ Zero coefficients after combination are not removed; they should be.
    for(q=fq; q!=NULL; q=q->next) { // @@ May crash if fq is NULL.
        printf("%d %d ",q->coef,q->index);
    }
    return 0;
}