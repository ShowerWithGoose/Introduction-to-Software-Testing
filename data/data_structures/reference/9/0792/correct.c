#include<stdio.h>
struct LINE
{
	int x1;
	int y1;
	int x2;
	int y2;
};
int main()
{
	int n,i,j,flag1,flag2,num=0,max=0,px,py;
	struct LINE line[100];
	int hold1,hold2,hold3,hold4;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d %d %d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			if(line[j].x1>line[j+1].x1)
			{
				hold1=line[j].x1;
				hold2=line[j].y1;
				hold3=line[j].x2;
				hold4=line[j].y2;
				line[j].x1=line[j+1].x1;
				line[j].y1=line[j+1].y1;
				line[j].x2=line[j+1].x2;
				line[j].y2=line[j+1].y2;
				line[j+1].x1=hold1;
				line[j+1].y1=hold2;
				line[j+1].x2=hold3;
				line[j+1].y2=hold4;
			}
			if(line[j].x1==line[j+1].x1&&line[j].y1>line[j+1].y1)
			{
				hold1=line[j].x1;
				hold2=line[j].y1;
				hold3=line[j].x2;
				hold4=line[j].y2;
				line[j].x1=line[j+1].x1;
				line[j].y1=line[j+1].y1;
				line[j].x2=line[j+1].x2;
				line[j].y2=line[j+1].y2;
				line[j+1].x1=hold1;
				line[j+1].y1=hold2;
				line[j+1].x2=hold3;
				line[j+1].y2=hold4;
			}
		}
	}
	for(i=1;i<=n-1;i++)
	{
		num=1;
		flag1=line[i].x2;
		flag2=line[i].y2;
		for(j=i;j<=n;j++)
		{
			if(line[j].x1==flag1&&line[j].y1==flag2)
			{
				flag1=line[j].x2;
				flag2=line[j].y2;
				num++;
				if(num>max)
				{
					max=num;
					px=line[i].x1;
					py=line[i].y1;
				}
			}
		}
	}
	printf("%d %d %d",max,px,py);
	
}

