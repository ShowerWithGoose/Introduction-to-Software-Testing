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
#define edge struct _edge
#define Memset(X,n) memset(X,n,sizeof(X))
//#define ForPoint(p,x) for(edge *p=First[x].Next;p!=NULL;p=p->Next)
int N,M;
int Delete=-1;//删除节点编号
/*struct _edge{
	int To;
	edge *Next;
}First[108];
void AddEdge(int P,int Q){//添加一条从P到Q的边
	edge *p=malloc(sizeof(edge));
	p->To=Q;
	p->Next=First[P].Next;
	First[P].Next=p;
}*/
bool a[102][102];//是否相连
bool Vis[108];
void DFS(int This){
	Vis[This]=1;
	printf("%d ",This);
	FOR(i,0,N) if(!Vis[i]&&a[This][i]&&i!=Delete) DFS(i);
}
void BFS(){
	Vis[0]=1;
	int Q[109],Head=0,Tail=1;
	memset(Q,0,sizeof(Q));
	int Now;
	while(Tail-Head>0){
		Now=Q[Head];
		Head++;
		printf("%d ",Now);
		FOR(i,0,N) if(!Vis[i]&&a[Now][i]&&i!=Delete){
			Vis[i]=1;
			Q[Tail++]=i;
		}
	}
}
int main()
{
	scanf("%d%d",&N,&M);
	int A,B;
	FOR(i,0,M){
		scanf("%d%d",&A,&B);
		a[A][B]=a[B][A]=1;
	}
	DFS(0);printf("\n");
	Memset(Vis,0);BFS();printf("\n");
	scanf("%d",&Delete);
	Memset(Vis,0);DFS(0);printf("\n");
	Memset(Vis,0);BFS();
	return 0;
}


