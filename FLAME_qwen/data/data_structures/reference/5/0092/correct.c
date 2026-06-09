#include<stdio.h>
#include<string.h>
int main()
{
	int a1[100]={0},a2[100]={0},b1[100]={0},b2[100]={0};
	int c1[10000],c2[10000];
	int i=0,j=0,k=0,h;
	char c=' ';
	while(c!='\n')
	{
		scanf("%d%d%c",&a1[i],&b1[i],&c);
		i++;
	}
	int n=i;
	c=' ';
	while(c!='\n')
	{
		scanf("%d%d%c",&a2[j],&b2[j],&c);
		j++;
	}
	int m=j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			c1[k]=a1[i]*a2[j];
			c2[k]=b1[i]+b2[j];
			k++;
		}
	}//Éú³É±í
	for(i=1;i<k;i++) 
	{
		for(j=0;j<i;j++)
		{
			if(c2[j]==c2[i])
			{
				c1[j]=c1[j]+c1[i];
				for(h=i;h<k;h++)
				{
					c1[h]=c1[h+1];
					c2[h]=c2[h+1];
				}
				k--;
				i--;
				break;
			}
		}
	}
	int temp;
	for(i=0;i<k;i++)
	{
		for(j=k-1;j>i;j--)
		{
			if(c2[j]>c2[j-1])
			{
				temp=c2[j];
				c2[j]=c2[j-1];
				c2[j-1]=temp;
				temp=c1[j];
				c1[j]=c1[j-1];
				c1[j-1]=temp;
			}
		}
	}
	for(i=0;i<k;i++)
	{
		printf("%d %d ",c1[i],c2[i]);
	}
	return 0;
}

