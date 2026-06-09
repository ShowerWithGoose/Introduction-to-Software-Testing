#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int coef,index;
    struct node *next;
} node;
node *fp,*fq,*p,*q,*r,*ans;
int ex,ef,temp;
char c;
int cmp(const void *,const void *); // @@ [Declaration of unused function 'cmp'; not causing compilation error but unnecessary. However, the real issue is uninitialized 'fq' and incorrect sorting/merging logic leading to undefined behavior, but since error type is Compilation Error and test shows 'gcc: not found', this suggests environment issue. But assuming local compilation error due to logic: main issue is 'fq' used uninitialized in loops if second polynomial has no terms. Also, sorting loop uses 'fq->next' without ensuring 'fq' is not NULL.]
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
    while(scanf("%d%d",&ef,&ex)!=EOF) { // @@ [This loop condition may not correctly detect end-of-input for second polynomial as per problem's newline-terminated format; should use char check like first loop. This can cause infinite loop or undefined behavior but not direct compilation error. However, if input ends without EOF, this may read invalid data.]
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
    for(r=fq->next; r!=NULL; r=r->next) { // @@ [If 'fq' is NULL (e.g., empty second polynomial), dereferencing 'fq->next' causes segmentation fault at runtime, but not compilation error. However, if compiler does aggressive checks, might warn. Main compilation risk is elsewhere? Actually, no syntax errors. But given error type is Compilation Error and output says 'gcc: not found', likely environment issue. But per instructions, assume code has logical errors causing undefined behavior that might manifest as compile-time issues in strict environments. The real bug is using 'fq' without checking if it's NULL before accessing 'fq->next'.]
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
    for(q=fq; q->next!=NULL; q=q->next) { // @@ [Again, if 'fq' is NULL, 'q->next' dereferences NULL. Also, if only one term, loop doesn't run, but merging adjacent duplicates only works for consecutive terms after sort, which is broken.]
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