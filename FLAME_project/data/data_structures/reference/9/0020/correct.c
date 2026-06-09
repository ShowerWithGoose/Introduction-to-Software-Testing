#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Xianduan
{
	int x1;
	int x2;
	int y1;
	int y2;
}a[100],temp;
int cmp(const void*a,const void*b)
{
	struct  Xianduan*c=(struct Xianduan*)a;
	struct  Xianduan*d=(struct Xianduan*)b;
	//if(c->x1!=d->x1)//这里，不相等返回-1是没办法完成排序的
	if(c->x1 <= d->x1) 
		return -1;
	return 1; 
}
int main()
{
	int n,i,j,max=0,l=1,place,k;//l初始化为1，因为下面循环中第一条线段没有被计数 
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);	
	}
	qsort(a,n,sizeof(a[0]),cmp);//排序 为什么要-1呢？一共有n个结构体需要排列，下标是0~n-1 
/*	for(i=0;i<n;i++)
	{
		printf("%d %d %d %d\n",a[i].x1,a[i].y1,a[i].x2,a[i].y2);
	}*/
	for(i=0;i<n;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		{
			//if(a[j].x1==a[k].x1&&a[j].y1==a[k].y2)//首位相接
			if(a[k].x2==a[j].x1 && a[k].y2==a[j].y1) 
			{
				l++;
				k=j;
			}
		}	
		if(l > max)//如果判断长度写在循环外面，是不是每次循环之后，l都会被覆盖，所以最终只记录了一个l 
		{
			max=l;
			place = i;//同时记录是第几个线段的成果 
		}//最大长度
		l = 1;//复原 
	}//判断长度 

	printf("%d %d %d",max,a[place].x1,a[place].y1);
	return 0;
}

