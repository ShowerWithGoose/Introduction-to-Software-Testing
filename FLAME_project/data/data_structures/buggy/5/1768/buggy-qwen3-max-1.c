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
    for(r=fq->next; r!=NULL; r=r->next) { // @@ [The sorting algorithm is incorrect: it uses a non-standard and logically flawed bubble sort that compares each element with all others in a way that doesn't guarantee correct ordering. This leads to terms not being sorted in strictly descending order of exponents, which affects the subsequent merging of like terms.]
        for(q=fq; q->next!=NULL; q=q->next) {
            if(r->index>q->next->index) { // @@ [This comparison logic is part of the flawed sorting: it compares a fixed 'r' (from outer loop) with 'q->next', but 'r' is not being updated correctly within inner loop, leading to inconsistent swaps and incorrect final order.]
                temp=r->index;
                r->index=q->next->index;
                q->next->index=temp;
                temp=r->coef;
                r->coef=q->next->coef;
                q->next->coef=temp;
            }
        }
    }
    for(q=fq; q->next!=NULL; q=q->next) { // @@ [Because the list is not properly sorted in descending order before this step, adjacent like terms may not be consecutive, causing some terms with same exponent to remain unmerged. For example, two terms with exponent 26 appear non-consecutively and only one gets merged, leading to "145 26" + "12 26" = "157 26" missing in output (instead showing both separately as "145 26" and "12 26").]
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