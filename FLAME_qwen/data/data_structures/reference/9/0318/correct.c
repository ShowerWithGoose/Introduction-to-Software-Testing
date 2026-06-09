#include<stdio.h>
struct dot
{
	int x1;
	int y1;
	int x2;
	int y2;
	int flag;
	int count;
};
struct dot line[500];
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
		line[i].flag=0;
		line[i].count=0;
	}
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	{
		if(line[i].x2==line[j].x1&&line[i].y2==line[j].y1)
		{
			if(line[i].flag!=2)
				line[i].flag=1;
			line[j].flag=2;
		}
	}
	int x,y;
	for(i=0;i<n;i++)
	{
		int mark=1;
		if(line[i].flag==1)
		{
			x=line[i].x2;
			y=line[i].y2;
			while(mark==1)
			{
				for(j=0;j<n;j++)
				{
					mark=0;
					if(line[j].x1==x&&line[j].y1==y)
					{
						line[i].count++;
						x=line[j].x2;
						y=line[j].y2;
						mark=1;
						j=n;
					}
				}
			}
		}
	}
	int max=0,result;
	for(i=0;i<n;i++)
	{
		if(line[i].count>max)
		{
			max=line[i].count;
			result=i;
		}
	}
	printf("%d %d %d",max+1,line[result].x1,line[result].y1);
	return 0;
 } 

