
#include <stdio.h>
#include <string.h>
struct line{
	int x1; int y1;
	int x2; int y2; 
}list[200],temp;
int n,i,j;

void sort(struct line list[])
{
	for (i=0;i<n;i++)
		for(j=i;j<n;j++)
		{
			if(list[i].x1>list[j].x1)
			{
				temp=list[i];
				list[i]=list[j];
				list[j]=temp; 
			}
		}
	
}
int main()
{
	int xmax=0,ymax=0,linemax=1;
	int x2,y2,count=1;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d%d%d%d",&list[i].x1,&list[i].y1,&list[i].x2,&list[i].y2);
	
	sort(list);
	for(i=0;i<n;i++)
	{
		count=1;
		x2=list[i].x2,y2=list[i].y2;
		for(j=i+1;j<n;j++)
		{
			if(x2==list[j].x1&&y2==list[j].y1)
			{
				count++;
				x2=list[j].x2;
				y2=list[j].y2; 
			}
			if(count>linemax)
			{
				linemax=count;
				xmax=list[i].x1;
				ymax=list[i].y1;
			}
		}	
	}
	
	printf("%d %d %d",linemax,xmax,ymax);
	return 0;	
}

