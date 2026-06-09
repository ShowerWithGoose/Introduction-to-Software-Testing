#include<stdio.h>
int vis[21];int n,l;
char str[100];
void dfs()
{
	int i,fl=0;
	for(i=1;i<=n;i++)
	if(vis[i]==0)
	{
		if(i!=10)
			{
				str[l]=i-0+'0',str[++l]=' ';
				l++;vis[i]=1;dfs();l-=2;vis[i]=0;
			}
		else 
			{
				str[l]='1',str[++l]='0',str[++l]=' ';
				l++;vis[i]=1;dfs();vis[i]=0;l-=3;
			}
		fl=1;
	}
	if(!fl)printf("%s\n",str);
}
int main()
{
	scanf("%d",&n);
	dfs();
}


