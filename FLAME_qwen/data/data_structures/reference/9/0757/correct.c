#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct line{
	int x1;
	int y1;
	int x2;
	int y2;
};
int times[10000];
struct line* p;
int n; 
int i;
int max=0;
int mark=0;
void F(int k)
{
	int j;
	for(j=0;j<n;j++)
	{
		if(((p+j)->x1)==((p+k)->x2)&&((p+j)->y1)==((p+k)->y2))
		{
			times[i]++;
			F(j);
		}
	}
	
}
int main()
{
	scanf("%d",&n);
	p=(struct line*)malloc(n*sizeof(struct line));
	for(i=0;i<n;i++)
		scanf("%d%d%d%d",&p[i].x1,&p[i].y1,&p[i].x2,&p[i].y2);
	if(n==1)
	{
		printf("1 %d %d",p->x1,p->y1);
		return 0;
	}
	else
	{
		for(i=0;i<n;i++)
	    {
		    F(i);
	    }
	    for(i=0;i<n;i++)
	    {
	    	if(times[i]>max)
	    	{
	    		max=times[i];
	    		mark=i;
			}
		}
		printf("%d %d %d",max+1,p[mark].x1,p[mark].y1);
	}
}



