#include<stdio.h>
#include<stdlib.h>
struct line{
	int x,y,num;
	struct line* next;
}segment[200];
int cmp(const void*,const void*);
struct line*p[200];
int a[200][5];
int main()
{
	int i,j,k,n,x1,x2,y1,y2,key=0,max=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&a[i][1],&a[i][2],&a[i][3],&a[i][4]);
		p[i]=segment[i].next;
		p[i]=(struct line*)malloc(sizeof(struct line*));
		segment[i].num=1;
	}
	qsort(a,n,sizeof(a[1]),cmp);
	for(i=0;i<n;i++)
	{
		key=0;
		x1=a[i][1];
		x2=a[i][3];
		y1=a[i][2];
		y2=a[i][4];
		for(j=0;j<n;j++)
		{
			if(x1==p[j]->x&&y1==p[j]->y)
			{
				segment[j].num++;
				p[j]=p[j]->next;
				p[j]=(struct line*)malloc(sizeof(struct line*));
				p[j]->x=x2;
				p[j]->y=y2; 
				key=1;
			}	
		}
		if(key==0)
		{
			segment[i].x=x1;
			segment[i].y=y1;
			segment[i].next=(struct line*)malloc(sizeof(struct line));
			p[i]=segment[i].next;
			segment[i].next->x=x2;
			segment[i].next->y=y2;
		}
	}
	for(i=0;i<n;i++)
	{
		if(max<segment[i].num)
		{
			key=i;
			max=segment[i].num;
		}
	}
	printf("%d %d %d",max,segment[key].x,segment[key].y);
	return 0;	
}
int cmp(const void*p1,const void*p2)
{
	int *q1=(int *)p1;
	int *q2=(int *)p2;
	if(q1[1]<q2[1])return -1;
	return 1;
}

