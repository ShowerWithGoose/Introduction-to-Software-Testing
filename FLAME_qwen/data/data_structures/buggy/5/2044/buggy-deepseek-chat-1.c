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
    t->nxt=q,q->nxt=p; // @@ [When the loop breaks because p->y < y and t is NULL (i.e., the new node should be inserted at the head), t is NULL, causing a segmentation fault when dereferencing t->nxt.]
    return 0;
}
int A[M],B[M],C[M],D[M];
int l,r;
int main(){
//    freopen("article.txt","r",stdin);
    while(scanf("%d %d",&A[l],&B[l])&&B[l]!=0)l++; // @@ [The condition B[l]!=0 assumes the last term has exponent 0, but the problem allows any non-negative exponent; also, the input may end with a newline, not necessarily a zero exponent.]
    while(scanf("%d %d",&C[r],&D[r])&&D[r]!=0)r++; // @@ [Same issue as above; the input termination condition is incorrect.]
    for(int i=0;i<=l;i++)printf("A:%d %d\n",A[i],B[i]);
    for(int i=0;i<=r;i++)printf("B:%d %d\n",C[i],D[i]);
    
    for(int i=0;i<=l;i++)for(int j=0;j<=r;j++){
        insert(A[i]*C[j],B[i]+D[j]);
    }
    for(p=Wordlist;p!=NULL;p=p->nxt)if(p->x!=0)printf("%d %d ",p->x,p->y);
    return 0;
}