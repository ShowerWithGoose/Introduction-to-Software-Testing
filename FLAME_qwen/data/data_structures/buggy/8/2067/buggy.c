#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int a[101][101]={{0}};
int visit[101]={0};
int que[101]={0};
void g0(int n){
	for(int i=0;i<n;i++){
		visit[i]=0;
		que[i]=0;
	}
}
void DFS(int n,int k){
	visit[k]=1;
	printf("%d ",k);   
	for(int i=0;i<n;i++){
		if(visit[i]==0&&a[k][i]==1){
			DFS(n,i);
		}
	}
}
void tDFS(int n){
	for(int i=0;i<n;i++){
		if(visit[i]==0){
			DFS(n,i);
		}
	}
	printf("\n");
}

void tBFS(int n)
{
	int i,head=0,tail=1,tmp;	
	que[head]=0;	
	while(head<=tail)	
	{
		tmp=que[head];
		head++;			
		if(visit[tmp])	continue;
		else
		{
			printf("%d ",tmp);		
			visit[tmp]=1;		
			for(i=0;i<n;i++)
				if (a[tmp][i] && !visit[i])	
					que[tail++]=i;		
		}
	}
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);
		a[x][y]=a[y][x]=1;
	}
	g0(n);
	tDFS(n);
	g0(n);
	tBFS(n);
	int v;
	scanf("%d",&v);
	g0(n);
	visit[v]=1;
	tDFS(n);
	g0(n);
	visit[v]=1;
	tBFS(n);
	return 0;
}




