#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define eps 1e-9
struct duo
{
	long long xs;
	long long ms;
};
void sort(struct duo a[],int n);
void hb(struct duo a[],int n);
struct duo dxs1[1024];
struct duo dxs2[1024];
struct duo dxs3[1024];
int main()
{
	int i=0;
	int j=0,k=0;
	int i1=0,j1=0;
	char c;
	while(1)
	{
		scanf("%lld%lld%c",&dxs1[i].xs,&dxs1[i].ms,&c);
		if(c=='\n')
		{
			break;
		}
		i++;
	}
	while(1)
	{
		scanf("%lld%lld%c",&dxs2[j].xs,&dxs2[j].ms,&c);
		if(c=='\n')
		{
			break;
		}
		j++;
	}
	for(i1=0;i1<=i;i1++)
	{
		for(j1=0;j1<=j;j1++)
		{
			dxs3[k].xs=(dxs1[i1].xs)*(dxs2[j1].xs);
			dxs3[k].ms=(dxs1[i1].ms)+(dxs2[j1].ms);
			k++;
		}
	}
	//for(i=0;i<k;i++)
	//{
	//	if(dxs3[i].ms!=-1)
	//	{
	//		printf("%d %d",dxs3[i].xs,dxs3[i].ms);
	//	}
	//}
	sort(dxs3,k);
	hb(dxs3,k);
	for(i=0;i<k;i++)
	{
		if((dxs3[i].ms)!=-1&&(dxs3[i].xs)!=0)
		{
			printf("%lld %lld ",dxs3[i].xs,dxs3[i].ms);
		}
	}
	return 0;
}
void sort(struct duo a[],int n)
{
	struct duo temp;
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(a[i].ms<a[j].ms)
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
void hb(struct duo a[],int n)
{
	int i;
	int j;
	for(i=0;i<n;i++)
	{
		j=i+1;
		while((a[j].ms==a[i].ms)&&j<n-1&&a[i].ms!=-1)
		{
			a[i].xs+=a[j].xs;
			a[j].ms=-1;
			j++;
		}
	}
}

