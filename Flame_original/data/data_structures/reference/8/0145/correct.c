#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>
#define N 100
int visit[N] = {0};
int graph[N][N] = {0};
int v, e, de;
int temp[N] = {0};
void DFS(int V, int v)
{		 
	visit[V] = 1;
	printf("%d ", V);
	int i;
	for(i = 0; i < v; i++)
	{
		if(visit[i] == 0 && graph[V][i] == 1)
		{
			DFS(i, v);
		}
	}
}

void BFS(int V, int v)
{
    int front,rear,start,i;
    front = rear = 0;
    visit[V]=1;
    printf("%d ",V);
    temp[rear++] = V;
    while(rear>front){
        start = temp[front++];
        for(i = 0; i < v; i++){
            if(!visit[i] && graph[start][i]){
                visit[i] = 1;
                printf("%d ",i);
                temp[rear++] = i;
            }
        }
    }

}

int main()
{
	scanf("%d%d", &v, &e);

	int i, j, e1, e2;
	for(i = 0; i < e; i++)
	{
		scanf("%d%d", &e1, &e2);
		graph[e1][e2] = 1;
		graph[e2][e1] = 1;
	}
	scanf("%d",&de);
	DFS(0, v);
	printf("\n");
	for(i = 0; i < v; i++)
	{
		visit[i] = 0;
	}
	BFS(0, v);
	printf("\n");
	for(i = 0; i < v; i++)
	{
		visit[i] = 0;
		graph[i][de] = 0;
		graph[de][i] = 0;
	} 
	DFS(0, v);
	printf("\n");
	
	for(i = 0; i < v; i++)
	{
		visit[i] = 0;
	}
	BFS(0, v);
	printf("\n");
	
	return 0;	
}

