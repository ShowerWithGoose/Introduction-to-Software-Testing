#include<stdio.h>
#include<string.h>
int n,cnt,head,tail;
int a[200][200],b[200],c[200],q[200];
void DFS(int x);
void BFS(int x);
void print();
int main()
{
	int i=0;
	int m,x,y;
	scanf("%d%d",&n,&m);
	//做图
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		a[x][y]=a[y][x]=1; 
	}
	DFS(0);
	print();
	BFS(0);
	print();
	
	scanf("%d",&x);
	//删除点
	for(i=0;i<n;i++)
	{
		a[x][i]=a[i][x]=0;
	}
	DFS(0);
	print();
	BFS(0);
	print();
	return 0;
}
void DFS(int x)
{   int i=0;
	if(x==0)
	{
		b[0]=1;
		c[0]=0;
	}
	for(i=0;i<n;i++)
	{
		if(a[x][i]==1&&b[i]==0)
		{
			b[i]=1;
			c[++cnt]=i;
			DFS(i);
		}
	}
	return;
}
void BFS(int x)
{   int i=0;
	if(x==0)
	{
		b[0]=1;
		c[0]=0;
	}
	for(i=0;i<n;i++)
	{
		if(a[x][i]==1&&!b[i])
		{
			b[i]=1;
			c[++cnt]=i;
			q[++tail]=i;
		}
	}
	while(head<=tail)
	{
		BFS(q[head++]);
	}
	return;
}
void print()
{   int i=0;
	for(i=0;i<=cnt;i++)
	{
		printf("%d ", c[i]);
	}
	printf("\n");
	//初始化
	tail=-1;
	cnt=head=0;
	memset(c,0,sizeof(c));
	memset(b,0,sizeof(b));
	return;
}

