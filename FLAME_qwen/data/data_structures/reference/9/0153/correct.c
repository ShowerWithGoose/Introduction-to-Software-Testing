#include<stdio.h>
#include<string.h>
#include<math.h>
int n;
struct line
{
	int x1;
	int x2;
	int y1;
	int y2;
}; 
void linesort(struct line b[],int n)
{
	int i,j;
	struct line flag;
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(b[i].x1>b[j].x1)
			{
				flag=b[i];
				b[i]=b[j];
				b[j]=flag;
			}
		}
	} 
}
void linenum(struct line e[],int n)
{
	int i,j,c,d,max=1;
	int x1max=0;
	int y1max=0;
	for(i=0;i<n;i++)
	{
		int num=1;
		c=e[i].x2;
		d=e[i].y2;
		for(j=i+1;j<n;j++)
		{
			if(e[j].x1==c&&e[j].y1==d)
			{
				c=e[j].x2;
				d=e[j].y2;
			    num++;
		    }
		}
		if(num>max)
		{
			max=num;
		    x1max=e[i].x1;
			y1max=e[i].y1;	
		}
	}
	printf("%d %d %d",max,x1max,y1max);
}
int main()
{
	int i;
	scanf("%d",&n);
	struct line a[10000];
	for(i=0;i<n;i++) scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
	linesort(a,n);
	linenum(a,n);
return 0;
}


