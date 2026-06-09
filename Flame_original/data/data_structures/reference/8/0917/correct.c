#include<stdio.h>

int l,n,i,j,del,first;
int pic[200][200]={0},list[200]={0},mark[200]={0};//mark标记这个点是否被遍历 
int dfs(int head){
	int k;
	printf("%d ",head);
	mark[head]=1;
	for(k=0;k<n;k++){
		if(pic[head][k]==1&&mark[k]==0)
			dfs(k);
	}
} 
int bfs(int head,int sum){
	int t=0;
	list[t]=head;
	t++; //已经压进队列的个数 
	first=0;
	while(first<t) {
		mark[list[first]]=1;
		for(i=0;i<n;i++){
			if(pic[list[first]][i]==1&&mark[i]==0){
				list[t]=i;//压进队列 
				t++;
				mark[i]=1;//标记遍历过 
			}
		}
		printf("%d ",list[first]);
		first++;
	}
} 
int main(){
	int k;
	scanf("%d%d",&n,&l);//n是节点个数，l是边数
	for(k=0;k<l;k++){
		scanf("%d%d",&i,&j);
		pic[i][j]=pic[j][i]=1; 
	} //建立连接矩阵 
	scanf("%d",&del);//要删除的节点 
	dfs(0);//未删除节点的深度优先遍历 
	for(i=0;i<n;i++){
		mark[i]=0;
	}//给标记置为零 
	printf("\n");
	bfs(0,n);//广度优先遍历 
	printf("\n");
	

//删除节点之后 
	for(i=0;i<n;i++){
		mark[i]=0;
		list[i]=0;
	}//给标记置为零 
	mark[del]=1;
	dfs(0);//删除节点后深度优先遍历 
	printf("\n");
	
	for(i=0;i<n;i++){
		mark[i]=0;
	}//给标记置为零 
	mark[del]=1;
	bfs(0,n-1);//广度优先遍历 
	printf("\n");
	return 0;
}

