#include<stdio.h>
#include<string.h>
#define maxn 100

typedef struct{
	int x1;int y1;
	int x2;int y2;
}line;

line lines[maxn];
int vis[maxn];
int ans[maxn];
int length;
line linemax;
int n;

void dfs(line* temp)
{
	for(int i=0;i<n;i++)
	{
		if(!vis[i])
		{
			if(temp->x1==lines[i].x1&&temp->y1==lines[i].y1){
				temp->x1=lines[i].x2;temp->y1=lines[i].y2;
				vis[i]=1;length++;dfs(temp);return ;
			}else if(temp->x2==lines[i].x1&&temp->y2==lines[i].y1){
				temp->x2=lines[i].x2;temp->y2=lines[i].y2;
				vis[i]=1;length++;dfs(temp);return ;
			}else if(temp->x1==lines[i].x2&&temp->y1==lines[i].y2)
			{
				temp->x1=lines[i].x1;temp->y1=lines[i].y1;
				vis[i]=1;length++;dfs(temp);return ;
			}else if(temp->x2==lines[i].x2&&temp->y2==lines[i].y2)
			{
				temp->x2=lines[i].x1;temp->y2=lines[i].y1;
				vis[i]=1;length++;dfs(temp);return ;
			}
		}
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d%d%d%d",&lines[i].x1,&lines[i].y1,&lines[i].x2,&lines[i].y2);
		
	int ans1=0;
	
	for(int i=0;i<n;i++)
	{
		line temp;temp=lines[i];
		memset(vis,0,sizeof(vis));
		vis[i]=1;length=1;dfs(&temp);
		if(length>ans1){
			ans1=length;
			linemax=temp;
		}
	}
	printf("%d %d %d\n",ans1,linemax.x1,linemax.y1);
	return 0;
} 

