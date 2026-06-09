#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define VLink int
int bian[100][100];
int numd,numb;
int  Visited[100]={0};//标识顶点是否被访问过，N为顶点数
void VISIT(int i)
{
	printf("%d ",i); 
} 
void DFS(int v)
{
	int i;
    Visited[v] = 1; //标识某顶点被访问过
    VISIT(v); //访问某顶点
    for(i=0;i<numd;i++)
    {
    	if(bian[v][i]==1&&Visited[i]==0)
		DFS(i);	
	}
}
void  travelDFS(int n)
{
    int i;
    for(i=0; i<n; i++)
        if( !Visited[i] ) DFS(i);
        
       printf("\n"); 
}
int Q[100];
int in=-1,out=0;
void BFS(int v)
{
	int i;
	VISIT(v);
	Visited[v]=1;
	Q[++in]=v;
	while(out!=in+1)
	{
		v=Q[out++];
		for(i=0;i<numd;i++)
		{
			if(bian[v][i]==1&Visited[i]==0)
			{
				VISIT(i);
				Visited[i]=1;
				Q[++in]=i;
			}
		}
	}
}

void travelBFS(int n)
{
	int i;
	in=-1,out=0;
	for(i=0;i<n;i++)
	if( !Visited[i] ) BFS(i);	
	printf("\n");
}
void bef_and_now(int numd,int s)
{
	int i;
	for(i=0;i<numd;i++)
	Visited[i]=0;
	travelDFS(numd);
	for(i=0;i<numd;i++)
	Visited[i]=0;
	travelBFS(numd);
	for(i=0;i<numd;i++)
	Visited[i]=0;
	Visited[s]=1;
	travelDFS(numd);
	for(i=0;i<numd;i++)
	Visited[i]=0;
	Visited[s]=1;
	travelBFS(numd); 
}

int main()
{

	scanf("%d %d",&numd,&numb);
	int i;
	int a,b;
	for(i=0;i<numb;i++)
	{
		scanf("%d %d",&a,&b);
		bian[a][b]=1;
		bian[b][a]=1;
	} 
	int s;
	scanf("%d",&s);
	bef_and_now(numd,s);
	return 0;
	
	 
 } 

