#include<stdio.h>
#include<stdlib.h>
typedef struct line{
	int hx,hy;
	int sx,sy;
	int p;
}line;

int cmp(const void *p1,const void *p2)
{
	return ((line*)p1)->hx-((line*)p2)->hx;
}

int main()
{
	line a[105];
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&a[i].hx,&a[i].hy,&a[i].sx,&a[i].sy);
		a[i].p=0;
	}
	qsort(a,n,sizeof(line),cmp);
	int j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i].sx==a[j].hx&&a[i].sy==a[j].hy)
			{
				a[i].p=j;
				break;
			}
		}
	}
	int maxl=0,mini;
	for(i=0;i<n;i++)
	{
		if(a[i].p==0) continue;
		else
		{
			int po;
			po=a[i].p;
			int cnt=1;
			while(a[po].p)
			{
				cnt++;
				po=a[po].p;
			}
			if(cnt>maxl)
			{
				maxl=cnt;
				mini=i;
			}
		}
	}
	printf("%d %d %d",maxl+1,a[mini].hx,a[mini].hy);
	return 0;
} 

