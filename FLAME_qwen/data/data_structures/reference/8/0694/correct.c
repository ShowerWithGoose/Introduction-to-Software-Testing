#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int number_of_ver,number_of_edge;
int map[110][110];
int visited[110];
int quene[110];
int top=-1,location=0;
void DFS(int i)
{
	visited[i]=1;
	printf("%d ",i);
	for(int j=0;j<number_of_ver;j++)
	{
		if(map[i][j]==1&&visited[j]==0){DFS(j);}
	}
}
void BFS(int i)
{
	if(visited[i]==0)
	{visited[i]=1;printf("%d ",i);quene[++top]=i;}
	for(int j=0;j<number_of_ver;j++)
	{
		if(map[i][j]==1&&visited[j]==0)
		{
			visited[j]=1;printf("%d ",j);
			quene[++top]=j;
		}
	}
	if(location<top)
	{BFS(quene[++location]);}
}
int main()
{
	scanf("%d%d",&number_of_ver,&number_of_edge);
	for(int i=0;i<number_of_edge;i++)
	{
		int startver,endver;
		scanf("%d%d",&startver,&endver);
		map[startver][endver]=1;map[endver][startver]=1;
	}
	int deletever;
	scanf("%d",&deletever);
	for(int i=0;i<number_of_ver;i++)//删除前深度优先 
	{
		if(visited[i]==0){DFS(i);}
	}
	printf("\n");
	for(int i=0;i<number_of_ver;i++){visited[i]=0;}
	for(int i=0;i<number_of_ver;i++)//删除前广度优先 
	{
		if(visited[i]==0){BFS(i);}	
	}
	printf("\n");
	for(int i=0;i<number_of_ver;i++){map[i][deletever]=0;map[deletever][i]=0;}
	for(int i=0;i<number_of_ver;i++){visited[i]=0;}
	visited[deletever]=1;
	for(int i=0;i<number_of_ver;i++){quene[i]=0;}
	for(int i=0;i<number_of_ver;i++) 
	{
		if(visited[i]==0){DFS(i);}
	}
	printf("\n");
	for(int i=0;i<number_of_ver;i++){visited[i]=0;}
	visited[deletever]=1;
	for(int i=0;i<number_of_ver;i++)//删除前广度优先 
	{
		if(visited[i]==0){BFS(i);}	
	}
}
/*9 9
0 1
1 2
2 3
3 4
2 6
0 5
5 6
6 7
7 8
1*/

