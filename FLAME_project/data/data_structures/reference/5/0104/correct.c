#include<stdio.h>
#define int long long

typedef struct {int a,x;} pp;

pp a1[1005],b1[1005],c[1000005],d[1000005];
int n1=0,n2=0;

void read(pp *a,int *n)
{
	char ch=getchar();
	int k=0;
	while(1)
	{
		while(ch<'0'||ch>'9') 
		{
			if(ch=='\n'||ch==EOF) break;
			ch=getchar();
		}
		if(ch=='\n'||ch==EOF) break;
		int x=0;
		while(ch>='0'&&ch<='9')
		{
			x=x*10+ch-'0';
			ch=getchar();
		}
		if(k==0) a[++(*n)].a=x;else a[*n].x=x;
		k=1-k;
	}
}

void merge(int l,int r)
{
	if(l==r) return;
	int mid=(l+r)>>1;
	merge(l,mid);
	merge(mid+1,r);
	int i=l,j=mid+1,t=l;
	while((i<=mid)&&(j<=r))
	{
		if(c[i].x>c[j].x) d[t++]=c[i++];else d[t++]=c[j++];
	}
	while(i<=mid) d[t++]=c[i++];
	while(j<=r) d[t++]=c[j++];
	for(int i=l;i<=r;i++) c[i]=d[i];
}

signed main()
{
	read(a1,&n1);read(b1,&n2);
	for(int i=1;i<=n1;i++)
		for(int j=1;j<=n2;j++)
		{
			int yu=(i-1)*n2+j;
			c[yu].a=a1[i].a*b1[j].a;
			c[yu].x=a1[i].x+b1[j].x;
		}
	merge(1,n1*n2);
	for(int i=1;i<=n1*n2;i++)
	{
		int yu=c[i].a;
		while(c[i].x==c[i+1].x)
		{
			yu+=c[i+1].a;
			i++;
			if(i>=n1*n2) break;
		}
		printf("%lld %lld ",yu,c[i].x);
	}
	return 0;
}

