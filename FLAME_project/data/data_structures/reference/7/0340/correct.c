#include<stdio.h>
#include<string.h>
int a[11000];
int son[11000][2];
void ins(int x,int t)
{
	if(a[x]<=a[t])
	{
		if(son[x][1]==0)
		{
			son[x][1]=t;
		}
		else ins(son[x][1],t);
	}
	else
	{
		if(son[x][0]==0)
		{
			son[x][0]=t;
		}
		else ins(son[x][0],t);
	}
}
void print(int x,int dep)
{
	if(son[x][0]==0&&son[x][1]==0) printf("%d %d\n",a[x],dep);
	else
	{
		if(son[x][0]!=0) print(son[x][0],dep+1);
		if(son[x][1]!=0) print(son[x][1],dep+1);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	memset(son,0,sizeof(son));
	for(int i=2;i<=n;i++) ins(1,i);
	print(1,1);
	return 0;
}

