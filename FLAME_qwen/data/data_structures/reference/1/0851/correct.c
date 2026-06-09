#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define ep 1e-6
#define pi 3.14159265
#define pf printf
#define sf scanf
#define ll long long
#define ull unsigned long long
#define NumberOf(x) (sizeof(x)/sizeof(x[0])
#define max(A,B) ((A)>(B)?(A):(B))

void quanpai(int a[],int n,int x);
int num[10000000][15],j=0; 
int cmp(const void *p1,const void *p2);
int N(int n);
int main()
{
	int n,a[15],i,k;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		a[i]=i+1;
	}
	quanpai(a,n,0);
	int s=N(n);
	qsort(num,s,15*sizeof(int),cmp);
	for(i=0;i<s;i++)
	{
		for(k=0;k<n;k++)
		{
			printf("%d ",num[i][k]);
		}
		puts("");
	}
}
void quanpai(int a[],int n,int x)
{
	int i,b;
	if(x>=n-1)
	{
		for(i=0;i<n;i++)
		{
			num[j][i]=a[i];
		}
		j++;
	}
	else
	{
		for(i=x;i<n;i++)
		{
			b=a[x];
			a[x]=a[i];
			a[i]=b;
			quanpai(a,n,x+1);
			b=a[x];
			a[x]=a[i];
			a[i]=b;			
		}
	}
}
int cmp(const void *p1,const void *p2)
{
	int i;
	for(i=0;i<15;i++)
	{
		if(((int*)p1)[i]<((int*)p2)[i])
		return -1;
		else if(((int*)p1)[i]>((int*)p2)[i])
		return 1;
		else
		continue;
	}
	return 1;
}
int N(int n)
{
	int s=1;
	for(int i=1;i<=n;i++)
	{
		s=s*i;
	}
	return s;
}

