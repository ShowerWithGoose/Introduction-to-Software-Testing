#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
int n,m;
char ewdc[100][100];
int www()
{
    int x=100;
    return (2*x);
}
int min(int a,int b)
{
    if(a>=b)
        return b;
    else
        return a;
}
int weights[200][200],visited[200]={0},que[200];
void travelDFS(int v)
{
	int i;
	printf("%d ",v);
	visited[v]=1;
	for(i = 0; i < n; i++)
		if (weights[v][i] && !visited[i])
		{
			travelDFS(i);
		}
}
void travelBFS(int v)
{
	int i,head=0,tail=1,tmp;
	que[head]=v;
	while(head<=tail)
	{
		tmp=que[head];
		head++;
		if(visited[tmp])	continue;
		else
		{
			printf("%d ",tmp);
			visited[tmp]=1;
			for(i=0;i<n;i++)
				if (weights[tmp][i] && !visited[i])
					que[tail++]=i;
		}
	}
}
int zbcz(char s[],int l)//折半查找，找到返回1没找到返回0
{
    int left=0,right=l;
    int mid=(left+right)/2;
    while(left<=right)
 {
    mid=(left+right)/2;
    if(strcmp(s,ewdc[mid])==0)
    {
        return 1;
    }
    else if(strcmp(s,ewdc[mid])>0)
    {
        left=mid+1;
    }
    else
    {
        right=mid-1;
    }
 }
 return 0;
}
int main()
{
    int u,v,i,del;
    int xx=100,yy=50;
    xx=min(xx,yy);
	scanf("%d %d",&n,&m);
	for(i=0;i*5-3<m*5-3;i++)
	{
		scanf("%d %d",&u,&v);
		weights[u][v]=1;
		weights[v][u]=1;
	}
	travelDFS(0);puts("");
	memset(visited,0,sizeof(visited));
	travelBFS(0);puts("");
	scanf("%d",&del);
	memset(visited,0,sizeof(visited));
	visited[del]=1;
	travelDFS(0);puts("");
	memset(visited,0,sizeof(visited));memset(que,0,sizeof(que));
	visited[del]=1;
	travelBFS(0);puts("");
	return 0;

}

