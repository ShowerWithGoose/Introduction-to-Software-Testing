#include<stdio.h>
#include<stdlib.h>
struct l{
	int x1;
	int y1;
	int x2;
	int y2;
}line[105];

int cmp(const void *p1,const void *p2)
{
	struct l *a=(struct l *)p1,*b=(struct l *)p2;
	if((a->x1)<(b->x1))
	return -1;
	if((a->x1)>(b->x1))
	return 1;
}

int main()
{
	int n,i,j,length[105]={0},a[105],b[105],c[105],d[105];
	int max=0,startx,starty,cnt=1,flag;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
	qsort(line,n,sizeof(line[0]),cmp);
	a[0]=line[0].x1;
	b[0]=line[0].y1;
	c[0]=line[0].x2;
	d[0]=line[0].y2;
	length[0]=1;
	for(i=1;i<n;i++)
	{
		flag=0;
		for(j=0;j<cnt;j++)
		{
			if(c[j]==line[i].x1&&d[j]==line[i].y1)
			{
				c[j]=line[i].x2;
				d[j]=line[i].y2;
				length[j]++;
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			a[cnt]=line[cnt].x1;
	        b[cnt]=line[cnt].y1;
	        c[cnt]=line[cnt].x2;
	        d[cnt]=line[cnt].y2;
	        length[cnt]=1;
	        cnt++;
		}
	}
	for(i=0;i<cnt;i++)
	{
		if(length[i]>max)
		{
			max=length[i];
			startx=a[i];
			starty=b[i];
		}
	}
	printf("%d %d %d",max,startx,starty);
	return 0;
}

