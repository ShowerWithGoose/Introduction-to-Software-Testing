#include <stdio.h>
#define M 5005
struct node {
    int x,y;
    struct node *nxt;
};
struct node *Wordlist=NULL;
struct node *p;
struct node *t;

int n;
char s[M];
int insert(int x,int y){
    struct node *q;
    q=(struct node *)malloc(sizeof(struct node));
    q->nxt=NULL;
    q->x=x,q->y=y;
    if(Wordlist==NULL){Wordlist=q;return 0;}
    for(p=Wordlist,t=NULL;p!=NULL;t=p,p=p->nxt){
        if(p->y==y){p->x+=x;return 0;}
        if(p->y<y)break;
    }
    t->nxt=q,q->nxt=p; // @@ [Error: If `t` is NULL (when inserting before the first node), this line dereferences a null pointer, causing a segmentation fault. Also, when the loop ends because `p` is NULL (no node with smaller exponent), the appending logic is missing a check for `t` being NULL. Additionally, the function does not handle the case where `p` becomes NULL after the loop – it should append at the end, but the current code attempts to set `t->nxt=q` only when `t` is not NULL, and after `break` due to `p->y<y`, `t` may be NULL. The logic is flawed and does not correctly insert in all cases.]
    return 0;
}
int A[M],B[M],C[M],D[M];
int l,r;
int main(){
//    freopen("article.txt","r",stdin);
    while(scanf("%d %d",&A[l],&B[l])&&B[l]!=0)l++; // @@ [Error: The condition `B[l]!=0` treats exponent 0 as termination, but exponent 0 is valid (constant term). This will prematurely stop reading the first polynomial if a term has exponent 0. Also, it does not properly handle the newline that marks the end of input. The intended input ends with a newline, not a zero exponent.]
    while(scanf("%d %d",&C[r],&D[r])&&D[r]!=0)r++; // @@ [Error: Same issue as above for the second polynomial.]
    for(int i=0;i<=l;i++)printf("A:%d %d\n",A[i],B[i]); // @@ [Error: This debug output prints extra lines not required by the problem specification. The output should only contain the multiplied polynomial terms.]
    for(int i=0;i<=r;i++)printf("B:%d %d\n",C[i],D[i]); // @@ [Error: Same debug output error for the second polynomial.]
    
    for(int i=0;i<=l;i++)for(int j=0;j<=r;j++){ // @@ [Error: The loop conditions `i<=l` and `j<=r` cause off-by-one errors. After reading, `l` and `r` represent the number of terms read (since they are incremented after each successful scanf), so the valid indices are 0 to l-1 and 0 to r-1. Using `<=` accesses uninitialized array elements, leading to undefined behavior and incorrect multiplication.]
        insert(A[i]*C[j],B[i]+D[j]);
    }
    for(p=Wordlist;p!=NULL;p=p->nxt)if(p->x!=0)printf("%d %d ",p->x,p->y);
    return 0;
}