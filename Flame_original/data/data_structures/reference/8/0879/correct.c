#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int graph[105][105];
int queue[105], rear = -1, front = 0, flag[105];
int stack[105], top = -1;
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int t1, t2;
	for(int i = 0; i < m; i++)
	{
		scanf("%d%d", &t1, &t2);
		graph[t1][t2] = graph[t2][t1] = 1;
	}
	
	stack[++top] = 0;
	while(top > -1)
	{
		int temp = stack[top];
		if(!flag[temp])
		{
			if(temp)
			printf(" %d", temp);
			else
			printf("%d", temp);			
			flag[temp] = 1;
		}
		for(int i = 0; i < n; i++)
		{
			if(graph[temp][i] && !flag[i])
			{
				stack[++top] = i;
				break;
			}
		}
		if(temp == stack[top])
		{
			top--;
		}
	}
	printf("\n");	
	
	memset(flag, 0, sizeof(flag));	
	printf("0");
	for(int i = 1; i < n; i++)
	{
		if(graph[0][i] && !flag[i])
		{
			queue[++rear] = i;
			flag[i] = 1;
		}
	}
	while(rear >= front)
	{
		int temp = queue[front++];
		printf(" %d", temp);
		for(int i = 1; i < n; i++)
		{
			if(graph[temp][i] && !flag[i])
			{
				queue[++rear] = i;
				flag[i] = 1;
			}
		}		
	}
	printf("\n");
	
	
	scanf("%d", &t1);
	for(int i = 0; i < n; i++)
	{
		graph[t1][i] = graph[i][t1] = 0;
	}
	
	memset(flag, 0, sizeof(flag));
	top = -1;	
	stack[++top] = 0;
	while(top > -1)
	{
		int temp = stack[top];
		if(!flag[temp])
		{
			if(temp)
			printf(" %d", temp);
			else
			printf("%d", temp);			
			flag[temp] = 1;
		}
		for(int i = 0; i < n; i++)
		{
			if(graph[temp][i] && !flag[i])
			{
				stack[++top] = i;
				break;
			}
		}
		if(temp == stack[top])
		{
			top--;
		}
	}
	printf("\n");
	
	memset(flag, 0, sizeof(flag));
	printf("0");
	for(int i = 1; i < n; i++)
	{
		if(graph[0][i] && !flag[i])
		{
			queue[++rear] = i;
			flag[i] = 1;
		}
	}
	while(rear >= front)
	{
		int temp = queue[front++];
		printf(" %d", temp);
		for(int i = 1; i < n; i++)
		{
			if(graph[temp][i] && !flag[i])
			{
				queue[++rear] = i;
				flag[i] = 1;
			}
		}		
	}	
			
}

