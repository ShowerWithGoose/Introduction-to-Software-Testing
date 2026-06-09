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
    t->nxt=q,q->nxt=p; // @@ [Error: When the loop breaks because p->y < y and t is NULL (i.e., the new node should be inserted at the head), t is NULL, causing a segmentation fault or incorrect insertion. The code does not handle the case where the new node should become the new head of the list.]
    return 0;
}
int A[M],B[M],C[M],D[M];
int l,r;
int main(){
//    freopen("article.txt","r",stdin);
    while(scanf("%d %d",&A[l],&B[l])&&B[l]!=0)l++; // @@ [Error: The input reading loop stops when B[l] (exponent) is 0, but the problem requires reading all terms including the constant term (exponent 0). This causes the last term (with exponent 0) to be missed, leading to incorrect polynomial representation.]
    while(scanf("%d %d",&C[r],&D[r])&&D[r]!=0)r++; // @@ [Error: Same issue as above; the loop stops prematurely when exponent is 0, missing the constant term of the second polynomial.]
    for(int i=0;i<=l;i++)printf("A:%d %d\n",A[i],B[i]);
    for(int i=0;i<=r;i++)printf("B:%d %d\n",C[i],D[i]);
    
    for(int i=0;i<=l;i++)for(int j=0;j<=r;j++){
        insert(A[i]*C[j],B[i]+D[j]);
    }
    for(p=Wordlist;p!=NULL;p=p->nxt)if(p->x!=0)printf("%d %d ",p->x,p->y);
    return 0;
}