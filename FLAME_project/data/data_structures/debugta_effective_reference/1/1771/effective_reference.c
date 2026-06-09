#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define ll long long 
#define ull unsigned long long
int read()
{
	int x=0,fl=1;char st=getchar();
	while(st<'0'||st>'9'){ if(st=='-')fl=-1; st=getchar();}
	while(st>='0'&&st<='9') x=x*10+st-'0',st=getchar();
	return x*fl;
}
int ar[15];
int st[15];
int n;
void dfs(int x)
{
	if(x==n+1)
	{
		for(int i=1;i<=n;i++)
			printf("%d ",ar[i]);
		printf("\n");
		return ;
	}
	for(int i=1;i<=n;i++)
		if(st[i]==0)
		{
			ar[x]=i;
			st[i]=1;
			dfs(x+1);
			st[i]=0;
		}
}
int main()
{
	n=read();
	dfs(1);
	return 0;	
}

