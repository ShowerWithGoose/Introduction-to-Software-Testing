#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>

int a[110][110],visited[110] = {0};

int t1 = 0,t2 = 0;

void deep(int begin,int n)
{
	int i = 0;
	visited[begin] = 1;
	printf("%d ",begin);
	for(i = 0;i < n;i ++)
	{
		if(visited[i] == 0 && a[begin][i] == 1)
		{
			deep(i,n);
		}
	}
}

	int q[110] = {0};
	int front = 0,rear = 0;
void wide(int begin,int n)
{
	int now = 0,i;
	q[rear++] = begin;
	
	while(front <= rear)
	{	//printf("aaaaa\n");
		now = q[front++];//³ö¶Ó 
		if(visited[now])
		{
			continue; 
		}
		
		printf("%d ",now);
		visited[now] = 1;
		for(i = 0;i < n;i ++)
		{
			if(visited[i] == 0 && a[now][i] == 1)
			{
				q[rear++] = i;
				
			}
		}
	}		
}

void dele(int i,int n)
{
	int j = 0;
	for(j = 0;j < n;j ++)
	{
		a[i][j] = 0;
		a[j][i] = 0;
		
	 }

}

int main()
{
	int nv,ne;
	
	scanf("%d %d\n",&nv,&ne);
	
	int i = 0;
	int begin,end;
	
	for(i = 0;i < ne;i ++)
	{
		scanf("%d %d\n",&begin,&end);
		a[begin][end] = 1;
		a[end][begin] = 1;
	}
	int del;
	scanf("%d",&del);
	
	deep(0,nv);
	printf("\n");
	for(i = 0;i < 110;i ++)
	{
		visited[i] = 0;
	}
	wide(0,nv);
	printf("\n");
	for(i = 0;i < 110;i ++)
	{
		visited[i] = 0;
	}	
	dele(del,nv);
	
	//nv--;
	deep(0,nv);
	printf("\n");
	printf("pppp\n");
	for(i = 0;i < 110;i ++)
	{
		visited[i] = 0;
	}
	wide(0,nv);
	printf("\n");
	
	return 0;
}

