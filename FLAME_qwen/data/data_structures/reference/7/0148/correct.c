#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>


int main()
{
	int n,i,a[200],b[200]={0},c[200]={0},j,k,l,num[200][200],flag[200][200]={0},no[200];
	scanf("%d%d",&n,&a[1]);
	num[1][1]=a[1];
	flag[1][1]=-1;
	b[1]=1;
	c[1]=1;
	for(i=2;i<=n;i++)
	{
		scanf("%d",&a[i]);
		j=1;k=1;
		if(a[i]<num[j][k])
		{
			j=2;
			k=1;
		}
		else if(a[i]>=num[j][k])
		{
			j=2;
			k=2;
		}
		while(flag[j][k]==-1)
		{
			if(a[i]<num[j][k])
			{
				j++;
				k=2*k-1;
			}
			else if(a[i]>num[j][k])
			{
				j++;
				k=2*k;
			}
		}
		num[j][k]=a[i];
		flag[j][k]=-1;
		b[i]=j;
		c[i]=k;
	}
	j=0;
	for(i=1;i<=n;i++)
	{
		if(flag[b[i]+1][2*c[i]-1]!=-1&&flag[b[i]+1][2*c[i]]!=-1)
		{
			++j;
			no[j]=i;
		}
	}
	for(i=1;i<j;i++)
	{
		for(l=i+1;l<=j;l++)
		{
			if(a[no[i]]>a[no[l]])
			{
				k=no[i];
				no[i]=no[l];
				no[l]=k;
			}
		}
	}
	for(i=1;i<=j;i++)
	{
		printf("%d %d\n",a[no[i]],b[no[i]]);
	}
	
	
	return 0;
}

