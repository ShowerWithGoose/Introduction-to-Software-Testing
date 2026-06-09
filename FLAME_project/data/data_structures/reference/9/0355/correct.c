#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
struct li
{
	int x1,y1,x2,y2;
	int flag;
} line[110];
int n;
int main()
{
	scanf("%d",&n);
	int i,j;
	for(i=0; i<n; i++)
	{
		scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
		line[i].flag=0;
	}
	int max=1,x,y;
	for(i=0; i<n; i++)
	{
		int count=1;
		int x0=line[i].x1,y0=line[i].y1;
		int xm=line[i].x2,ym=line[i].y2;//жу╣Ц
		for(j=0; j<n; j++)
		{
			if((line[j].x1==xm)&&(line[j].y1==ym))
			{
				count++;
				xm=line[j].x2;
				ym=line[j].y2;
				j=0;
			}
			else if((line[j].x2==x0)&&(line[j].y2==y0))
			{
				count++;
				x0=line[j].x1;
				y0=line[j].y1;
				j=0;
			}
		}

		if(count>=max)
		{
			max=count;
			x=x0;
			y=y0;
		}
	}
	printf("%d %d %d",max,x,y);
	return 0;
}


