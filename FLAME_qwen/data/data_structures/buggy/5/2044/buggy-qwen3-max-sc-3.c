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
    q=(struct node *)malloc(sizeof(struct node)); // @@ [Missing #include <stdlib.h> for malloc]
    q->nxt=NULL;
    q->x=x,q->y=y;
    if(Wordlist==NULL){Wordlist=q;return 0;}
    for(p=Wordlist,t=NULL;p!=NULL;t=p,p=p->nxt){
        if(p->y==y){p->x+=x;return 0;}
        if(p->y<y)break;
    }
    t->nxt=q,q->nxt=p; // @@ [If Wordlist is not NULL but the loop breaks at first iteration (i.e., t is still NULL), then t->nxt is invalid dereference]
    return 0;
}
int A[M],B[M],C[M],D[M];
int l,r;
int main(){
//    freopen("article.txt","r",stdin);
    while(scanf("%d %d",&A[l],&B[l])&&B[l]!=0)l++; // @@ [Loop condition B[l]!=0 incorrectly stops when exponent is 0, but constant term (exponent 0) should be included; also l is uninitialized]
    while(scanf("%d %d",&C[r],&D[r])&&D[r]!=0)r++; // @@ [Same issue: D[r]!=0 excludes constant term; r is uninitialized]
    for(int i=0;i<=l;i++)printf("A:%d %d\n",A[i],B[i]); // @@ [Loop runs to i<=l, but l was incremented after last valid index, so A[l], B[l] are uninitialized]
    for(int i=0;i<=r;i++)printf("B:%d %d\n",C[i],D[i]); // @@ [Same: r points past last valid index, so C[r], D[r] are uninitialized]
    
    for(int i=0;i<=l;i++)for(int j=0;j<=r;j++){ // @@ [Loops include invalid indices l and r which were never assigned valid input]
        insert(A[i]*C[j],B[i]+D[j]);
    }
    for(p=Wordlist;p!=NULL;p=p->nxt)if(p->x!=0)printf("%d %d ",p->x,p->y);
    return 0;
}