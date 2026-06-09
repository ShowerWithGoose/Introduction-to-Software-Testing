#include <stdio.h>
//用结构体数组 分别记录线段起点和终点  dfs 循环dfs和不同线段的终点比对 
struct node
{
	int start_x,start_y;
	int end_x,end_y;
};
int n;
int min=0;
struct node line[120];
void dfs(int x,int step)
{
	int i;
	if(step>min)min=step;
	for(i=1;i<=n;i++)
	{
		if((line[x].end_x==line[i].start_x)&&(line[x].end_y==line[i].start_y))
		{//当前点的终点与一个点的起点相同且没有走过（？ 
			dfs(i,step+1);
		}
	}
	return ;
}

int main()
{
	int ans=0;
	int ans_x,ans_y;
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&line[i].start_x,&line[i].start_y,&line[i].end_x,&line[i].end_y);
		
	}//数据读入 
	
	for(i=1;i<=n;i++)
	{ 
		dfs(i,1);
		if(min>ans){
			ans=min;
			ans_x=line[i].start_x;
			ans_y=line[i].start_y;
		}
		min=0;
	}
	printf("%d %d %d",ans,ans_x,ans_y);
	return 0;
}

