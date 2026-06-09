#include<stdio.h>
struct node{
	int x1;
	int y1;
	int x2;
	int y2;
};
int main()
{
	struct node pnt[100],tmp,pnt2[100];
	int n;
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
	scanf("%d %d %d %d",&pnt[i].x1,&pnt[i].y1,&pnt[i].x2,&pnt[i].y2);
	
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
		if(pnt[i].x1>pnt[j].x1)
		{
			tmp=pnt[i];
			pnt[i]=pnt[j];
			pnt[j]=tmp;
		}
		}
	}
	//for(int i=0;i<n;i++)
	//printf("%d %d %d %d\n",pnt[i].x1,pnt[i].y1,pnt[i].x2,pnt[i].y2);
	int x0,y0,x2,y2,count=0,max=0; 
	for(int i=0;i<n;i++)
	{
		x2=pnt[i].x2;
		y2=pnt[i].y2;
		count=1;
		for(int j=i+1;j<n;j++)
		{
			if(x2==pnt[j].x1&&y2==pnt[j].y1)
			{
				count++;
				x2=pnt[j].x2;
				y2=pnt[j].y2;
			}
		}
				if(count>max)
				{
					max=count;
					x0=pnt[i].x1;
					y0=pnt[i].y1;
				}
	}
	printf("%d %d %d",max,x0,y0);
	return 0; 
}

