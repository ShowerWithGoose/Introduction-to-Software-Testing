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
    for(r=fq->next; r!=NULL; r=r->next) {
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
    for(q=fq; q->next!=NULL; q=q->next) { // @@ The merging loop only iterates once and fails to handle consecutive terms with the same exponent or re-check after a merge. It should be a while loop or restart from head when a merge occurs. Specifically, if q->next is removed, the new q->next might also have the same index, but q increments, skipping the check. Also, if the first two match, it merges, but if the third also matches, it won't be caught in this single pass correctly if not sorted/merged iteratively. More critically, if q->coef becomes 0 after addition, it should ideally be removed, but the problem says non-zero terms in input, output usually implies non-zero too. However, the main issue is that this single forward pass doesn't fully consolidate all like terms if there are more than 2 identical exponents scattered or adjacent after sort. Wait, after sorting, identical exponents are adjacent. A single pass *should* work for adjacent duplicates IF we don't advance q when we merge. But here q advances unconditionally in the for loop update. If we merge q and q->next, we remove q->next. The new q->next is the old next->next. We should check q against the NEW q->next again. But the for loop does q=q->next. So we skip checking the current q against the new neighbor. This leads to missed merges.
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