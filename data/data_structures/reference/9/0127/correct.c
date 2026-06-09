#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct line{
	int x1;
	int y1;
	int x2;
	int y2;
}exp,*Exp;
exp num[120];
int cmp(const void* a,const void* b);
int main()
{
	int n;
	scanf("%d",&n);
	int x,y;
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&num[i].x1,&num[i].y1,&num[i].x2,&num[i].y2);
	}
	qsort(num,n,sizeof(exp),cmp);
	int X,Y,max=1;
	for(int i=0;i<n;i++)
	{
		int count=1;
		int c,d;
		c=num[i].x2;
		d=num[i].y2;
		for(int j=i+1;j<n;j++)
		{
			if(c==num[j].x1&&d==num[j].y1)
			{
				count++;
				c=num[j].x2;
				d=num[j].y2;
			}
			if(count>max)
			{
				max=count;
				X=num[i].x1;
				Y=num[i].y1;
			}
		}
	}
	printf("%d %d %d",max,X,Y);
	return 0;
}
int cmp(const void* a,const void* b)
{
	int ans;
	Exp exp1=(Exp)a;
	Exp exp2=(Exp)b;
	ans=exp1->x1-exp2->x1;
	return ans;
}

