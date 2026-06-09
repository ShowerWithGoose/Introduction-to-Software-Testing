#include <stdio.h>
#include <string.h>
#include <math.h>
int graph[120][120];
int visited[100];
int n,e;//µãºÍ±ß 
int delnum;

void DFS(int v)
{
    int i;
    printf("%d ",v);
    for(i=0;i<n;i++)
	{
        if(graph[v][i] && !visited[i])
        {
            visited[i] = 1;
            DFS(i);
        }
    }

}


void BFS()
{
    int que[101];
    int front=0,rear=1;
    que[front] = 0;
    int i;
    while(front<rear)
	{
        for(i=0;i<n;i++)
		{
            if(graph[que[front]][i] && !visited[i])
			{
                que[rear]=i;
                visited[i]=1;
                rear++;
            }
        }
        printf("%d ",que[front]);
        front++;
    }
}
int main()
{
    scanf("%d %d",&n,&e);
    int i = 0,v1,v2;
    while(i<e)
	{
        scanf("%d %d",&v1,&v2);
        graph[v1][v2]=1;
        graph[v2][v1]=1;
        i++;
    }
    scanf("%d",&delnum);

    visited[0]=1;
    DFS(0);
	for(i=0;i<n;i++)
	{
		visited[i]=0;
	} 
    printf("\n");

    visited[0]=1;
    BFS();
    for(i=0;i<n;i++)
	{
		visited[i]=0;
	} 
    printf("\n");
    visited[delnum]=1;
    visited[0]=1;
    DFS(0);
    for(i=0;i<n;i++)
	{
		visited[i]=0;
	} 
    printf("\n");
    visited[delnum]=1;
    visited[0]=1;
    BFS();

    return 0;
}


