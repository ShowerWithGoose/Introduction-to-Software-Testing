#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	int a[1024],b[1024],c[1024],d[1024],i=0,j=0,m,n,t=0,k;
	int p[1024],q[1024];
	while(1)
	{
		scanf("%d%d",&a[i],&b[i]);i++;
		if(getchar()=='\n') break;
	}
	while(1)
	{
		scanf("%d%d",&c[j],&d[j]);j++;
		if(getchar()=='\n') break;
	}
	for(m=0;m<i;m++)
	{
		for(n=0;n<j;n++)
		{
			q[t]=b[m]+d[n];
			p[t]=a[m]*c[n];
			t++;
		}
	}
	if(t==1) printf("%d %d ",p[0],q[0]);
	else
	{
	for(k=0;k<t;k++)
	{
		for(i=0;i<t-k;i++)
		{
			int temp1,temp2;
			if(q[i+1]>q[i])
			{
				temp1=q[i+1];
				q[i+1]=q[i];
				q[i]=temp1;
				temp2=p[i+1];
				p[i+1]=p[i];
				p[i]=temp2;
			}
		}
	}
	for(k=0;k<t-1;k++)
	{
		if(q[k+1]==q[k])
		{
			p[k]+=p[k+1];
			for(i=k+1;i<t-1;i++)
			{
				q[i]=q[i+1];p[i]=p[i+1];
			}
			t--;k--;
		}
	}
	for(k=0;k<t;k++)
	{
		if(p[k]!=0)
		printf("%d %d ",p[k],q[k]);
	}
	
    }
	return 0;
}



