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
    q=(struct node *)malloc(sizeof(struct node)); // @@ [missing #include <stdlib.h> for malloc]
    q->nxt=NULL;
    q->x=x,q->y=y;
    if(Wordlist==NULL){Wordlist=q;return 0;}
    for(p=Wordlist,t=NULL;p!=NULL;t=p,p=p->nxt){
        if(p->y==y){p->x+=x;return 0;}
        if(p->y<y)break;
    }
    t->nxt=q,q->nxt=p; // @@ [t may be NULL when inserting at head after first element, leading to segmentation fault]
    return 0;
}
int A[M],B[M],C[M],D[M];
int l,r;
int main(){
//    freopen("article.txt","r",stdin);
    while(scanf("%d %d",&A[l],&B[l])&&B[l]!=0)l++; // @@ [l is uninitialized (used before initialization), and loop condition B[l]!=0 incorrectly excludes constant term (exponent 0)]
    while(scanf("%d %d",&C[r],&D[r])&&D[r]!=0)r++; // @@ [r is uninitialized (used before initialization), and loop condition D[r]!=0 incorrectly excludes constant term (exponent 0)]
    for(int i=0;i<=l;i++)printf("A:%d %d\n",A[i],B[i]); // @@ [debug print left in code; also accesses uninitialized A[0], B[0] if l starts uninitialized]
    for(int i=0;i<=r;i++)printf("B:%d %d\n",C[i],D[i]); // @@ [debug print left in code; also accesses uninitialized C[0], D[0] if r starts uninitialized]
    
    for(int i=0;i<=l;i++)for(int j=0;j<=r;j++){ // @@ [loop includes index l and r which were incremented after last valid input, causing out-of-bound access]
        insert(A[i]*C[j],B[i]+D[j]);
    }
    for(p=Wordlist;p!=NULL;p=p->nxt)if(p->x!=0)printf("%d %d ",p->x,p->y); // @@ [output order may not be strictly descending due to insertion logic flaw when t is NULL]
    return 0;
}