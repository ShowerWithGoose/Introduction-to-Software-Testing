#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define eps 1e-10
#define pi 3.141592654
#define e 2.71828182846
int n;//线段个数 
struct line
{
	int x1;
	int y1;
	int x2;
	int y2;
	int ctn;
};
struct line a[107];
int main()
{
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
		a[i].ctn=1;
	}
	
	
	int max=-1,j,flg,flag;
	for(i=0;i<n;i++)
	{
		flg=0;
		for(j=0;j<n;j++)
		{
			flag=0;
			if(a[j].x1==a[i].x2&&a[j].y1==a[i].y2&&a[j].ctn!=0&&a[i].ctn!=0)//线段a[j]可以接在a[i]之后
			{
				a[i].x2=a[j].x2;         a[j].x1=0;a[j].x2=0;
				a[i].y2=a[j].y2;         a[j].y1=0;a[j].y2=0;
				a[i].ctn+=a[j].ctn;
				a[j].ctn=0;
//				printf("%d-%d\n",i+1,j+1);
				flag=1;flg=1;
			}
			else if(a[i].x1==a[j].x2&&a[i].y1==a[j].y2&&a[i].ctn!=0&&a[j].ctn!=0)//线段a[i]可以接在a[j]之后 
			{
				a[j].x2=a[i].x2;        a[i].x1=0;a[i].x2=0;
				a[j].y2=a[i].y2;        a[i].x1=0;a[i].x2=0;
				a[j].ctn+=a[i].ctn;
				a[i].ctn=0;
//				printf("%d-%d'\n",j+1,i+1);
				flag=1;flg=1;
			}
			
//		for(int k=0;k<n;k++)
//		{
//			printf("%d:ctn=%d\n",k+1,a[k].ctn);
//		}
//		printf("\n");	

			if(flag==1)
				j=-1;
		}
		if(flg==1)
		{
			i=-1;
			flg=0;
		}
	}
	
	int ans;
	for(i=0;i<n;i++)
	{
		if(max<a[i].ctn)
		{
			max=a[i].ctn;
			ans=i;
		}
	}
	

	
	printf("%d %d %d",max,a[ans].x1,a[ans].y1);
	return 0;
}





















