#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef struct{
	int base;
	int index;	
}calculate;
int count(int a)
{
	int i=1,j,k;
	while(pow(10,i)<=a)i++;
	return i;
}
int cmp(const void*p1,const void*p2)
{
	calculate*q1=(calculate*)p1;
	calculate*q2=(calculate*)p2;
	if(q1->index<q2->index)return 1;
	return -1;
}
int main()
{
	int i=1,j,k,n,na,nb;
	calculate num_initial[10000],num_multiple[10000],ans[10000];
	char a[10000],b[10000];
	gets(a);
	gets(b);
	na=strlen(a);
	nb=strlen(b);
	k=0;
	while(k<=na)
	{
		num_initial[i].base=atoi(&a[k]);
		k=k+count(num_initial[i].base)+1;
		num_initial[i].index=atoi(&a[k]);
		k=k+count(num_initial[i].index)+1;
		i++;
	}
	na=i-1;
	i=1;
	k=0;
	while(k<=nb)
	{
		num_multiple[i].base=atoi(&b[k]);
		k=k+count(num_multiple[i].base)+1;
		num_multiple[i].index=atoi(&b[k]);
		k=k+count(num_multiple[i].index)+1;
		i++;
	}
	nb=i-1;
	for(i=1;i<=na;i++)
	{
		for(j=1;j<=nb;j++)
		{
			ans[(i-1)*nb+j-1].base=num_initial[i].base*num_multiple[j].base;
			ans[(i-1)*nb+j-1].index=num_initial[i].index+num_multiple[j].index;
		}
	}
	qsort(ans,na*nb,sizeof(ans[1]),cmp);
	for(i=0;i<na*nb;i++)
	{
		if(ans[i].index==ans[i+1].index)
		{
			ans[i+1].base+=ans[i].base;
			ans[i].base=0;
		}
	}
	for(i=0;i<=na*nb;i++)
	{
		if(ans[i].base!=0)printf("%d %d ",ans[i].base,ans[i].index);
	}
	return 0;
}

