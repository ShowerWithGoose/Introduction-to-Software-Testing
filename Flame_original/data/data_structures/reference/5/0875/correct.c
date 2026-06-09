#include <stdio.h>
#include <string.h>
struct node
{
	int zhi;
	int xi;
}a[10000],b[10000],ans[10000];
int cmp(const void* a,const void *b)
{
	struct node *c= (struct node *)a;
	struct node *d= (struct node *)b;
	return -(c->zhi-d->zhi); 
}
int main()
{
	int i=1,j,l1,l2,l3;
	char c,d;
	while(1)
	{
		scanf("%d%d%c",&a[i].xi,&a[i].zhi,&c);
		i++;
		if(c=='\n')break;
	}
	l1=i-1;
	i=1;
	while(1)
	{
		scanf("%d%d%c",&b[i].xi,&b[i].zhi,&c);
		i++;
		if(c=='\n')break;
	}
	l2=i-1;
	l3=1;
	for(i=1;i<=l1;i++)
	{
		for(j=1;j<=l2;j++)
		{
			ans[l3].xi=a[i].xi*b[j].xi;
			ans[l3].zhi=a[i].zhi+b[j].zhi;
			l3++;
		}
	}
	l3--;
	int len=l3;
	for(i=1;i<=l3;i++)
	{
		for(j=i+1;j<=l3;j++)
		{
			if(ans[j].xi==0)continue;
			if(ans[i].zhi==ans[j].zhi)
			{
				ans[i].xi+=ans[j].xi;
				len--;
				ans[j].xi=0;
				ans[j].zhi=0;	
			}
		}
	}
	qsort(&ans[1],l3,sizeof(ans[1]),cmp);
	for(i=1;i<=len;i++)
	{
		printf("%d %d ",ans[i].xi,ans[i].zhi); 
	}
	for(i=len+1;i<=l3;i++)
	{
		if(ans[i].xi!=0&&ans[i].zhi==0)
		{
			printf("%d %d ",ans[i].xi,ans[i].zhi); 
		}
		
	}
	return 0;
}

