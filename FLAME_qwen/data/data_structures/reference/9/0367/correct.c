#include <stdio.h>
int main()
{	
	struct xian{
		int x1;
		int x2;
		int y1;
		int y2;
		//struct xian* link;
	};
	struct xian a[110];
	int i,j;
	int n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{	
		scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
	}	
	int cnt=0;
	int sign=1; 
	int sum[120]={0};//记录每个i开头的线段段数 
	int k;
	for(i=1;i<=n;i++)//起始 
	{	cnt=0;
		k=i;
		sign=1;
		
		while(sign!=0)
		{	sign=0;
			for(j=1;j<=n;j++)
			{		
				if(a[k].x2==a[j].x1&&a[k].y2==a[j].y1)
				{	cnt++;//成功找到
					k=j;
					sign=1; 
					break;
				}
			}
		}
		sum[i]=cnt+1;
	}
	int max=-1;
	int cnt1; 
	for(i=1;i<=n;i++)
	{	//printf("%d\n",sum[i]);
		if(sum[i]>=max)
		{	max=sum[i];
			cnt1=i;//记录最大值的i 
		}
	}
	printf("%d %d %d",max,a[cnt1].x1,a[cnt1].y1);
}

