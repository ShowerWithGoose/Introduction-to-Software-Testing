#include<stdio.h>
#include<string.h>
int weights[300][300],visit[300]={0},queue[300];
// weights图的邻接矩阵， visit访问数组， que BFS用的访问队列 
int n,m;	//顶点数和边数 
void  DFS(int);
void  BFS(int);
int main()
{	
	int u,v,i,del;
	fscanf(stdin,"%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&u,&v); //录入矩阵 
		weights[u][v]=weights[v][u]=1;
	}
	DFS(0);	//DFS
	puts("");
	
	memset(visit,0,sizeof(visit));	//初始化不要忘了 
	BFS(0);	//BFS
	puts("");
	
	memset(visit,0,sizeof(visit));	//初始化不要忘了
	scanf("%d",&del);
	visit[del]=1;		//	要删除的元素设置为已访问 
	DFS(0);	//DFS
	puts("");
	
	memset(visit,0,sizeof(visit));
	memset(queue,0,sizeof(queue));
	visit[del]=1;		
	BFS(0);
	puts("");	//BFS
return 0;
}

void DFS(int v)
{
	int i;
	printf("%d ",v);	//输出 
	visit[v]=1;		//已访问 
	for(i = 0; i < n; ++i)
		if (weights[v][i]!=0 && visit[i]==0)	 DFS(i);		//DFS访问 	
}
void BFS(int v)
{
	int i,head=0,tail=1,tmp;	//队头，队尾，出列的元素 
	queue[0]=v;	//入队 
	while(head<=tail)	//队列访问完毕 
	{
		tmp=queue[head++];	//出队 
		if(visit[tmp]!=0)	continue;	//如果访问过 
		else
		{
			printf("%d ",tmp);		//打印出队元素 
			visit[tmp]=1;			//已访问 
			for(i=0;i<n;++i)
				if (weights[tmp][i] !=0 && visit[i]==0)	//如果矩阵元素为 1 且未访问过 
					queue[tail++]=i;		//入队 
		}
	}
}

