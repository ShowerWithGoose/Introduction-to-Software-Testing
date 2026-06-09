#include<stdio.h>
#include<stdlib.h>
int G[105][105]={0};//G[0][0] 0点存储的节点数量
int visited[105]={0};
int delnum=102;
int count_p=0,count_e=0;

void del(int m,int n) //删除G[m]中编号为n的点 
{
	int i=1;
	for(;i<=G[m][0]&&G[m][i]!=n;i++);
	G[m][0]--;
	for(int k=i;k<=G[m][0];k++) G[m][k]=G[m][k+1];
	return;
}

void DFS(int v)
{
	visited[v]=1;
	printf("%d ",v);
	for(int i=1;i<=G[v][0];i++)
		if(!visited[G[v][i]])
			DFS(G[v][i]);   
}

void travelDFS(void)
{
	for(int i=0;i<count_p;i++) visited[i]=0;
	visited[delnum]=1;
	for(int i=0;i<count_p;i++)
		if(!visited[i])//&&G[i][0]!=0
			DFS(i);
}

int qu[201]={0};
int head=0,tail=-1;
void enqu(int en)
{
	tail++;
	if(tail>200) tail-=200;
	qu[tail]=en;
	return;
}

int dequ(void)
{
	int n=qu[head];
	head++;
	if(head>200) head-=200;
	return n;
}

void BFS(int v)
{
	visited[v]=1;
	printf("%d ",v);
	enqu(v);
	while(tail!=head-1)
	{
		int test;
		v=dequ();
		test=v;
		for(int i=1;i<=G[v][0];i++)
		{
			int pt=G[v][i];
			if(!visited[pt])
			{
				printf("%d ",pt);
				visited[pt]=1;
				enqu(pt);
			}
		}
	}
	return;
}

void travelBFS(void)
{
	for(int i=0;i<count_p;i++) visited[i]=0;
	visited[delnum]=1;
	for(int i=0;i<count_p;i++)
		if(!visited[i])//&&G[i][0]!=0
			BFS(i);
}

int cmp(const void *_a, const void *_b)
{
	int *a=(int*)_a,*b=(int *)_b;
	return *a-*b;
}

int main()
{
	scanf("%d%d",&count_p,&count_e);
  	for(int i=1;i<=count_e;i++)
	{
		int m,n;
		scanf("%d %d",&m,&n);
		G[m][++G[m][0]]=n;
		G[n][++G[n][0]]=m;
		
	}
	
	//排序，编号从小到大
	for(int i=0;i<count_p;i++)
	{
		int first=G[i][0];
		G[i][0]=0;
		qsort(G[i],first+1,sizeof(G[i][0]),cmp);
		G[i][0]=first;
	}
	
	travelDFS();
	printf("\n");
	travelBFS();
	printf("\n");
	
	//删除后 
	scanf("%d",&delnum);
	for(int i=1;i<=G[delnum][0];i++)
	{
		int pt=G[delnum][i];
		del(pt,delnum);
	}
	G[delnum][0]=0;

	travelDFS();
	printf("\n");
	travelBFS();
	printf("\n");

	return 0;
}

