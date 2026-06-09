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
    t->nxt=q,q->nxt=p; // @@ [if insertion happens at head (t is NULL), this causes undefined behavior]
    return 0;
}
int A[M],B[M],C[M],D[M];
int l,r;
int main(){
//    freopen("article.txt","r",stdin);
    while(scanf("%d %d",&A[l],&B[l])&&B[l]!=0)l++; // @@ [loop condition incorrect: should read until newline, not until exponent 0; also l is uninitialized]
    while(scanf("%d %d",&C[r],&D[r])&&D[r]!=0)r++; // @@ [same issue: r is uninitialized and condition wrong]
    for(int i=0;i<=l;i++)printf("A:%d %d\n",A[i],B[i]); // @@ [debug print left in code; also accesses uninitialized elements if l==0]
    for(int i=0;i<=r;i++)printf("B:%d %d\n",C[i],D[i]); // @@ [same debug issue]
    
    for(int i=0;i<=l;i++)for(int j=0;j<=r;j++){ // @@ [loops include index l and r which may be beyond valid input due to incorrect reading logic]
        insert(A[i]*C[j],B[i]+D[j]);
    }
    for(p=Wordlist;p!=NULL;p=p->nxt)if(p->x!=0)printf("%d %d ",p->x,p->y); // @@ [output order may not be descending due to flawed insertion logic when inserting before head]
    return 0;
}