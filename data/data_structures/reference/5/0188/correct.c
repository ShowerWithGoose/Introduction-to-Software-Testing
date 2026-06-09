#include<stdio.h>
#include<stdlib.h>
struct jiegou
{
	long long a,n;
}m[1000],n[1000],mn[1000];

int cmp(const void *_a, const void *_b)
{
	struct jiegou a=*(struct jiegou*)_a;
	struct jiegou b=*(struct jiegou*)_b;
	return b.n-a.n;
}

int num_m=0,num_n=0,num=0;
int main()
{
	//shu ru
	while(1)
	{
		num_m++;
		scanf("%ld%ld",&m[num_m].a,&m[num_m].n);
		if(getchar()=='\n') break;
	}
	while(1)
	{
		num_n++;
		scanf("%ld%ld",&n[num_n].a,&n[num_n].n);
		if(getchar()=='\n') break;
	}
	
	//cheng
	int i=1; 
	for(;i<=num_m;i++)
	{
		int j=1;
		for(;j<=num_n;j++)
		{
			num++;
			mn[num].a=m[i].a*n[j].a;
			mn[num].n=m[i].n+n[j].n;
		}
	}
	
	
	//paixu
	qsort(mn+1,num,sizeof(mn[1]),cmp);
	
	
	//合并
	i=num;
	int num_=num;
	for(;i>=1;i--)
	{
		if(mn[i].n==mn[i-1].n)
		{
			mn[i-1].a+=mn[i].a;
			mn[i].n=-1;
			num_--; 
		}
	} 
	
	//再次排序
	qsort(mn+1,num,sizeof(mn[1]),cmp);
	
	//输出测试 
	//int k=1;
	//for(;k<=num_;k++) printf("\n%lld\n",mn[k].a); 	
	
	//输出 
	i=1;
	for(;i<=num_;i++)
	{
		printf("%lld %lld ",mn[i].a,mn[i].n);
	}
	
	return 0;
}

