#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>
#define MAXSIZE 102
int photo[102][102];
int visited[102];
int queue[102];
int sum;
int head;
int rear;
void dfs(int photo[102][102],int i,int x)
{
	int j;
	printf("%d ",i);
	visited[i]=1;
	for(j=0;j<x;j++)
	{
		if(photo[i][j]==1)
		{
			if(visited[j]==0)
			{
				dfs(photo,j,x);
			}
		}
	}

}
void bfs(int photo[102][102],int i,int x)
{
    head = 0;
    rear = 0;
    
    visited[0] = 1;
	queue[rear] = 0;
    rear++;
    while (head < rear)
    {
        for (i = 0; i < x; i++)
        {
            if (photo[queue[head]][i] == 1 && visited[i] == 0)
            {
                queue[rear] = i;
                rear++;
                visited[i] = 1;
            }
            if (rear >= x)
            {
                break;
            }
        }
        head++;
    }
    for (i = 0; i < rear; i++)
    {
        printf("%d ", queue[i]);
    }
    return ;
}

int main() 
{
	int n,m;
	int a,b;
	int x;
	int i;
	scanf("%d %d\n",&n,&m);
	while(m--)
	{
		scanf("%d %d",&a,&b);
		photo[a][b]=1;
		photo[b][a]=1;
	}
	scanf("%d",&x);
	visited[0]=1;
	dfs(photo,0,n);
	for(i=0;i<n;i++)
	{
		visited[i]=0;
	}
	printf("\n");
	sum=0;
	bfs(photo,0,n);
	for(i=0;i<n;i++)
	{
		visited[i]=0;
	}
	for(i=0;i<n;i++)
	{
		queue[i]=0;
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		photo[i][x]=0;
		photo[x][i]=0;
	}
	dfs(photo,0,n);
	for(i=0;i<n;i++)
	{
		visited[i]=0;
	}
	printf("\n");
	sum=0;
	bfs(photo,0,n);
	for(i=0;i<n;i++)
	{
		visited[i]=0;
	}
	for(i=0;i<n;i++)
	{
		queue[i]=0;
	}
}

