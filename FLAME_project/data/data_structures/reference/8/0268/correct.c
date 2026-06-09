#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define fr(i,l,n) for(i=l;i<n;i++)
#define ll long long
#define gc getchar()
#define sc scanf
#define in(n) scanf("%d",&n)
#define pr printf
#define pn putchar('\n')
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define st struct
#define stmalloc(p) (struct p*)malloc(sizeof(struct p))
#define maxv 1000

int elist[maxv][maxv],visited[maxv];
int v,cnt=1,p=0;
int que[maxv];

void DFS(int r){
	int i;
	visited[r]=1;
	pr("%d ",r);
	fr(i,0,v) if(elist[i][r]&&visited[i]==0) DFS(i);
}

void BFS(int r){
	int i,j;
	if(visited[r]) return ;
	p++;
	visited[r]=1;
	pr("%d ",r);
	fr(i,0,v) if(elist[i][r]&&visited[i]==0) que[cnt++]=i;
	fr(i,p,cnt) BFS(que[i]); 
}

int main(){
	int i,j,e,delp,s,t;
	sc("%d %d\n",&v,&e);
	fr(i,0,e){
		sc("%d %d",&s,&t);
		elist[s][t]=1;
		elist[t][s]=1;
	}
	in(delp);
	
	DFS(0);
	memset(visited,0,maxv);
	pn;
	BFS(0);
	memset(visited,0,maxv);
	cnt=1;
	p=0;
	memset(que,0,maxv);
	pn;
	
	fr(i,0,v) if(elist[i][delp]) elist[i][delp]=0;
	fr(j,0,v) if(elist[delp][j]) elist[delp][j]=0;
	
	DFS(0);
	memset(visited,0,maxv);
	pn;
	BFS(0);
return 0;
}

