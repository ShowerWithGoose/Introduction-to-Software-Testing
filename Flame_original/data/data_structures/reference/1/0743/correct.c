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
int N;
bool ch[10];//每个数是否检查过
int Select[10];//选择的顺序
void DFS(int Step){
	if(Step==N) {
		for(int i=0;i<N;i++) printf("%d ",Select[i]+1);
		printf("\n");return;}
	for(int i=0;i<N;i++)
	if(!ch[i]){
		ch[i]=1;
		Select[Step]=i;
		DFS(Step+1);
		Select[Step]=-1;
		ch[i]=0;
	}
}
int main()
{
	memset(Select,-1,sizeof(Select));
	scanf("%d",&N);
	DFS(0);
	return 0;
}


