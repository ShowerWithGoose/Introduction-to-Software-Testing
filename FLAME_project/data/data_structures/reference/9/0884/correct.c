#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
struct kong 
{
	int a[2];
	int b[2];
};
struct kong hang[100];
int pai(const void *u, const void *p) 
{
	struct kong *x = (struct kong *)u;
	struct kong *y = (struct kong *)p;
	if (x->a[0] != y->a[0])
		return -x->a[0]+y->a[0];
	else
		return -x->a[1]+y->a[1];
}
int panduan(struct kong link, struct kong lint) 
{
	if (link.a[0]==lint.b[0]&&link.a[1]==lint.b[1])
		return 2;
	if (link.b[0]==lint.a[0]&&link.b[1]==lint.a[1])
		return 1;
	return 0;
}
int main() 
{
	int n,i,j,shu[100],max=0,ans=0;
	scanf("%d",&n);
	for (i=0;i<n;i++) 
	{
		shu[i]=1;
	}
	for (i=0;i<n;i++) 
	{
		scanf("%d%d%d%d", &hang[i].a[0], &hang[i].a[1], &hang[i].b[0], &hang[i].b[1]);
	}
	qsort(hang, n, sizeof(hang[0]), pai);
	for (i = 0; i < n; i++) 
	{
		for (j = i + 1; j < n; j++) 
		{
			if (panduan(hang[i], hang[j]) == 1) 
			{
				shu[i] += shu[j];
			}
			if (panduan(hang[i], hang[j]) == 2) 
			{
				shu[j] += shu[i];
			}
		}
	}
	for (i = 0; i < n; i++) 
	{
		if (shu[i] > max) 
		{
			max = shu[i];
			ans = i;
		}
	}
	printf("%d %d %d\n", max, hang[ans].a[0], hang[ans].a[1]);
	return 0;
}



