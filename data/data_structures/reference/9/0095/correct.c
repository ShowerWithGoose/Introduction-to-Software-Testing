#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int x1[100],y1[100],x2[100],y2[100];
//n行，每行一个坐标 
int op[100];

int main()
{
	int n,i,j,k;
	int x,y;
	j=0; 
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&x1[i],&y1[i],&x2[i],&y2[i]); 
	}
	
	for(i=0;i<n;i++)
	{
		x=x2[i];
		y=y2[i];
		//取xy为第i条线段右端点
		for(j=0;j<n;j++)//循环n次
		{
			for(k=0;k<n;k++)
			{
				if(x1[k]==x&&y1[k]==y)
				{
					op[i]=op[i]+1;
					x=x2[k];
					y=y2[k];
					break;
					//找到一个相连线段后可跳出k循环 
					//进入j循环 
				}
				else if(k==n-1)
				{
					break;
				} 
			}
		}
		
	}
	
	int l=sizeof(op)/sizeof(op[0]);
	
	j=0;
	for(i=0;i<l;i++)
	{
		if(op[i]>=op[j])
		{
			
			j=i;
		}
	}
	
	printf("%d %d %d",op[j]+1,x1[j],y1[j]);
	return 0;
}

