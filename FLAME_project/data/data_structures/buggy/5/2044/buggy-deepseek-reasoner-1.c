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
    t->nxt=q,q->nxt=p;
    return 0;
}
int A[M],B[M],C[M],D[M];
int l,r;
int main(){
//    freopen("article.txt","r",stdin);
    while(scanf("%d %d",&A[l],&B[l])&&B[l]!=0)l++; // @@ Incorrect parsing: condition B[l]!=0 assumes polynomial ends with exponent 0, but input may not have a zero-exponent term. Should read until newline/EOF.
    while(scanf("%d %d",&C[r],&D[r])&&D[r]!=0)r++; // @@ Same error as previous line.
    for(int i=0;i<=l;i++)printf("A:%d %d\n",A[i],B[i]); // @@ After loop, l is the count of terms (incremented past last index), so condition i<=l accesses out-of-bounds element A[l] and B[l] (uninitialized). Should be i<l.
    for(int i=0;i<=r;i++)printf("B:%d %d\n",C[i],D[i]); // @@ Same out-of-bounds error: r may be 0 but i<=r accesses index 0 if r=0? Actually if r=0, i<=0 accesses only index 0 which is fine, but in the buggy run r=0 and C[0],D[0] are uninitialized (0 from global). But the real issue is that the parsing loop did not read the second polynomial, so the debug prints are misleading. However, the condition should be i<r to avoid accessing uninitialized values.
    for(int i=0;i<=l;i++)for(int j=0;j<=r;j++){ // @@ Loop bounds use <= instead of <, causing out-of-bounds access on arrays A,B,C,D, leading to garbage multiplications and possible crashes.
        insert(A[i]*C[j],B[i]+D[j]); // @@ Multiplication may involve uninitialized elements due to incorrect loop bounds and parsing.
    }
    for(p=Wordlist;p!=NULL;p=p->nxt)if(p->x!=0)printf("%d %d ",p->x,p->y);
    return 0;
}