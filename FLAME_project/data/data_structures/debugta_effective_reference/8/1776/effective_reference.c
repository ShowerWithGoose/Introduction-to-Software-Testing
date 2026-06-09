#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct edge
{
    int adjvex;
    int weight;
    struct edge *next;
}ELink;
typedef struct ver
{
	int vertex;
    ELink *link;
}VLink;
struct con
{
	int st;
	int en;
};
struct con cons[105];//弧 
VLink G[105];
int k,Visited[105]={0}; //标识顶点是否被访问过，N为顶点数
void DFS(VLink Gs[ ],int v)
{//在图G中，从顶点v开始进行深度优先遍历
    ELink *p;
    Visited[v]=1; //标识某顶点被访问过
    printf("%d ",v); //访问某顶点
    for(p=Gs[v].link;p!=NULL;p=p->next)
         if(!Visited[p->adjvex])
             DFS(Gs,p->adjvex);
}
void travelDFS(VLink Gs[ ],int n)
{
    int i;
    for(i=0;i<n;i++)
        if(!Visited[i]) 
			DFS(Gs,i);
	printf("\n");
}//深度优先
int  Q[105]={},top=-1,rear=0,Visited1[105]={0};//标识顶点是否被访问过，N为顶点数
void enQueue(int el)
{
	top++;
	Q[top]=el;
}
int deQueue()
{
	rear=rear+1;
	return Q[rear-1];
} 
void BFS(VLink Gs[ ],int v)
{
    ELink *p;
    printf("%d ",Gs[v].vertex); //访问当前顶点
    Visited1[v]=1; //标识某顶点被访问过
    enQueue(v);
    while(rear<=top)
	{
        v=deQueue();  //取出队头元素
        p=Gs[v].link;  //获取该顶点第一个邻接顶点
        for(;p!=NULL;p=p->next ) //访问该顶点下的每个邻接顶点
            if(!Visited1[p->adjvex])
			{
				printf("%d ",p->adjvex);//访问当前顶点
                Visited1[p->adjvex]=1; //标识某顶点被访问过
                enQueue(p->adjvex);
           	}
     }
}
void travelBFS(VLink Gs[ ],int n)
{
    int i;

    for(i=0;i<n;i++)
        if(!Visited1[i]) 
			BFS(Gs,i);
	printf("\n");
}//广度优先 

int cop(const void* a1,const void* b1)//比较函数 
{
	struct con* a=(struct con*) a1;//可相应修改;注意：修改为 比 较 对 象 的 指 针 
	struct con* b=(struct con*) b1;
	if(a->st==b->st)
		return a->en>b->en?1:-1;
	else
		return a->st>b->st?1:-1;
}
int cop1(const void* a1,const void* b1)//比较函数 
{
	int* a=(int*) a1;//可相应修改;注意：修改为 比 较 对 象 的 指 针 
	int* b=(int*) b1;
	return *a>*b?1:-1; 
}
int main()
{
	int per[105]={},n,m,i,j,k;
	ELink *ex,*pos;
	scanf("%d%d",&m,&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&cons[i-1].st,&cons[i-1].en);
		
	}
	qsort(cons,n,sizeof(cons[0]),cop);
	scanf("%d",&k);
	for(i=1;i<=m;i++)
	{
		G[i-1].vertex=i-1;
		G[i-1].link=NULL;
		k=1;
		for(j=1;j<=n;j++)
		{
			if(cons[j-1].st==i-1)
			{
				per[k-1]=cons[j-1].en;
				k++;
			}
			else if(cons[j-1].en==i-1)
			{
				per[k-1]=cons[j-1].st;
				k++;
			}
		}
		k--;
		qsort(per,k,sizeof(int),cop1);
		for(j=1;j<=k;j++)
		{
			ex=(ELink*)malloc(sizeof(ELink));
			ex->next=(ELink*)malloc(sizeof(ELink));
			ex->next=NULL;
			
				ex->adjvex=per[j-1];
				if(G[i-1].link==NULL)
				{
					G[i-1].link=(ELink*)malloc(sizeof(ELink));
					memcpy(G[i-1].link,ex,sizeof(ELink));	
				}	
				else
				{
					pos=G[i-1].link;
					while(pos->next!=NULL)
						pos=pos->next;
					pos->next=(ELink*)malloc(sizeof(ELink));
					memcpy(pos->next,ex,sizeof(ELink));
				} 
			
			
			free(ex);
		}
		for(k=1;k<=105;k++)
			per[k-1]=0;
	}
	for(i=0;i<m;i++)
	{
		Visited1[i]=0;
		Visited[i]=0;
	 } 
		
	travelDFS(G,m);
	travelBFS(G,m);
	for(i=0;i<m;i++)
	{
		Visited1[i]=0;
		Visited[i]=0;
	 } 
	 Visited1[k]=1;Visited[k]=1;
	travelDFS(G,m);
	travelBFS(G,m);
	return 0;
}

