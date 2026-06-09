#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
int weights[200][200], n,m,del=-1;
void createGraph() {
	int i,v1,v2;
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&v1,&v2); //录入矩阵 
		weights[v1][v2]=1;
		weights[v2][v1]=1;
	}
}
int Visited[10000];
void  travelDFS(int v)
{
    int i;
    printf("%d ",v);	 
	Visited[v]=1;		 
	for(i = 0; i < n; i++)
		if (weights[v][i] && !Visited[i])	//如果矩阵元素为 1 且未访问过 
		{
			travelDFS(i);		//DFS访问 
		}
}
int Q[1000];
int head,rear;
void enQueue(int n){
	int i=head;
	head++;
	Q[i]=n;
}
int deQueue(){
	return Q[rear++];
}
void  travelBFS(int v)
{
    int i,tmp;
    enQueue(v);	//入队 
	while(head>rear)	//队列访问完毕 
	{
		tmp=deQueue();	//出队 
		if(Visited[tmp])	continue;	//如果访问过 
		else
		{
			printf("%d ",tmp);		//打印出队元素 
			Visited[tmp]=1;			//已访问 
			for(i=0;i<n;i++)
				if (weights[tmp][i] && !Visited[i])	//如果矩阵元素为 1 且未访问过 
					enQueue(i);		//入队 
		}
	}
}
int main(){
	int i;
	scanf("%d %d",&n,&m);
	createGraph();
    /*for(i=0; i<n; i++)
	if(i!=del) 
	Visited[i]=0;*/
	travelDFS(0);
	printf("\n");
    for(i=0; i<n; i++)
	Visited[i]=0;
	travelBFS(0);
	printf("\n");
	scanf("%d",&del);
    for(i=0; i<n; i++)
	Visited[i]=0;
	Visited[del]=1;
	travelDFS(0);
	printf("\n");
    for(i=0; i<n; i++)
	Visited[i]=0;
	Visited[del]=1;
	travelBFS(0);
	printf("\n");
}


