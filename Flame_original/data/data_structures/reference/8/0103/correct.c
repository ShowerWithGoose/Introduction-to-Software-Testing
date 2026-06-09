#include<stdio.h>
int visit[115],temp[115],num_node,num_line,num=0,p;
int a[115][115];
int ans[4][115];
void dfs(int line);
void bfs(int line,int pos);
int main()
{
	int cnt=0,i;
	scanf("%d %d",&num_node,&num_line);
	int node1,node2;
	for(cnt=0;cnt<num_line;cnt++)
	{
		scanf("%d %d",&node1,&node2);
		a[node1][node2]=1;
		a[node2][node1]=1;
	}
	p=0;
	dfs(0);
	for(cnt=0;cnt<num_node;cnt++)
		ans[0][cnt]=temp[cnt];
	for(cnt=0;cnt<num_node;cnt++)
		visit[cnt]=0;	
	bfs(0,1);	
	int delete_num;
	scanf("%d",&delete_num);
	for(cnt=0;cnt<num_node;cnt++)
		a[cnt][delete_num]=0;
	for(cnt=0;cnt<num_node;cnt++)
		a[delete_num][cnt]=0;
	for(cnt=0;cnt<num_node;cnt++)
		visit[cnt]=0;
	p=0;
	dfs(0);
	for(cnt=0;cnt<num_node;cnt++)
		ans[2][cnt]=temp[cnt];
	for(cnt=0;cnt<num_node;cnt++)
		visit[cnt]=0;
	bfs(0,3);	
	for(i=0;i<2;i++)
	{
		for(cnt=0;cnt<num_node;cnt++)
			printf("%d ",ans[i][cnt]);
		printf("\n");
	}
	for(i=2;i<4;i++)
	{
		for(cnt=0;cnt<num_node-1;cnt++)
			printf("%d ",ans[i][cnt]);
		printf("\n");
	}
	return 0;	
} 
void dfs(int line)
{
	int cnt=0;
	if(visit[line]==0)
	{
		visit[line]=1;
		temp[p++]=line;
	}	
	for(cnt=0;cnt<num_node;cnt++)
		if(a[line][cnt]==1&&visit[cnt]==0)
			dfs(cnt);
	return;	
}
void bfs(int line,int pos)
{
	int cnt=0,front=0,rear=1;
	temp[0]=0;
	visit[0]=1;
	while(front<rear)
	{
		for(cnt=0;cnt<num_node;cnt++)
			if(a[temp[front]][cnt]==1&&visit[cnt]==0)
			{
				temp[rear++]=cnt;
				visit[cnt]=1;
			}
						
		front++;			
	}
	for(cnt=0;cnt<rear;cnt++)
		ans[pos][cnt]=temp[cnt];
	return;	
}

