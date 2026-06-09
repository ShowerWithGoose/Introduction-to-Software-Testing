#include<stdio.h>
#include<stdlib.h>
struct aaa
{
	long long x1,x2,y1,y2;
	int l;
}a[105];
int cmp(const void *x,const void *y)
{
	struct aaa p=*(struct aaa*)x;
	struct aaa q=*(struct aaa*)y;
	if(p.x1==q.x1) return p.y1-q.y1;
	return p.x1-q.x1;
}
int main()
{
	int n,maxn=0,f;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld%lld%lld%lld",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
		a[i].l=1;
	}
	qsort(a,n,sizeof(a[0]),cmp);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j) continue;
			if(a[i].x2==a[j].x1&&a[i].y2==a[j].y1)
			{
				a[i].x2=a[j].x2;a[i].y2=a[j].y2;a[i].l+=a[j].l;
				a[j].x1=-8589934592;a[j].y1=-8589934592;
				a[j].x2=-8589934592;a[j].y2=-8589934592;
				a[j].l=0;
			}
		}
	}
	for(int i=0;i<n;i++)
	if(a[i].l>maxn) maxn=a[i].l,f=i;
	printf("%d %lld %lld",maxn,a[f].x1,a[f].y1);
}


