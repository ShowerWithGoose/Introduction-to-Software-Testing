#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int ver[105][105]={0},vnum=0,bnum=0; 

void dfs(int *visited,int start)
{
	int i=0,j=0;
	printf("%d ",start);
	visited[start]=1;
	while(i<vnum)
	{
		for(j=0;j<vnum;j++)
		if(ver[start][j]==1&&visited[j]==0)
		dfs(visited,j);
		i++;
	}
	
}

void wfs(int *visited,int start)
{
	int queue[105]={0},head=0,tail=1,i=0,j=0;
	queue[head]=start;
	while(head<tail)
	{
		printf("%d ",queue[head]);
		visited[queue[head]]=1;
		for(j=0;j<vnum;j++)
		{
			if(ver[queue[head]][j]==1&&visited[j]==0)
			{
				queue[tail]=j;
				tail++;
				visited[j]=1;
			}
		}
		head++;
	}
}
int main(int argc, char *argv[]) {
	scanf("%d %d",&vnum,&bnum);
	int c,d,dele;
	while(bnum--)
	{
		scanf("%d %d",&c,&d);
		ver[c][d]=1;
		ver[d][c]=1;
	}
	scanf("%d",&dele);
	
	int visited[105]={0};
	dfs(visited,0);
	printf("\n");
	
	for(c=0;c<vnum;c++)
	visited[c]=0;
	wfs(visited,0);
	printf("\n");
	
	for(c=0;c<vnum;c++)
	{
		visited[c]=0;
		ver[dele][c]=0;
		ver[c][dele]=0;
	}
	dfs(visited,0);
	printf("\n");
	
	for(c=0;c<vnum;c++)
	visited[c]=0;
	wfs(visited,0);
	printf("\n");
	return 0;
}

