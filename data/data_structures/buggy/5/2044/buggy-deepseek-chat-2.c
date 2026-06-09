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
    t->nxt=q,q->nxt=p; // @@ [When the loop breaks because p is NULL (end of list), t may be NULL if the new node should be inserted at the head, causing a segmentation fault when accessing t->nxt. Also, when the loop breaks because p->y < y, t is guaranteed to be non-NULL only if the list is non-empty and the first node's y is not less than y; if the new node should be inserted before the first node, t is NULL.]
    return 0;
}
int A[M],B[M],C[M],D[M];
int l,r;
int main(){
//    freopen("article.txt","r",stdin);
    while(scanf("%d %d",&A[l],&B[l])&&B[l]!=0)l++; // @@ [The input format does not guarantee that the last term has exponent 0; it only says input ends with newline. This loop will fail if the last term's exponent is not 0, as it will stop reading prematurely. Also, it does not read the constant term (exponent 0) if present.]
    while(scanf("%d %d",&C[r],&D[r])&&D[r]!=0)r++; // @@ [Same issue as above for the second polynomial.]
    for(int i=0;i<=l;i++)printf("A:%d %d\n",A[i],B[i]); // @@ [Debug print statements should not be present in final output; they will produce extra output not matching expected format.]
    for(int i=0;i<=r;i++)printf("B:%d %d\n",C[i],D[i]); // @@ [Same as above.]
    
    for(int i=0;i<=l;i++)for(int j=0;j<=r;j++){
        insert(A[i]*C[j],B[i]+D[j]);
    }
    for(p=Wordlist;p!=NULL;p=p->nxt)if(p->x!=0)printf("%d %d ",p->x,p->y);
    return 0;
}