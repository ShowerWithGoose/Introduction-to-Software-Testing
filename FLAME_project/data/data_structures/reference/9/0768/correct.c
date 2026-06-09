#include<stdio.h>
#define N 110
int a[N],b[N],c[N],d[N],n,m,x,y;
void dfs(int p,int s);
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) 
		scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
	for(int i=0;i<n;i++) 
		dfs(i,1);
	printf("%d %d %d",m,x,y);
	return 0;
}
void dfs(int p,int s)
{
 	if(s>m)
	{
	  	m=s;
	  	x=a[p];y=b[p];
 	}
 	for(int i=0;i<n;++i)
	 	if(a[p]==c[i]&&b[p]==d[i])
			dfs(i,s+1);
}
