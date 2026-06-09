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
    if(t==NULL){q->nxt=Wordlist;Wordlist=q;}else{t->nxt=q;q->nxt=p;} // @@ [When inserting at the head of the list (t is NULL), the code fails to update Wordlist correctly. The original code assumes t is not NULL when doing t->nxt=q, which causes undefined behavior or crash when inserting a term with exponent larger than the first term's exponent.]
    return 0;
}
int A[M],B[M],C[M],D[M];
int l,r;
int main(){
//    freopen("article.txt","r",stdin);
    while(scanf("%d %d",&A[l],&B[l])&&B[l]!=0)l++; // @@ [The loop condition stops reading when exponent is 0, but the problem states that terms with non-zero coefficients are input, including possibly a constant term (exponent 0). Thus, this misses the last term if its exponent is 0.]
    while(scanf("%d %d",&C[r],&D[r])&&D[r]!=0)r++; // @@ [Same issue as above: fails to read a term with exponent 0 in the second polynomial.]
    for(int i=0;i<=l;i++)printf("A:%d %d\n",A[i],B[i]); // @@ [Debug print statements are present in the output, which violates the output format requirement. These should be removed.]
    for(int i=0;i<=r;i++)printf("B:%d %d\n",C[i],D[r]); // @@ [Typo: uses D[r] instead of D[i], causing incorrect debug output and potentially undefined behavior due to out-of-bounds access. Also, debug prints should not be in final output.]
    
    for(int i=0;i<=l;i++)for(int j=0;j<=r;j++){
        insert(A[i]*C[j],B[i]+D[j]);
    }
    for(p=Wordlist;p!=NULL;p=p->nxt)if(p->x!=0)printf("%d %d ",p->x,p->y); // @@ [The output order may be incorrect because the insertion logic does not guarantee descending order when handling equal exponents or inserting at head. Additionally, zero-coefficient terms are skipped, which is correct, but the ordering depends on correct insertion.]
    return 0;
}