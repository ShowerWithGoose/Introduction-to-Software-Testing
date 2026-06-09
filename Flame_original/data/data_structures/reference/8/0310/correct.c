#include<stdio.h>
#include<stdlib.h>
#include<ctype.h> 
#include<string.h>
int n,m,a[220][220];
int array1[220],flag,array2[220];
void dfs(int tmp)
{
	int i;
	if(!flag)	printf("%d",tmp),flag=1;
	else	printf(" %d",tmp);
	array1[tmp]=1;
	for(i=1;i<=n;i++)
		if(a[tmp][i])
			if(!array1[i])
				dfs(i);
}
void bfs(int t)
{
	array2[1]=t;
	int i,temp,l=1,r=1;
	while(l<=r)
	{
		temp=array2[l];
		l++;
		if(array1[temp])	continue;
		if(!flag)	printf("%d",temp), flag=1;
		else	printf(" %d",temp);
		array1[temp]=1;
		for(i=1;i<=n;i++)
			if(a[temp][i])
				if(!array1[i])
					array2[++r]=i;
	}
	memset(array1,0,sizeof(array1));
}
int main()
{
	scanf("%d%d",&n,&m);
	int i,b,c;
	for(i=1;i<=m;i++){
		scanf("%d%d",&b,&c);
		a[b][c]=1;
		a[c][b]=1;
	}
	flag=0;
	dfs(0);
	printf("\n");
	flag=0;
	memset(array1,0,sizeof(array1));
	bfs(0);
	printf("\n");
	scanf("%d",&i);
	flag=0;
	array1[i]=1;
	dfs(0);
	printf("\n");
	memset(array1,0,sizeof(array1));
	flag=0;
	array1[i]=1;
	bfs(0);
	printf("\n");
	return 0;
}



