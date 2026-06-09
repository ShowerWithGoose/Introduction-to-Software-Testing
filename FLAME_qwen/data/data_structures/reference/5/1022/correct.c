#include<stdio.h>
#include<stdlib.h>
int a[1000][5];
int b[1000][5];
int c[1000][5];
int main()
{
	int i,j;
	int len1=0,len2=0;
	char p;
	int k=0;
	int x,y;
	for(i=1;;i++)
	{
		for(j=1;j<=2;j++)
		{
			scanf("%d%c",&a[i][j],&p);
			len1++;
		}
		if(p=='\n')
		break;
	}
	for(i=1;;i++)
	{
		for(j=1;j<=2;j++)
		{
			scanf("%d%c",&b[i][j],&p);
			len2++;
		}
		if(p=='\n')
		break;
	}
	len1/=2;
	len2/=2;
	for(i=1;i<=len1;i++)
	{
		for(j=1;j<=len2;j++)
		{
			k++;
			c[k][1]=a[i][1]*b[j][1];
			c[k][2]=a[i][2]+b[j][2];
		}
	}
	for(i=1;i<k;i++)
	{
		for(j=i+1;j<k;j++)
		{
			if(c[i][2]>c[j][2])
			continue;
			else if(c[i][2]==c[j][2])
			{
				c[i][1]+=c[j][1];
				c[j][1]=0;
				c[j][2]=-1;
			
			}
			
		}
	}
	for(i=1;i<k;i++)
	{
		for(j=i+1;j<=k;j++)
		{
			if(c[j][2]>c[i][2])
			{
				x=c[i][1];
				y=c[i][2];
				c[i][1]=c[j][1];
				c[i][2]=c[j][2];
				c[j][1]=x;
				c[j][2]=y;
			}
			
		}
	}
		
	for(i=1;i<=k;i++)
	{
		if(c[i][2]<0)
		break;
		for(j=1;j<=2;j++)
		{
			printf("%d ", c[i][j]);
		
		}
		
	}
}

