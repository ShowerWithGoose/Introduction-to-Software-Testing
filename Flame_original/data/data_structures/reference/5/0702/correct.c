#include <stdio.h>
int main()
{
	int a1[1000],b1[1000],a2[1000],b2[1000],c1[1000],c2[1000];
	int t1=0,t2=0,m=1,temp1,temp2;
	char judge1[100],judge2[100];
	for(a1[t1],b1[t1];;)
	{
		t1++ ;
		scanf("%d%d%c",&a1[t1],&b1[t1],&judge1[t1]);
		if(judge1[t1]=='\n') break;
	}
	for(a2[t2],b2[t2];;)
	{
		t2++ ;
		scanf("%d%d%c",&a2[t2],&b2[t2],&judge2[t2]);
		if(judge2[t2]=='\n') break;
	}
	for(int i=1;i<=t1;i++)
	{
		for(int j=1;j<=t2;j++)
		{
			c1[m]=a1[i]*a2[j];
			c2[m]=b1[i]+b2[j];
			m++;
		}
	}
	for(int i=1;i<=m-1;i++)
	{
		for(int j=i+1;j<=m;j++)
		{
			if(c2[i]<c2[j])
			{
				temp1=c1[i];
				c1[i]=c1[j];
				c1[j]=temp1;
				temp2=c2[i];
				c2[i]=c2[j];
				c2[j]=temp2;
			}
			else if(c2[i]==c2[j])
			{
				c1[i]+=c1[j];
				for(int w=j;w<m;w++)
				{
					c1[w]=c1[w+1];
					c2[w]=c2[w+1];
				}
				m--;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(c1[i]==0)
		{
			for(int w=i;w<m;w++)
			{
				c1[w]=c1[w+1];
				c2[w]=c2[w+1];
			}
			m--;
		}
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d %d ",c1[i],c2[i]);
	}
	return 0;
}

