#include<stdio.h>
#include<stdlib.h>
int edge[100][100];
void bfs();
void dfs();
int v,e;
int main()
{
	int i,a,b,j;
	scanf("%d %d",&v,&e);
	for(i=0;i<e;i++)
	{
		scanf("%d %d",&a,&b);
		edge[a][b]=1;
		edge[b][a]=1;
	}
	scanf("%d",&j);
	dfs();
	putchar('\n');
	bfs();
	putchar('\n');
	for(i=0;i<v;i++)
	{
		if(edge[j][i]==1)
		{
			edge[j][i]=0;
			edge[i][j]=0;
		}
	}
	dfs();
	putchar('\n');
	bfs();
	return 0;
}
void dfs()
{
	int i,j,s[100]={0},stack[1000]={0},top=0;
	j=0;
	s[0]=1;
	while(top>=0)
	{
		top--;
		s[j]=1;
		printf("%d ",j);
		for(i=v-1;i>=0;i--)
		{
			if(edge[j][i]==1&&s[i]==0)
			{
				top++;
				stack[top]=i;
			}
		}
		while(top>=0&&s[stack[top]])
		{
			top--;
		}
		j=stack[top];  
	}	
}
void bfs()
{
	int queue[101],front=0,rear=-1,i,j,s[100];
	rear++;
	queue[0]=0;
	memset(s,0,sizeof(s));
	s[0]=1;
	while(front<=rear)
	{
		j=queue[front++];
		printf("%d ",j);
		for(i=0;i<v;i++)
		{
			if(edge[j][i]==1&&s[i]==0)
			{
				s[i]=1;
				queue[++rear]=i;
			}
		}
	}
}

