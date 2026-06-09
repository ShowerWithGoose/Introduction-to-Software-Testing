#include<stdio.h> 
#include<string.h>			
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<malloc.h>
int a[105][105]={0},record[105]={0},Record[105]={0},n,m;
void DFS(int);
void BFS(int);
int main(){
	int i,j,x;
	scanf("%d %d",&m,&n);
	for(x=0;x<n;x++)
	{
		scanf("%d %d",&i,&j);
		a[i][j]=1;
		a[j][i]=1;
	} 
	DFS(0);
	printf("\n");
	for(x=0;x<101;x++){
		record[x]=0;
	}
	BFS(0);
	for(x=0;x<101;x++){
		record[x]=0;
	}
	scanf("%d",&x);
	record[x]=1;
	DFS(0);
	printf("\n");
	for(i=0;i<101;i++){
		record[i]=0;
	}record[x]=1;
	BFS(0);
	return 0;
}
//º¯Êý±¾Ìå
void DFS(int b)
{
	printf("%d ",b);
	record[b]=1;
	for(int i=1;i<=m;i++)
	{
		if(a[b][i]==1&&record[i]==0)
		{
			DFS(i);
		}
	}
} 
void BFS(int b)
{
	int p;
	Record[1]=b;
	for(int j=1,r=1;j<=r;)
	{
		p=Record[j++];
		if(record[p]==1)
		{
			continue;
		}
		printf("%d ",p);
		record[p]=1;
		for(int i=1;i<=m;i++)
		{
			if(a[p][i]==1&&record[i]==0)
			{
				Record[++r]=i;
			}
		}
	}
	printf("\n");
}

