#include<stdio.h>
int point,edge;
int a[1000][1000];
int find1[1000]; 
int find2[1000];
int find3[1000];
int find4[1000];
void DFS(int n,int *find)
{
	find[n]=1;//表示遍历了这个 
	printf("%d ",n);
	int i;
	for(i=0;i<edge;i++)
	{
		if(find[i]==0&&a[n][i]==1)//find[i]！=0，则这个点没被遍历
		DFS(i,find); //a[n][i]表示这个点有边可以继续遍历 
	}
}
int dui[1000];
int first=0;
int end=0;
void BFS(int n,int *find)
{
	dui[first++]=n;
	find[n]=1;
	while(first-end>0)//队伍里面还有人 
	{
		n=dui[end++];
		printf("%d ",n);
		int i;
		for(i=0;i<edge;i++)
		{
			if(a[n][i]==1&&find[i]==0)
			{
				dui[first++]=i;
				find[i]=1;
			}
		}
	}
}
int main()
{
	scanf("%d%d",&point,&edge);
	int i=0,j=0; 
	int x,y;
	for(i=0;i<edge;i++)
	{
		scanf("%d%d",&x,&y);
		a[x][y]=1;
		a[y][x]=1;
	}
	int delete;
	scanf("%d",&delete); 
	DFS(0,find1);
	printf("\n");
	BFS(0,find2);
	printf("\n"); 
	for(i=0;i<edge;i++)
	{
		a[delete][i]=0;
		a[i][delete]=0;
	}
	DFS(0,find3);
	printf("\n");
	BFS(0,find4);
	printf("\n");
	return 0;
}


