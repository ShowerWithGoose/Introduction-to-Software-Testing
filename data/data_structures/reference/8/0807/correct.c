#include <stdio.h>
#include <string.h>
int w[209][209];
int v[209]={0};
int que[205]; 
int n,m;
void tra_BFS(int x){
	int i,h=0,t=1,tmp;
	que[h]=x;//进行入队
	while(h<=t){
		tmp=que[h++];
		if(v[tmp]) continue;
		else{
			printf("%d ",tmp);
			v[tmp]=1;
			for(i=0;i<n;i++)
			if(w[tmp][i]&& !v[i])
			que[t++] = i;
		} 
	} 
}
void t(int x){
	int i;
	printf("%d ",x);
	v[x]=1;
	for(i=0;i<n;i++){
		if(w[x][i]&&v[i]==0)  
		t(i);
	}
}
int main(){
	int u,y,i,j,del;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&u,&y);
		w[u][y]=w[y][u]=1;
	}
t(0);
	printf("\n");
	memset(v,0,sizeof(v));
	tra_BFS(0);
	printf("\n");
	scanf("%d",&del);
		memset(v,0,sizeof(v));
	v[del]=1;
	t(0);
	printf("\n");
	
	memset(v,0,sizeof(v));
		v[del]=1;
	tra_BFS(0);
	printf("\n");
return 0;	
}

