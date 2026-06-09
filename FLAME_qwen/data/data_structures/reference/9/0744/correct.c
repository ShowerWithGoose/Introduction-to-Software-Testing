#include<stdio.h>


//解题思路：搜索与回溯算法
//用一个数组存下开始的位置  再用一个n记录下线段的条数
//终止条件：找不到和最后一个点对应的线段
//不会有三条线段公用一个点

int a[100][5]={0};//存线段
int b[3]={0};//存结果
int n;//线段个数 
int max_k;
void dfs(int ix,int iy,int x,int y,int k)
{
	int j=1;
	for(;j<=n;j++)
	{
		if(k==1)
		{
			x=a[j][3];//x,y代表的是 这个线段的右断点  用于和后面线段的前端点作比较 
		    y=a[j][4];
		    ix=a[j][1];iy=a[j][2];//记录整条线段的初始位置 
			dfs(ix,iy,x,y,k+1);
		}else
		{
			if(x==a[j][1]&&y==a[j][2])//与后端点作比较 
			{
				dfs(ix,iy,a[j][3],a[j][4],k+1);
			}
		}
	}
	//开始存数据
	if(k>max_k)
	{
		max_k=k;
		b[0]=k;
		b[1]=ix;
		b[2]=iy;
	}
}
int main()
{
	
	scanf("%d",&n);
	int i=1;
	for(;i<=n;++i)
	scanf("%d%d%d%d",&a[i][1],&a[i][2],&a[i][3],&a[i][4]);
	dfs(0,0,0,0,1);
	printf("%d %d %d",b[0]-1,b[1],b[2]);
	return 0;
}

