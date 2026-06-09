#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int visit[100];
typedef struct q{
	int rear,front;
	int p[1000]; 
}em; 
void enqueue(em *a,int i)
{
	a->p[a->rear]=i;
	a->rear++;
}
void dequeue(em *a){
	a->front++;
}
void FPS(int a[][100],int m,int n,int flag)
{   int j;
	visit[m]=1;
	if(flag!=m)
	printf("%d ",m);
	for(j=0;j<n;j++)
	{if(a[m][j]==1&&!visit[j])
	FPS(a,j,n,flag);
	}
}
void travelFPS(int a[][100],int n,int flag)
{
	int i=0;
	for(i=0;i<n;i++)
	  visit[i]=0;
	for(i=0;i<n;i++)
	  if(!visit[i])
	  FPS(a,i,n,flag);
}
void travelBPS(int a[][100],int n)
{
	int i=0;
	em *queue=(struct q*)malloc(sizeof(struct q));
	queue->front=0;queue->rear=0;
	for(i=0;i<n;i++)
	visit[i]=0;
	printf("0 ");
	for(i=0;i<n;i++)
	if(!visit[i])
	{  
		visit[i]=1;
		enqueue(queue,i);
		while(queue->rear!=queue->front)
		{   int j;
		    i=queue->p[queue->front];
		    dequeue(queue);
			for(j=0;j<n;j++)
			{
				if(a[i][j]==1&&!visit[j])
				{
					visit[j]=1;
					printf("%d ",j);
					enqueue(queue,j);
				}
			}
		}
		
	}
}

int main(){
	int vex,line,n,m,i,j,k,p,a[100][100]={0};
	scanf("%d %d",&vex,&line);
	for(i=0;i<line;i++)
	{
		scanf("%d %d",&n,&m);
		a[n][m]=1;
		a[m][n]=1;
	}
	scanf("%d",&n);
	travelFPS(a,vex,-1);
	printf("\n");
	travelBPS(a,vex);
	printf("\n");
	for(i=0;i<vex;i++)
	{
		a[i][n]=0;
		a[n][i]=0;
	}
	travelFPS(a,vex,n);
	printf("\n");
	travelBPS(a,vex);
	printf("\n");
	
} 

