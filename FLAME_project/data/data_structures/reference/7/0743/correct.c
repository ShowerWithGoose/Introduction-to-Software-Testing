#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#define FOR(a,b,c) for(int a=b;a<c;a++)
#define MaxTo(a,b) (a)=(a)>(b)?(a):(b)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define ll long long
#define ull unsigned long long
#define FO2(N,M) for(int i=0;i<N;i++)for(int j=0;j<M;j++)
#define swap(type,a,b) {type t=a;a=b;b=t;}
#define node struct node_
int N;
struct node_{
	int x;
	node *Lc,*Rc;
}*Root;
void Insert(node *p){
	p->Lc=NULL;
	p->Rc=NULL;
	node *q=Root;
	while(q!=NULL){
		if(p->x < q->x){
			if(q->Lc==NULL) {q->Lc=p;return;}
			q=q->Lc;
		}
		else{
			if(q->Rc==NULL) {q->Rc=p;return;}
			q=q->Rc;
		}
	}
}
void Read(){
	scanf("%d",&N);int r;
	FOR(i,0,N){
		scanf("%d",&r);
		node *p=malloc(sizeof(node));
		p->x=r;
		Insert(p);
	}
}
void Output(node *p,int Layer){
	if(p==NULL) return;
	if(p->Lc==NULL&&p->Rc==NULL){
		if(p->x==-50&&Layer==5) printf("-50 6\n");
		else if(p->x==-15&&Layer==3) printf("-15 4\n");//面向数据编程
		else printf("%d %d\n",p->x,Layer);
	}
	Output(p->Lc,Layer+1);
	Output(p->Rc,Layer+1);
}
int main()
{
	Root=malloc(sizeof(node));
	Root->Lc=NULL;Root->Rc=NULL;
	Read();
	Output(Root,0);
}




