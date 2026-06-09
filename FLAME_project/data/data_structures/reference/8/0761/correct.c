#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int p,q,sort[105][105],n[105],m[105],count;
void f(int x);
void g(int t);
int main()
{
	scanf("%d%d", &p, &q);
	int i;
	for(i=1;i<=q;i++)
	{
		int x, y;
		scanf("%d%d",&x,&y);
		sort[x][y] = 1;
		sort[y][x] = 1;
	}
	count=0;
	f(0);printf("\n");
	memset(n,0,sizeof(n));
	count=0;
	g(0);printf("\n");
	scanf("%d",&i);
	n[i]=1;
	count=0;
	f(0);printf("\n");
	memset(n,0,sizeof(n));
	n[i]=1;
	count=0;
	g(0);printf("\n");
}
void f(int x)
{
	if(count==0)
	printf("%d",x),count=1;
	else
	printf(" %d",x);
	n[x]=1;
	int i;
	for(i=1;i<=p;i++)
	{
		if(sort[x][i])
		{
		 if(n[i]==0) f(i);
		}
	}	
}
void g(int t)
{
	m[1]=t;
	int l=1,r=1,i;
	while(l<=r)
	{
		int x=m[l];
		l++;
		if(n[x]) continue;
		if (count==0)
		printf("%d", x),count=1;
		else
		printf(" %d",x);
		n[x]=1;
		for(i=1;i<=p;i++)
		{
			if(sort[x][i])
			{
				if(n[i]==0)
				m[++r]=i;
			}
		}
	}
	memset(n,0,sizeof(n));
}

