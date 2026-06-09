#include<stdio.h>
#include<stdlib.h>
struct num{
	int a,p;
};
typedef struct num num;
num l1[114514],l2[114514],ans[114514];
int cnt1=1,cnt2=1;
int cmp(const void *a,const void *b)
{
	num *c=(num*)a;
	num *d=(num*)b;
	return d->p-c->p; 
 } 
int main()
{
	char c=' ';
	while(c!='\n')
	{
		scanf("%d%d%c",&l1[cnt1].a,&l1[cnt1].p,&c);
		cnt1++;
	}
	c=' ';
	while(c!='\n')
	{
		scanf("%d%d%c",&l2[cnt2].a,&l2[cnt2].p,&c);
		cnt2++;
	}
	int k=1;
	for(int i=1;i<=cnt1;i++)
	{
		for(int j=1;j<=cnt2;j++)
		{
			ans[k].a=l1[i].a*l2[j].a;
			ans[k].p=l1[i].p+l2[j].p;
			k++;
		}
	}
	qsort(ans+1,k-1,sizeof(ans[1]),cmp);
	for(int i=1;i<k;i++)
	{
		for(int j=1;j<k;j++)
		{
			if(ans[j].p==ans[j+1].p&&ans[j].p!=0)
			{
				ans[j].a+=ans[j+1].a;
				ans[j+1].a=0;
			}
		}
		
	}
	for(int i=1;i<k;i++)
	{
		if(ans[i].a!=0)
		{
			printf("%d %d ",ans[i].a,ans[i].p);
		}
	}
	return 0;
 } 

