#include<stdio.h>
#include<stdlib.h>
struct line{
	int x1;
	int y1;
	int x2;
	int y2;
}a[200];
int cmp(const void*p1,const void*p2)
{
	struct line *a=(struct line*)p1;
	struct line *b=(struct line*)p2;
	if(a->x1 != b->x1) return a->x1-b->x1;
	else return a->y1-b->y2;
}
int main()
{
	int i,j,k,n,x=0,y=0;
	int cnt=1,tmp=1;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
		
	}
	qsort(a,n,sizeof(struct line),cmp);
	
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(a[i].x2==a[j].x1 && a[i].y2==a[j].y1  )
				{
				tmp++;
				a[i].x2 =a[j].x2 ;
				a[i].y2 =a[j].y2 ;
				
				}
			}
			if(tmp>=cnt)
		{
		cnt=tmp;x=a[i].x1;y=a[i].y1 ;
		}	
		tmp=1;
		}

		
	
	printf("%d %d %d",cnt,x,y);
}	


