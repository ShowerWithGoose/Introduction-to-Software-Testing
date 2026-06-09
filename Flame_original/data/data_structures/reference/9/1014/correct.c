#include<stdio.h>
#include<stdlib.h>
struct point{
	int x1;
	int y1;
	int x2;
	int y2;
};
int main()
{
	int num,*q,max,temp1;
	struct point *p,temp;
	scanf("%d",&num);
	p=(struct point *)malloc(sizeof(struct point)*num);
	q=(int *)malloc(sizeof(int)*num);
	for(int i=0;i<num;i++)
		q[i]=1;
	for(int i=0;i<num;i++)
	{
		scanf("%d%d%d%d",&(p+i)->x1,&(p+i)->y1,&(p+i)->x2,&(p+i)->y2);
	}
	for(int i=0;i<num-1;i++)
	{
		for(int j=0;j<num-1-i;j++)
		{
			if(p[j].x1>p[j+1].x1)
			{
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}
	for(int i=0;i<num-1;i++)
	{
		temp=p[i];
		for(int j=1;j+i<num;j++)
		{
			if(temp.x2==p[i+j].x1&&temp.y2==p[i+j].y1)
			{
				q[i]++;
				temp=p[i+j];
			}
		}
	}
	max=0;
	temp1=q[0];
	for(int i=0;i<num-1;i++)
	{
		if(temp1<q[i+1])
		{
			max=i+1;
			temp1=q[i+1];
		}
	}
	printf("%d %d %d",temp1,p[max].x1,p[max].y1);
	return 0;
}



