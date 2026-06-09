#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	typedef struct node{
		long long exp;
		long long co;
	}NODE;
	NODE a[1005],b[1005],c[1005];
	char t=' ';
	int x=0;
	while(t!='\n')
	{
		scanf("%d%d%c",&a[x].co,&a[x].exp,&t);
		x++;
	}
	t=' ';
	int y=0;
	while(t!='\n')
	{
		scanf("%d%d%c",&b[y].co,&b[y].exp,&t);
		y++;
	}
	int i,j,k=0;
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			c[k].exp=a[i].exp+b[j].exp;
			c[k].co=a[i].co*b[j].co;
			k++;
		}
	}
	NODE temp;
	for(i=0;i<k-1;i++)
	{
	   	int f;
	   	for(j=0;j<k-i-1;j++)
	   	{
	   		if(c[j].exp<c[j+1].exp)
	   		{
			   temp.co=c[j].co;
	   		   temp.exp=c[j].exp;
	   		   c[j].co=c[j+1].co;
	   		   c[j].exp=c[j+1].exp;
	   		   c[j+1].co=temp.co;
	   		   c[j+1].exp=temp.exp;
	   		   f=0;
	   	    }
		}
		if(f==1)break;
	}
	for(i=0;i<k;i++)
	{
		if(c[i].exp==c[i+1].exp&&c[i].exp!=0)
		{
			c[i+1].co=c[i+1].co+c[i].co;
			c[i].co=0;
		}
	}
	for(i=0;i<k;i++)
	{
		if(c[i].co!=0)printf("%d %d ",c[i].co,c[i].exp);
	}
	
	return 0;
} 

