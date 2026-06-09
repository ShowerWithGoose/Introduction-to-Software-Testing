#include<stdio.h>

struct shu
{
	int coe[1000];
	int index[1000];
};

int main()
{
	int i,j,k=0,ia,ib,ic,temp;
	char s=0;
	struct shu a,b,c;
	i=0;
	for(i=0;s!='\n';i++)
	{
		scanf("%d%d",&a.coe[i],&a.index[i]);
		s=getchar();
	}
	ia=i;i=0;
	s=0;
	for(i=0;s!='\n';i++)
	{
		scanf("%d%d",&b.coe[i],&b.index[i]);
		s=getchar();
	}
	ib=i;
	for(i=0;i<ia;i++)
	{
		for(j=0;j<ib;j++)
		{
			c.coe[k]=a.coe[i]*b.coe[j];
			c.index[k]=a.index[i]+b.index[j];
			k++;
		}
	}
	ic=k;
	for(i=0;i<ic;i++)
	{
		for(j=i+1;j<ic;j++)
		{
			if(c.index[i]<c.index[j])
			{
				temp=c.index[i];
				c.index[i]=c.index[j];
				c.index[j]=temp;
				temp=c.coe[i];
				c.coe[i]=c.coe[j];
				c.coe[j]=temp;
			}
			else if(c.index[i]==c.index[j])
			{
				c.coe[i]=c.coe[i]+c.coe[j];
				c.coe[j]=0;
			}
		}
	}
	for(i=0;i<ic;i++)
	{
		if(c.coe[i]!=0)
		{
			printf("%d %d ",c.coe[i],c.index[i]);
		}
	}
}

