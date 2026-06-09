#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct line{
	int x1;
	int y1;
	int x2;
	int y2;
	int cnt;//左边已经连接的线段条数 
	int x_st;								//改动1 定义x_st,y_st为左端链接的最远的线段的起点，便于输出答案 
	int y_st; 
};//一条线段两个端点
struct line line={0,0,0,0};

int main()
{
//	freopen("a.txt", "r", stdin);
	struct line a[200];
	int i=0,j=0,n=0,num=0,b=0,c=0,max=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
		a[i].cnt=1; 
		a[i].x_st = a[i].x1;				//改动2 为x_st, y_st赋初值 
		a[i].y_st = a[i].y1; 
	}
	
	struct line temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(a[j].x1>a[j+1].x1)
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;	
			}
		}
	}//把数组h1中的元素，即所有的x1从小到大排列（冒泡排序） 
	
	int x=0,y=0;
	for(i=0;i<n;i++)
	{
		b=a[i].x2;
		c=a[i].y2;
		num=a[i].cnt;
		for(j=i+1;j<n;j++)
		{
			if(b==a[j].x1&&c==a[j].y1)//前一条线段x2y2=后一条线段x1y1
			{
				a[j].cnt=num+1;//右边线段cnt=左边线段cnt 
																	//改动3 不需要更新b和c在for循环里遍历时是用的a[i]的值 
//				b=a[j].x2;
//				c=a[j].y2;
																	//改动4 更新x_st, y_st为最左端的其实线段端点
				a[j].x_st = a[i].x_st;
				a[j].y_st = a[i].y_st; 
																	
			}		
			
																	//改动5 在for循环里面更新 
			if(a[j].cnt>max)
			{
				max=a[j].cnt;
				x=a[i].x_st;						//改动6 更新答案 
				y=a[i].y_st; 
			}
			
		}
	}
	printf("%d %d %d",max,x,y);
	return 0;
	
 } 

