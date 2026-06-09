#include<stdio.h>
int flag1=0;
int visit1[100]={0};
void DFS(int A[][100],int n,int v,int m)
{
	int i,j,k;
	flag1++;
	if(flag1<m) printf("%d ",v);
	else printf("%d\n",v);
	visit1[v]=1;
	int w;
	for(j=0;j<n;j++)
	{
		if(A[v][j]==1&&visit1[j]==0)
		{
			w=j;
			DFS(A,n,w,m);
		}
	}
}
void BFS(int A[][100],int n,int v,int m)
{
	int D[100],l,r,j;
	int w;
	flag1++;
	if(flag1<m) printf("%d ",v);
	else printf("%d\n",v);
	visit1[v]=1;
	l=0;r=0;D[l]=v;
	for(;l<=r;)
	{
		v=D[l];
		l++;
		for(j=0;j<n;j++)
		{
			if(A[v][j]==1&&visit1[j]==0)
			{
				flag1++;
				if(flag1<m) printf("%d ",j);
				else printf("%d\n",j);
				visit1[j]=1;
				D[++r]=j;
			}
		}
	}
	
}
int main()
{
	int n,m,A[100][100];
	scanf("%d %d",&n,&m);
	int v1,v2,i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			A[i][j]=0;
			A[j][i]=0;
		}
	}
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&v1,&v2);
		A[v1][v2]=1;
		A[v2][v1]=1;
	}
	int vd;
	scanf("%d",&vd);
	DFS(A,n,0,n);
	for(i=0;i<n;i++) visit1[i]=0; flag1=0;
	BFS(A,n,0,n);for(i=0;i<n;i++) visit1[i]=0; flag1=0;
	for(i=0;i<n;i++)
	{
		A[i][vd]=0;
	}
	for(j=0;j<n;j++)
	{
		A[vd][j]=0;
	}
	DFS(A,n,0,n-1);	for(i=0;i<n;i++) visit1[i]=0; flag1=0;
	BFS(A,n,0,n-1); visit1[i]=0; flag1=0;
		
	
	return 0;
 } 

