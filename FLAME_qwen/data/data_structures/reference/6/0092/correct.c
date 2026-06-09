#include<stdio.h>
int main()
{
	int a[10000],b[10000],c[200];
	int p=0,q;
	int i=0,n=0,k=0;
	scanf("%d",&p);
    a[i]=p;
	i++;
	while(p!=-1)
	{
		if(p==1)
		{
			scanf("%d",&q);
			b[k]=q;
			k++;
		}
		if(p==-1)
		{
			break;
		}
		scanf("%d",&p);
		a[i]=p;
		i++;
	}
	int j=0;
	int h=0;
	int d=0;
	for(j=0;j<i;j++)
	{
		if(a[j]==1)
		{
			if(h>=99)
			{
				printf("error ");
				h=99;
			}
			if(h<99)
			{
				c[h]=b[d];
				d++;
				h++;
			}
		}
		if(a[j]==0)
		{
			if(h>=1)
			{
				printf("%d ",c[h-1]);
				h--;
			}
			else
			{printf("error ");
			h=0;
			}
		}
		if(a[j]==-1)
		{
			break;
		}
	}
	return 0;
} 

