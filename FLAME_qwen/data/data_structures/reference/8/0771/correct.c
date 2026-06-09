#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
struct Tree
{ 
    int n;
    char o;
    struct Tree *l;
    struct Tree *r;
};
struct trees
{ 
    struct Tree tree[502];
    int top;
} to;
struct Tree *u, *v, *w;
int a,b;
int t[120],mark,q[120];
void dfs(int x);
void bfs(int y);
 int s[120][120];
int main()
{
	int str[100];
	int x,y;
		int i,j,k=0;
	scanf("%d%d",&a,&b);
	for (i=1;i<=b;i++)
	{
		str[j++]=1;
		scanf("%d%d", &x, &y);
		s[x][y]=1;
		s[y][x]=1;
	}
	mark=0;
	k=0;
	for (j=0;j<b;j++)
	{
		str[j]=0;
		k++;
		
	}
	dfs(0);
	printf("\n");
	memset(t,0,sizeof(t));
	k=0;
	mark=0;
	for (j=0;j<b;j++)
	{
		k--;
		str[j]=0;
		
	}
	bfs(0);
	printf("\n");
	scanf("%d", &i);
	t[i]=1;
	mark=0;
	for(j=0;j<b;j++)
	{
		str[j]=0;
		k++;
		
	}
	dfs(0);
	printf("\n");
	memset(t,0,sizeof(t));
	t[i]=1;
	mark=0;
	for(j=0;j<b;j++)
	{
		k--;
		str[j]=0;
		
	}
	bfs(0);
	printf("\n");
	return 0;
}
void dfs(int x)
{
		int i,j,k;
	if(mark==0)
	{
		printf("%d", x);
		 mark=1;
	}	
	else if(mark!=0)
		printf(" %d", x);
	t[x]=1;
	j=0;
	for(i=1;i<=a;i++)
		if(s[x][i]==1)
		{
			if(t[i]==0)
			{
				dfs(i);
				k=0;
			}
			else continue;
			k++;
		}
}
void bfs(int y)
{
	q[1]=y;
	int le=1;
	int ri=1;
	int i,j,k;
	while (le<=ri)
	{
		int x=q[le++];
		if (t[x]==1)
			{
				continue;
				j=0;
			}
			j++;
		if (mark==0)
		{
				printf("%d",x);
				mark= 1;
		}
		else
			printf(" %d", x);

		t[x]=1;
		for (i=1;i<=a;i++)
			if(s[x][i]==1)
			{
				if (t[i]==0)
					q[++ri]=i;
					else 
					{
						continue;
						k=0;
					}
					k++;
			}
	}
	memset(t, 0, sizeof(t));
}

