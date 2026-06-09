#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int a[500][500]={{0}};
int Q[300]; 
int front=-1,rear=-1;
int Visited[1000]={0};
int n,e;
void DFS(int v)
{
    Visited[v] = 1; //标识某顶点被访问过
	printf("%d ",v);    	//访问某顶点
    for(int i=0;i<n;  i++)
         if( !Visited[i]&&a[v][i]!=0 )
             DFS(i);
}

void  travelDFS( int n)
{
    int i;
    for(i=0; i<n; i++)
        if( !Visited[i] ) DFS(i);
}
void AddQ(int S){
	Q[++rear]=S;
}
int Delete(){
	int item;
	item=Q[++front];
	return item;
}
void BFS (int S)
{   /* 以S为出发点对邻接矩阵存储的图Graph进行BFS搜索 */
    /* 访问顶点S：此处可根据具体访问需要改写 */
    AddQ(S); /* S入队列 */
    while ( front<rear) {
        int tmp= Delete();  /* 弹出V */
        if(Visited[tmp])	continue;
        else{
        	Visited[tmp]=1;
        	printf("%d ",tmp);
	        for( int i=0; i<n; i++ ) /* 对图中的每个顶点W */
	            /* 若W是V的邻接点并且未访问过 */
	            if ( !Visited[i] && a[tmp][i]!=0) {
					AddQ(i);               
	            }
		}
        
    } /* while结束*/
}
int main()
{
	
	scanf("%d %d",&n,&e);
	for(int i=0;i<e;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		a[x][y]=1;
		a[y][x]=1;
	}
	int de;
	scanf("%d",&de);
	travelDFS(n);
	printf("\n");
	for(int i=0; i<n; i++) Visited[i] = 0 ;
	BFS(0);
	printf("\n");
	for(int i=0; i<n; i++) Visited[i] = 0 ;
	Visited[de]=1;
	travelDFS(n);
	printf("\n");
	for(int i=0; i<n; i++) Visited[i] = 0 ;
	Visited[de]=1;
	BFS(0);
	printf("\n");
	return 0;
}


