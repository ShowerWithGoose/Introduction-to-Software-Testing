#include <stdio.h> 
#include <string.h>
#include <ctype.h>
struct xianduan{
	int x1;
	int y1;
	int x2;
	int y2;
	int cnt; 
}xian[105],temp;
void paixu(int n,struct xianduan xian[105],struct xianduan temp) 
{
	int i,j,flag;
	for(i=0;i<n-1;i++)
	{
		flag=0;
		for(j=0;j<n-1-i;j++)
		{
			if(xian[j].x1<xian[j+1].x1)
			{
				temp=xian[j];
				xian[j]=xian[j+1];
				xian[j+1]=temp;
				flag=1;
			}
		}
		if(flag==0)
			{
				break;
			}
	}
}
int main()
{
	int number,i,j;
	scanf("%d",&number);
	for(i=0;i<number;i++)
	{
		scanf("%d%d%d%d",&xian[i].x1,&xian[i].y1,&xian[i].x2,&xian[i].y2);
		xian[i].cnt=1;
	}
	 paixu(number,xian,temp);
	for(i=0;i<number;i++)
	{
		for(j=i+1;j<number;j++)
		{
			if(xian[i].x1==xian[j].x2&&xian[i].y1==xian[j].y2)
			{
				xian[j].cnt+=xian[i].cnt;
				break;
			}
		}
	}
	int a=xian[number-1].cnt;
	for(i=number-1;i>=0;i--)
	{
		if(xian[i].cnt>a)
		{
			a=xian[i].cnt;
		}
	}
	for(i=number-1;i>=0;i--)
	{
		if(xian[i].cnt==a)
		{
			printf("%d %d %d",a,xian[i].x1,xian[i].y1);
		}
	}
	return 0;
}

