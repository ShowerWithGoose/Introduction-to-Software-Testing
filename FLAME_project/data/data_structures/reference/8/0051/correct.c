//7_1
#include <stdio.h>
int vis[102],n,m,con[102][102],b[102],front,rare;
void dvis(int num)
{
	printf("%d ",num);
	for(int i=1;i<n;i++)
	{
		if(!vis[i]&&con[num][i])
		{
			vis[i]=1;
			dvis(i);
		}
	}
	return;
}

int main(int argc, char const *argv[])
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		con[a][b]=1;
		con[b][a]=1;
	}
	for(int i=0;i<n;i++) vis[i]=0;
	dvis(0);
	printf("\n");
	for(int i=0;i<n;i++) vis[i]=0;
	front=0;
	rare=0;
	b[0]=0;
	while(front<n)
	{
		for(int i=front;i<rare+1;i++)
		{
			printf("%d ",b[i]);
			for(int j=1;j<n;j++)
			{
				if(!vis[j]&&con[j][b[i]])
				{
					vis[j]=1;
					b[++rare]=j;
				}
			}
			front++;
		}
	}
	printf("\n");
	int del;
	scanf("%d",&del);
	for(int i=0;i<n;i++)
	{
		con[del][i]=0;
		con[i][del]=0;
	}
	for(int i=0;i<n;i++) vis[i]=0;
	dvis(0);
	printf("\n");
	for(int i=0;i<n;i++) vis[i]=0;
	front=0;
	rare=0;
	b[0]=0;
	while(front<n-1)
	{
		for(int i=front;i<rare+1;i++)
		{
			printf("%d ",b[i]);
			for(int j=1;j<n;j++)
			{
				if(!vis[j]&&con[j][b[i]])
				{
					vis[j]=1;
					b[++rare]=j;
				}
			}
			front++;
		}
	}
	printf("\n");
	return 0;
}
