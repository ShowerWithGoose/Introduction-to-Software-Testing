#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<ctype.h>
struct line{
	int x1;
	int y1;
	int x2;
	int y2;
}s[105];//线段 
int max(int num[],int n)//找线段数最大的线段位置 
{
	int i,j,max=0;
	for(i=0;i<n;i++)
	{
		if(num[i]>max)
		{
			max=num[i];
			j=i;
		}
	}
    return j;
}
int main()
{
	int n,i,j,k,x0,y0,flag,flag0;
	int num[105];//存入每条线段后连续线段的线段数 
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&s[i].x1,&s[i].y1,&s[i].x2,&s[i].y2);
		//printf("%d %d %d %d\n",s[i].x1,s[i].y1,s[i].x2,s[i].y2);
	}
	memset(num,0,sizeof(num));//初始化为0 
	for(i=0;i<=n;i++)
	{
		x0=s[i].x2;
	    y0=s[i].y2;
	    num[i]++;//本身算一条 
		for(j=0;j<n;j++)
		{
			if(x0==s[j].x1&&y0==s[j].y1&&j!=i)
			{
				x0=s[j].x2;
				y0=s[j].y2;
				num[i]++;//找到连着的下一条线 
				flag=1;
				flag0=j;
				while(flag==1)
				{
					flag=0;
					for(k=0;k<n;k++)
					{
						if(x0==s[k].x1&&y0==s[k].y1&&k!=flag0)
						{
							flag=1;
							x0=s[k].x2;
							y0=s[k].y2;
							flag0=k;
							num[i]++;//接着找 
							break; 
						}
						else if(x0==s[k].x2&&y0==s[k].y2&&k!=flag0)
						{
							flag=1;
							x0=s[k].x1;
							y0=s[k].y1;
							flag0=k;
							num[i]++;//接着找 
							break; 
						}
					}
				}
				break;
			}
			else if(x0==s[j].x2&&y0==s[j].y2&&j!=i)
			{
				x0=s[j].x1;
				y0=s[j].y1;
				num[i]++;//找到连着的下一条线 
				flag=1;
				flag0=j;
				while(flag==1)
				{
					flag=0;
					for(k=0;k<n;k++)
					{
						if(x0==s[k].x1&&y0==s[k].y1&&k!=flag0)
						{
							flag=1;
							x0=s[k].x2;
							y0=s[k].y2;
							num[i]++;//接着找 
							flag0=k;
							break; 
						}
						else if(x0==s[k].x2&&y0==s[k].y2&&k!=flag0)
						{
							flag=1;
							x0=s[k].x1;
							y0=s[k].y1;
							num[i]++;//接着找
							flag0=k; 
							break; 
						}
					}
				}
				break;
			}
		}
	}
	printf("%d %d %d",num[max(num,n)],s[max(num,n)].x1,s[max(num,n)].y1);
	return 0;
}


/*15
600 600 721 2
80 75 125 75
1 1 2 2
400 400 600 600
60 40 80 55
80 55 90 20
300 300 400 400
140 120 195 205
10 111 70 165
22 35 43 43
195 205 300 300
22 175 80 205
43 43 60 40
90 20 125 60
70 165 140 120 */ 



