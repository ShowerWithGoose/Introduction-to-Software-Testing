#include<stdio.h>
struct node{
	int x;
	int y;
	int next_x;
	int next_y;
};
struct node array[110];
int n;
int cnt;
void find(int x1, int y1)
{
	int i;
	int x2,y2;
	for(i=1;i<=n;i++)
	{
		if(array[i].x==x1&&array[i].y==y1)//查找成功 
		{
			cnt++;
			x2=array[i].next_x;
			y2=array[i].next_y;
			find(x2,y2);
		}
	}
	return ;//查找失败 
}
int main()
{
	int i,j;
	int max=0;
	int max_x,max_y;
	int x1,y1,x2,y2;
	int x_c,y_c;
	scanf("%d",&n);
	for(i=1;i<=109;i++)
	{
		array[i].x=-1;
		array[i].y=-1;
		array[i].next_x=-1;
		array[i].next_y=-1;
	}
	
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		array[i].x=x1;
		array[i].y=y1;
		array[i].next_x=x2;
		array[i].next_y=y2;
	}
	for(i=1;i<=n;i++)
    {
    	find(array[i].x,array[i].y);
    	if(cnt>max)
    	{
    		max=cnt;
    		max_x=array[i].x;
    		max_y=array[i].y;
		}
    	cnt=0;
	}
	printf("%d %d %d",max,max_x,max_y);
	
	return 0; 
}

