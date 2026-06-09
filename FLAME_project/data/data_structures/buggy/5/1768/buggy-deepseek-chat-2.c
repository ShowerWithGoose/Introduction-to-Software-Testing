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
    fp=r=NULL;
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
    while(scanf("%d%d",&ef,&ex)!=EOF) {
        for(p=fp; p!=NULL; p=p->next) {
            q=(node*)malloc(sizeof(node));
            q->coef=(p->coef)*ef;
            q->index=(p->index)+ex;
            q->next=NULL;
            if(fq==NULL)
                fq=r=q;
            else {
                r->next=q;
                r=r->next;
            }
        }
    }
    for(r=fq->next; r!=NULL; r=r->next) { // @@ The outer loop uses r to traverse, but the inner loop modifies the list structure (swapping nodes), which can cause r to point to wrong nodes or skip nodes, leading to incorrect sorting.
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
    }
    for(q=fq; q->next!=NULL; q=q->next) {
        if(q->index==q->next->index) {
            q->coef+=q->next->coef;
            r=q->next;
            q->next=r->next;
            free(r);
        }
    }
    for(q=fq; q!=NULL; q=q->next) {
        printf("%d %d ",q->coef,q->index);
    }
    return 0;
}