#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
int n;
struct data{
	int x1;
	int y1;
	int x2;
	int y2;
	int sum;
}s[1005];
int cmp(const void *pa,const void *pb)
{
	struct data c=*(struct data*)pa;
	struct data d=*(struct data*)pb;
	if(c.x1==d.x1)
	{
		return c.y1-d.y1;
	}
	else
		return c.x1-d.x1;
}
int Cmp(const void *pa,const void *pb)
{
	struct data c=*(struct data*)pa;
	struct data d=*(struct data*)pb;
	return c.sum-d.sum;
}
int main()
{
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&s[i].x1,&s[i].y1,&s[i].x2,&s[i].y2);
		s[i].sum=1;
	}
	qsort(s,n,sizeof(s[0]),cmp);
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(s[i].x2==s[j].x1&&s[i].y2==s[j].y1)
			{
				s[i].x2=s[j].x2;s[i].y2=s[j].y2;
				s[i].sum+=s[j].sum;
				s[j].x1=0;s[j].x2=0;s[j].y1=0;s[j].y2=0;s[j].sum=0;
			}
		}
	}
	qsort(s,n,sizeof(s[0]),Cmp);
	printf("%d %d %d",s[n-1].sum,s[n-1].x1,s[n-1].y1);
	return 0;
}

