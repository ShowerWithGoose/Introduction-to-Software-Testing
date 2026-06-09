#include<stdio.h>
int a[105][105],b[105],c[105],left,right;
void DFS(int k,int n)
{
	if(b[k]==1)
	{
		printf("%d ",k);
		b[k]=0;
	}
	for(int i=0;i<n;i++)
	{
		if(a[k][i]&&b[i]) DFS(i,n);
	}
}
void BFS(int k,int n)
{
	if(b[k]==1)
	{
		printf("%d ",k);
		b[k]=0;
	}
	for(int i=0;i<n;i++)
	{
		if(a[k][i]==1&&b[i]) c[++right]=i;
	}
	if(left<right) BFS(c[++left],n);
}
int  main()
{
	int n,m,i,x,y,key;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		a[x][y]=1;
		a[y][x]=1;
	}
	for(i=0;i<n;i++) b[i]=1;
	DFS(0,n);
	printf("\n");
	for(i=0;i<n;i++) b[i]=1;
	c[0]=0;
	left=0;
	right=0;
	BFS(0,n);
	printf("\n");
	scanf("%d",&key);
	for(i=0;i<n;i++)
	{
		a[key][i]=0;
		a[i][key]=0;
	}
	for(i=0;i<n;i++) b[i]=1;
	DFS(0,n);
	printf("\n");
	for(i=0;i<n;i++) b[i]=1;
	c[0]=0;
	left=0;
	right=0;
	BFS(0,n);
	printf("\n");
	return 0;
}

