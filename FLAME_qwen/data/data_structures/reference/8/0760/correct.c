#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int n,m,tu[110][110],f,visit[110],t[110];
void DFS(int k)
{
	int l;
	if(!f)
	printf("%d",k),f=1;
	else
	printf(" %d",k);
	visit[k]=1;
	for(l=0;l<n;l++)
	{
		if(tu[k][l])
		{
			if(!visit[l])
			{
				DFS(l);
			}
		}
	}
}
void BFS(int r)
{
	int a=1,b=1,c,d,o;
	t[1]=r;
	while(a<=b)
	{
		d=t[a];
		a++;
		if(visit[d])
		continue;
		if(!f)
		printf("%d",d),f=1;
		else
		printf(" %d",d);
		visit[d]=1;
		for(c=1;c<=n;c++)
		{
			if(tu[d][c])
			{
				if(!visit[c])
				t[++b]=c;
			}
		}
	}
	for(o=0;o<105;o++)
	visit[o]=0;
}
int main()
{
	int i,p,q,e;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&p,&q);
		tu[p][q]=1;
		tu[q][p]=1;
	}
	scanf("%d",&e);
	f=0;
	DFS(0);
	printf("\n");
	for(i=0;i<105;i++)
	visit[i]=0;
	f=0;
	BFS(0);
	printf("\n");
	visit[e]=1;
	f=0;
	DFS(0);
	printf("\n");
	for(i=0;i<105;i++)
	visit[i]=0;
	visit[e]=1;
	f=0;
	BFS(0);
	return 0;
}

