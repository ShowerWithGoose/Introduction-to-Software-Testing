#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
int num,n;
    int i=0,j=0,k=0;
    int tu[110][110]={0},visit[110]={0};
    int queue[110];
	int rear=-1,front=0;
    int a,b;
    int del;
void dfs(int v)
{
    int w,r;
    visit[v]=1;
    printf("%d ",v);
    for(w=1;w<=n;w++)
    {
    	if(tu[v][w])
    	{
    		if(visit[w]==0)
        {
            dfs(w);
        }
		}
        
    }
}

void bfs(int v)
{
	int r,w;
	visit[v]=1;
	printf("%d ",v);
	queue[++rear]=v;
	while(front<=rear)
	{
		v=queue[front++];
			for(w=0;w<=n;w++)
	     {
		    if(tu[v][w])
	     	{
			  if(visit[w]==0)
			    {
			      queue[++rear]=w;
			      visit[w]=1;
			      printf("%d ",w);
		    	}
	     	}
	     }
		
		
	}
	
}
int main()
{
    
    scanf("%d %d",&num,&n);//表示顶点个数和边得个数
    
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&a,&b);//两个相连得顶点
        tu[a][b]=tu[b][a]=1;//记录下有连接关系得两个节点
    }
    scanf("%d",&del);
    dfs(0);
    printf("\n");
    memset(visit,0,sizeof(visit));
    bfs(0);
    printf("\n");
    for(i=0;i<110;i++)tu[del][i]=0;
    for(i=0;i<110;i++)tu[i][del]=0;
    memset(visit,0,sizeof(visit));
    dfs(0);
    printf("\n");
    memset(visit,0,sizeof(visit));
    bfs(0);
    return 0;
}

