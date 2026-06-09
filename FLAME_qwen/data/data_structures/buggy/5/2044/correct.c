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
//	freopen("article.txt","r",stdin);
	char c;
	do {
		scanf("%d%d%c",&A[l],&B[l],&c);
		l++;
	}while(c!='\n');
	do {
		scanf("%d%d%c",&C[r],&D[r],&c);
		r++;
	}while(c!='\n');
//	for(int i=0;i<l;i++)printf("A:%d %d\n",A[i],B[i]);
//	for(int i=0;i<r;i++)printf("B:%d %d\n",C[i],D[i]);
	
	for(int i=0;i<l;i++)for(int j=0;j<r;j++){
		insert(A[i]*C[j],B[i]+D[j]);
	}
	for(p=Wordlist;p!=NULL;p=p->nxt)if(p->x!=0)printf("%d %d ",p->x,p->y);
	return 0;
}


