#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct line
	{
		int x1,x2,y1,y2;
		int cnt;	
	}in[1005];
int cmp1(const void*p1,const void*p2)
{
	struct line *a = (struct line*)p1;
	struct line *b = (struct line*)p2;
	if(a->x1!=b->x1)
		return(a->x1-b->x1);
	return(a->y1-b->y1);
}
int cmp2(const void*p1,const void*p2)
{
	struct line *a = (struct line*)p1;
	struct line *b = (struct line*)p2;
	return(a->cnt-b->cnt);
}
int main()
{
	int n,i=0,j=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&in[i].x1,&in[i].y1,&in[i].x2,&in[i].y2);
		in[i].cnt=1;
	}
	qsort(in,n,sizeof(in[0]),cmp1);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(in[i].x2==in[j].x1&&in[i].y2==in[j].y1)
			{
				in[i].x2=in[j].x2;
				in[i].y2=in[j].y2;
				in[i].cnt+=in[j].cnt;
				in[j].cnt=0;
				in[j].x1=0;
				in[j].x2=0;
				in[j].y1=0;
				in[j].y2=0;
			}
		}
	}
	qsort(in,n,sizeof(in[0]),cmp2);
	printf("%d %d %d\n",in[n-1].cnt,in[n-1].x1,in[n-1].y1);
	return 0;
}

