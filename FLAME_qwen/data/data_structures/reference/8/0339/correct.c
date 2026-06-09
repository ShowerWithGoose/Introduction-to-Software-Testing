#include<stdio.h>
#include<string.h>
int weights[200][200],visited[200]={0},que[200];
// weights图的邻接矩阵， visited访问数组， que BFS用的访问队列 
int n,m;	//顶点数和边数 
void travelDFS(int v)
{
	int i;
	printf("%d ",v);	//输出 
	visited[v]=1;		//已访问 
	for(i = 0; i < n; i++)
		if (weights[v][i] && !visited[i])	//如果矩阵元素为 1 且未访问过 
		{
			travelDFS(i);		//DFS访问 
		}
}
#define MaxV    100
typedef struct  edge{ 
       int  adjvex;
       int  weight;
       struct edge  *next;
}ELink;
typedef struct ver{
       int  vertex;
       ELink  *link;
}VLink;
VLink  G[MaxV];

int  Visited[100]={0}; //标识顶点是否被访问过，N为顶点数
void  traveldfs(VLink  G[ ], int n)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    for(i=0; i<n; i++)
        if( !Visited[i] ) DFS(G, i);
}
void DFS(VLink  G[], int v)
{
    ELink  *p;
    Visited[v] = 1; //标识某顶点被访问过

    for(p = G[v].link; p !=NULL;  p=p->next)
         if( !Visited[p->adjvex] )
             DFS(G, p->adjvex);
}


void travelBFS(int v)
{
	int i,head=0,tail=1,tmp;	//队头，队尾，出列的元素 
	que[head]=v;	//入队 
	while(head<=tail)	//队列访问完毕 
	{
		tmp=que[head];	//出队 
		head++;			//出队
		if(visited[tmp])	continue;	//如果访问过 
		else
		{
			printf("%d ",tmp);		//打印出队元素 
			visited[tmp]=1;			//已访问 
			for(i=0;i<n;i++)
				if (weights[tmp][i] && !visited[i])	//如果矩阵元素为 1 且未访问过 
					que[tail++]=i;		//入队 
		}
	}
}
void  travelbfs(VLink  G[ ], int n)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    for(i=0; i<n; i++)
        if( !Visited[i] ) BFS(G, i);
}
void BFS(VLink  G[ ], int v)
{
    ELink  *p;
    int front = 0,rear = 1;
    int tmp;
    Visited[v] = 1; //标识某顶点已入队
    que[front] = v;
    while(front<=rear){
         tmp = que[front++];
         printf("%d ",v); //访问当前顶点
         for(p=G[v].link; p!=NULL; p=p->next ) //访问该顶点的每个邻接顶点
             if( !Visited[p->adjvex] ) {
                    Visited[p->adjvex] = 1; //标识某顶点入队
                    que[rear++] = p->adjvex;
           }
     }
}


int main()
{	
	int u,v,i,del;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&u,&v); //录入矩阵 
		weights[u][v]=1;
		weights[v][u]=1;
	}
	travelDFS(0);puts("");	//DFS
	
	traveldfs(G, 5);
	
	memset(visited,0,sizeof(visited));	//初始化不要忘了 
	travelBFS(0);puts("");	//BFS
	
	traveldfs(G, 5);
	
	scanf("%d",&del);
	memset(visited,0,sizeof(visited));	//初始化不要忘了
	visited[del]=1;		//	要删除的元素设置为已访问 
	travelDFS(0);puts("");	//DFS
	
	traveldfs(G, 5);
	
	memset(visited,0,sizeof(visited));
	memset(que,0,sizeof(que));//********注意：队列初始化不要忘了
	visited[del]=1;		//	要删除的元素设置为已访问 
	travelBFS(0);puts("");	//BFS
	
	traveldfs(G, 5);
	
	return 0;
}


