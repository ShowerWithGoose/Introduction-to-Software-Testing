#include<stdio.h>
#include<string.h>
#include<ctype.h>
struct line
{
	int x1,y1,x2,y2;
	int count;
};
struct line a[100];
int cmp(const void *a,const void *b)
{
	struct line s1,s2;
	s1=*(struct line*)a;
	s2=*(struct line*)b;
	if(s2.x1>s1.x1) return 1;
	if(s2.x1<s1.x1) return -1;
	if(s2.x1==s1.x1) return 0;
}
int main()
{
	int n,i,j,temp1,temp2,max=0,t=0;
	scanf("%d", &n);
	for(i=0;i<n;i++)
		scanf("%d%d%d%d", &a[i].x2, &a[i].y2, &a[i].x1, &a[i].y1);
	qsort(a,n,sizeof(a[0]),cmp);
	a[0].count=1;
	for(i=0;i<n;i++)
	{
		int flag=0;
		for(j=0;j<i;j++)
		{
			if(a[i].x1==a[j].x2&&a[i].y1==a[j].y2)
			{
				flag=1;
				a[i].count=a[j].count+1;
				if(a[i].count>max)
				{
					max=a[i].count;
					t=i;
				}
			}
		}
		if(flag==0)
			a[i].count=1;
	}
	printf("%d %d %d\n", max, a[t].x2, a[t].y2);
	return 0;
}

