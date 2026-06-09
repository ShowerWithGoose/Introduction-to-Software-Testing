#include "stdio.h"

struct {
	int x1;
	int y1;
	int x2;
	int y2;
}point[101],s;//所有的点 

int main (){
	int n,i,j,k,a,b,c,max;
	int lenth;
	scanf ("%d",&n);
	i = 0;
	while (i<n)// 输入 
	{
		scanf ("%d",&point[i].x1);
		scanf ("%d",&point[i].y1);
		scanf ("%d",&point[i].x2);
		scanf ("%d",&point[i].y2);
		i++;
	}
	 for(i=0;i<n;i++)//左端点排序 
    {
 		for(j=i+1;j<n;j++)
        {
            if(point[j].x1<point[i].x1)//csdn上扒下来的
            {
                s=point[j];
                point[j]=point[i];
                point[i]=s;
            }
        }
	}
	/*for (i=0;i<n;i++)
	{
		printf ("%d %d\n",point[i].point1[0],point[i].point1[1]);
	}*/ //检测排序发现有问题 有的点顺序不正确 
	c = 0;
	max = 0;
	for (i=0;i<n;i++)
	{
		lenth = 1;//线段树 
		c = i;
		for (j=1;j<n;j++)//找连起来的 
		{
			if (point[j].x1==point[c].x2&&point[j].y1==point[c].y2)
			{
				c = j;//继续向下一条线段判断 
				++lenth;
			}
		}
		if (lenth>=max)  
		{
			max = lenth;
			k = i;
		}
		
	} 
	printf ("%d %d %d",max,point[k].x1,point[k].y1);

		
	
	
	return 0;
}

