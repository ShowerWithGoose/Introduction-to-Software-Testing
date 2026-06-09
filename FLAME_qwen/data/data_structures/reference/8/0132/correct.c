#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int pic[110][110];
int flag[110];
int n,m;

void dfs(int start)
{
	flag[start]=1;
	printf("%d ",start);
	int i;
	for(i=0;i<n;i++)
	{
		if(flag[i]==0&&pic[start][i]==1)
		{
			dfs(i);
		}
	}
}

int forbfs[110],topbfs=-1;

void bfs(int depth)
{
	if(depth>topbfs) return;
	
	int start=forbfs[depth];
	
	if(flag[start]==0)
	{
		flag[start]=1;
		printf("%d ",start);
    }
    
    int i;
    for(i=0;i<n;i++)
    {
    	if(flag[i]==0&&pic[start][i]==1)
		{
			flag[i]=1;
			printf("%d ",i);
			forbfs[++topbfs]=i;
		}
	}
	bfs(depth+1);
}

int main()
{
	//freopen("damn.txt","r",stdin);//
	
	memset(pic,0,sizeof(pic));
	
	scanf("%d %d",&n,&m);
	int i;
	
	for(i=0;i<m;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		pic[x][y]=1;
		pic[y][x]=1;
	}
	
	memset(flag,0,sizeof(flag));
	dfs(0);
	printf("\n");
	
	memset(flag,0,sizeof(flag));
	memset(forbfs,0,sizeof(forbfs));
	topbfs=0;forbfs[0]=0; 
	bfs(0);
	printf("\n");
	
	int fordel;
	scanf("%d",&fordel);
	for(i=0;i<n;i++)
	{
		pic[fordel][i]=0;
		pic[i][fordel]=0;
	}
	
	memset(flag,0,sizeof(flag));
	dfs(0);
	printf("\n");
	
	memset(flag,0,sizeof(flag));
	memset(forbfs,0,sizeof(forbfs));
	topbfs=0;forbfs[0]=0; 
	bfs(0);
	printf("\n");
	
	
	
	return 0;
}















