#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
int a[200][200];//邻接矩阵 
int visited[200];    //访问数组
int que[200];        //用于BFS
void BFS(int v2); 
void DFS(int v2);
void clear(int a[]);


int n,t;//顶点数和边数 

int main()
{	
	int v1,v2,del;
	scanf("%d %d",&n,&t);
	for(int i=0;i<t;i++){
		scanf("%d %d",&v1,&v2);//录入矩阵 
		a[v1][v2]=a[v2][v1]=1;
	}
	scanf("%d",&del);
	
    DFS(0);	//深度
    printf("\n"); 
	clear(visited);
 
    BFS(0);	//广度 
    printf("\n"); 
    clear(visited);//清空！ 
    
	visited[del]=1;		 
	DFS(0);	
	printf("\n"); 
	
    clear(visited);
    clear(que);
	visited[del]=1;		 
	BFS(0);
	return 0;
}

void DFS(int v2)
{
	printf("%d ",v2);	//输出 
	visited[v2]=1;		//已访问 
	for(int i=0;i<n;i++)
		if (a[v2][i]==1 && visited[i]==0){	
			DFS(i);		//DFS访问 
		}
}
void BFS(int v2)
{
	int head=0,tail=1;//放里面,不用调整 
	int i,tmp;	
	que[head]=v2;
	while(head<=tail){
		tmp=que[head];	
		head++;			
		if(visited[tmp])
			continue;	//如果访问过 
		else{
			printf("%d ",tmp);		//打印出队元素 
			visited[tmp]=1;			//已访问 
			for(i=0;i<n;i++)
				if (a[tmp][i]==1 && visited[i]==0)	
					que[tail++]=i;		//入队 
		}
	}
}
void clear(int a[])
{
	for(int i=0;i<200;i++)
	a[i]=0;
}


