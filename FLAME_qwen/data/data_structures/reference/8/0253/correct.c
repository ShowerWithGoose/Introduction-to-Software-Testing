#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>
int a[105][105],v[105],q[105];
int n,x,y,z,m;
void dfs(int d)
{
	printf("%d ",d);
	v[d]=1;
	for(int i=0;i<n;i++)
	if(!v[i]&&a[d][i]) dfs(i);
}
void bfs(int b)
{
	int h=0,t=1,temp;
	q[h]=b;
	while(h<t)
	{
		temp=q[h];
		h++;
		if(v[temp]) continue;
		else
		{
			printf("%d ",temp);
			v[temp]=1;
			for(int i=0;i<n;i++)
			if(!v[i]&&a[temp][i]) q[t++]=i;
		}
	}
}
int main()
{
	scanf("%d%d",&n,&x);
	for(int i=1;i<=x;i++)
	{
		scanf("%d%d",&y,&z);
		a[z][y]=1;a[y][z]=1;
	}
	scanf("%d",&m);
	dfs(0);printf("\n");
	memset(v,0,sizeof(v));
	bfs(0);printf("\n");
	memset(v,0,sizeof(v));memset(q,0,sizeof(q));
	v[m]=1;
	dfs(0);printf("\n");
	memset(v,0,sizeof(v));
	v[m]=1;
	bfs(0);
}

