#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>
#include<float.h>
#include<ctype.h>

#define MaxV    105
#define MAXSIZE 1000//队的最大元素个数 

int  G[MaxV][MaxV];
int  Visited[MaxV]={0};
 //标识顶点是否被访问过，N为顶点数
int n,m,mm,i,j,v1,v2;
int Front=0, Rear=MAXSIZE-1,Count=0;
int Q[MAXSIZE];
void BFS(int  G[ ][MaxV], int v);
void  travelDFS(int  G[ ][MaxV], int n);
void  travelBFS(int  G[ ][MaxV], int n);
void DFS(int  G[ ][MaxV], int v);
int deQueue();
void enQueue(intitem);
int isEmpty( );
int isFull( );

int main()
{
	
	scanf("%d%d",&n,&m);
	mm=n+5;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&v1,&v2);
		G[v1][v2]= 1;
		G[v2][v1]= 1;
	}
	
	travelDFS(G, n);
	printf("\n");
	travelBFS(G, n);
	printf("\n");
	
	scanf("%d",&mm);
	for(i=0;i<n;i++)
	{
		G[mm][i]=0;
		G[i][mm]=0;
	}
	
	
	travelDFS(G, n);
	printf("\n");
	travelBFS(G, n);
	
	return 0;
 } 
 
 
void  travelDFS(int  G[ ][MaxV], int n)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    for(i=0; i<n; i++)
     if(i!=mm)
        if( !Visited[i] ) DFS(G, i);
}
void DFS(int  G[ ][MaxV], int v)
{
    int i;
    Visited[v] = 1; 	//标识某顶点被访问过
    printf("%d ",v); 	//访问某顶点
    for(i = 0; i<n;  i++)
     if(G[v][i]!=0)
         if( !Visited[i] )
             DFS(G, i);
}
void  travelBFS(int  G[ ][MaxV], int n)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    for(i=0; i<n; i++)
     if(i!=mm)
        if( !Visited[i] ) BFS(G, i);
}
void BFS(int  G[ ][MaxV], int v)
{
    int i;
    printf("%d ",v); //访问当前顶点
    Visited[v] = 1; //标识某顶点被访问过
    enQueue(v);         // 入口的第一个顶点入队
    while(Count!=0 ){  //  循环，直到队空为止 
         v = deQueue();  //取出队头元素
                 //获取该顶点第一个邻接顶点
         for(i=0;i<n ; i++ )
			  if(G[v][i]!=0) //访问该顶点下的每个邻接顶点
             if( !Visited[i] ) {
                    printf("%d ",i); //访问当前顶点
                    Visited[i] = 1; //标识某顶点被访问过
                    enQueue(i); //邻接顶点依次分别入队
           }
     }
}
void enQueue(int item)
{
    if(isFull()) /* 队满，插入失败 */
       printf("Wrong enter\n");
    else
	 {
       Rear = (Rear+1) % MAXSIZE; // 计算循环队列尾部的合适的进队位置
       Q[Rear]=item;
       Count++;/* 队未满，插入成功 */
    }
}

int deQueue()
{
   int q;
   if(Count==0)
    printf("Wrong out\n"); /* 队空，删除失败 */
   else
	{
      q=Q[Front];
      Count--; /* 队非空，删除成功 */
      Front = (Front+1)%MAXSIZE; // 计算循环队列头部的合适的出队位置
      return q;
   }
}
int isEmpty( )
{
   return Count == 0;
}

int isFull( )
{
    return Count == MAXSIZE;
}

