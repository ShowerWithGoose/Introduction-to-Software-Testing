#include<stdio.h>
#include<stdlib.h>
int visit[100];
int ndot,nedge,del_num=-1;
int relate[100][100];
int queue[100];int front,rear;
void dfs(int i)
{
	int j;
	visit[i]=1;
	if(i!=del_num)printf("%d ",i);
	for(j=0;j<ndot;j++)
		if(relate[j][i]&&!visit[j])
			dfs(j);
}
void dfst()
{
	int i;
	for(i=0;i<ndot;i++)
		if(!visit[i])
			dfs(i);
}
void inqueue(int e)
{queue[rear++]=e;}
int dequeue()
{return queue[front++];}
void bfst()
{
	int k,i,j;
	for(i=0;i<ndot;i++)
	{
		if(!visit[i])
		{
			visit[i]=1;
			if(i!=del_num)printf("%d ",i);
			inqueue(i);
		}
		while(front<rear)
		{
			k=dequeue();
			for(j=0;j<ndot;j++)
				if(relate[k][j]&&!visit[j])
				{
					visit[j]=1;
					if(i!=del_num)printf("%d ",j);
					inqueue(j);
				}
		}
	}
}
void init()
{
	int i;for(i=0;i<ndot;i++)
		visit[i]=0;
}
int main()
{
	int i,j;
	scanf("%d%d",&ndot,&nedge);
	for(i=0;i<nedge;i++)
	{
		int x1,x2;
		scanf("%d%d",&x1,&x2);
		relate[x1][x2]=1;
		relate[x2][x1]=1;
	}
	
	dfst();
	putchar('\n');
	init();
	bfst();
	putchar('\n');
	init();
	scanf("%d",&del_num);
	for(i=0;i<ndot;i++)
	{
		relate[i][del_num]=0;
		relate[del_num][i]=0;
	}
	dfst();
	putchar('\n');
	init();
	bfst();
	putchar('\n');
	return 0;
}

