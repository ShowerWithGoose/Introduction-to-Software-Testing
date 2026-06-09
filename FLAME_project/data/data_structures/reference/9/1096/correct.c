#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<memory.h>
struct duan{
	int x[2];
	int y[2];
}a[100];
int cmp(const void *p,const void *q)
{
	int a=((struct duan *)p)->x[0];
	int b=((struct duan *)q)->x[0];
	if(a>b)return 1;
	else return -1;
}
int main()
{
	int n,i,j,cnt[100]={0},c=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&a[i].x[0],&a[i].y[0],&a[i].x[1],&a[i].y[1]);
	}
	/*for(i=0;i<n;i++,c=i)
	{
		loop:for(j=0;j<n;j++)
		{
			if(c==j)continue;//·ÀÖ¹³É»· 
			if(a[c].x[1]==a[j].x[0]&&a[c].y[1]==a[j].y[0])
			{
				if(c==i&&cnt[i])break;
				cnt[i]++;
				c=j;
				goto loop;
			}
		}
	}*/
	qsort(a,n,sizeof(struct duan),cmp);
	for(i=0;i<n;i++)
	{
		c=i;
		for(j=i+1;j<n;j++)
		{
			if(a[c].x[1]==a[j].x[0]&&a[c].y[1]==a[j].y[0])
			{
				cnt[i]++;
				c=j;
			}
		}
	}
	for(i=0,c=0;i<n;i++)
	{
		if(cnt[c]<cnt[i])
		{
			c=i;
		}
	}
	printf("%d %d %d",cnt[c]+1,a[c].x[0],a[c].y[0]);
	return 0;
}



