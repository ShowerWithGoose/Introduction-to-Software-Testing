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
    while(scanf("%d %d",&A[l],&B[l])&&B[l]!=0)l++; // @@ [Error: The input reading condition `B[l]!=0` incorrectly assumes the input ends when exponent is 0, but the problem states exponents are non-negative integers and input ends with a newline. This causes the program to stop reading prematurely if a term has exponent 0, and also fails to read the last term if its exponent is 0. Additionally, the input format uses spaces and newlines, not a sentinel value of 0.]
    while(scanf("%d %d",&C[r],&D[r])&&D[r]!=0)r++; // @@ [Same error as above for the second polynomial.]
    for(int i=0;i<=l;i++)printf("A:%d %d\n",A[i],B[i]); // @@ [Error: This debug output prints the input data, which is not part of the required output format. It produces extra lines that cause the "Buggy Output" shown in the test case.]
    for(int i=0;i<=r;i++)printf("B:%d %d\n",C[i],D[i]); // @@ [Same error as above for the second polynomial.]
    
    for(int i=0;i<=l;i++)for(int j=0;j<=r;j++){
        insert(A[i]*C[j],B[i]+D[j]);
    }
    for(p=Wordlist;p!=NULL;p=p->nxt)if(p->x!=0)printf("%d %d ",p->x,p->y);
    return 0;
}