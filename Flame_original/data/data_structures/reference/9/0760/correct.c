#include<stdio.h>
#include<string.h>
struct a{
	int b[10];
}a[110],c;
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i=i+1)
	{
		for(j=0;j<4;j=j+1)
		{
			scanf("%d",&a[i].b[j]);
		}
	}
	for(i=0;i<n-1;i=i+1)
	{
		for(j=i+1;j<n;j=j+1)
		{
			if(a[i].b[0]>a[j].b[0])
			{
				c=a[j];
				a[j]=a[i];
				a[i]=c;
			}
		}
	}
	int t=0,p,q=0,d[5];
	for(i=0;i<n-1;i=i+1)
	{
		t=1;
		p=i;
		for(j=i+1;j<n;j=j+1)
		{
			if(a[p].b[2]==a[j].b[0]&&a[p].b[3]==a[j].b[1])
			{
				t=t+1;
				p=j;
			}
		}
		if(t>q)
		{
			q=t;
			d[0]=a[i].b[0];
			d[1]=a[i].b[1];
		}
	}
	printf("%d %d %d",q,d[0],d[1]);
	return 0;
}

