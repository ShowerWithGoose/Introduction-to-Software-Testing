#include<stdio.h>
#include<stdlib.h>
struct team
{
	int d;
	int m;
};

int fun(const void *a,const void *b)
{
	struct team *c=(struct team *)a;
	struct team *d=(struct team *)b;
	if(c->m<d->m)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
int main()
{
	struct team t1[1000];
	struct team t2[1000];
	struct team t[1000];
	int i=0;
	char c;
	while(1)
	{
		scanf("%d",&t1[i].d);
		scanf("%d",&t1[i].m);
		scanf("%c",&c);
		if(c=='\n')
		{
			break;
		}
		i++;
	}
	int j=0;
	while(1)
	{
		scanf("%d",&t2[j].d);
		scanf("%d",&t2[j].m);
		scanf("%c",&c);
		if(c=='\n')
		{
			break;
		}
		j++;
	}
	
//	for(;i>=0;i--)
//	{
//		printf("%d %d\n",t1[i].d,t1[i].m);
//	}
//	for(;j>=0;j--)
//	{
//		printf("%d %d\n",t2[j].d,t2[j].m);
//	}
	int k=0;
	int num1=i;
	int num2=j;
	for(i=0;i<num1+1;i++)
	{
		for(j=0;j<num2+1;j++)
		{
			t[k].d=t1[i].d*t2[j].d;
			t[k].m=t1[i].m+t2[j].m;
			k++;
		}
	}
	for(i=0;i<k-1;i++)
	{
		for(j=i+1;j<k;j++)
		{
			if(t[i].m==t[j].m)
			{
				t[i].d=t[i].d+t[j].d;
				t[j].d=0;
			}
		}
	}
	qsort(t,k,sizeof(t[0]),fun);
	for(i=0;i<k;i++)
	{
		if(t[i].d==0)
		{
			continue;
		}
		printf("%d %d ",t[i].d,t[i].m);
	}
	return 0;
}

