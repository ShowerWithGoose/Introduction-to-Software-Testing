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
    while(scanf("%d %d",&A[l],&B[l])&&B[l]!=0)l++; // @@ [The loop condition incorrectly stops when exponent is 0, but constant term (exponent 0) is valid and should be included. This causes the last term with exponent 0 to be skipped.]
    while(scanf("%d %d",&C[r],&D[r])&&D[r]!=0)r++; // @@ [Same issue: skips the term with exponent 0 in the second polynomial.]
    for(int i=0;i<=l;i++)printf("A:%d %d\n",A[i],B[i]); // @@ [Debug print statements are not part of expected output and cause Wrong Answer. Also, loop includes uninitialized A[l], B[l] because l was incremented after last valid input.]
    for(int i=0;i<=r;i++)printf("B:%d %d\n",C[i],D[i]); // @@ [Same debug print issue and accesses uninitialized C[r], D[r].]
    
    for(int i=0;i<=l;i++)for(int j=0;j<=r;j++){ // @@ [Loops run from 0 to l and r inclusive, but l and r point to one past the last valid index due to post-increment in input loops, leading to use of uninitialized values.]
        insert(A[i]*C[j],B[i]+D[j]);
    }
    for(p=Wordlist;p!=NULL;p=p->nxt)if(p->x!=0)printf("%d %d ",p->x,p->y); // @@ [Output format may not match exactly; also, insertion logic has a bug when inserting at head after initial insertion.]
    return 0;
}