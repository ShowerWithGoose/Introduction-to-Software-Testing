#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int x1[105]={0};
int y1[105]={0};
int x2[105]={0};
int y2[105]={0};
int num[105]={0};
int max_num(int num[],int n)
{
	int k=0,tmp=0;
	for(k=0;k<n;k++)
	{
		if(tmp<=num[k])
		tmp=num[k];
		else
		continue;
	}
	return tmp;
}

void search(int x1[],int x2[],int y1[],int y2[],int num[],int n)
{
	int k=0,l=0,x,y;
	for(k=0;k<n;k++)
	{
		x=x2[k];
		y=y2[k];
		for(l=0;l<n;l++)
		{
			if(x==x1[l]&&y==y1[l]&&k!=l)
			{
				num[k]++;
				x=x2[l];
				y=y2[l];
			}
		}
	}
}

void sort(int x1[],int x2[],int y1[],int y2[],int n)
{
	int i=0,j=0,flag=0,hold;
	for(i=0;i<n-1;i++)
	{
		flag=0;
		for(j=0;j<n-1-i;j++)
		{
			if(x1[j]>x1[j+1])
			{
				hold=x1[j];
				x1[j]=x1[j+1];
				x1[j+1]=hold;
				hold=x2[j];
				x2[j]=x2[j+1];
				x2[j+1]=hold;
				hold=y1[j];
				y1[j]=y1[j+1];
				y1[j+1]=hold;
				hold=y2[j];
				y2[j]=y2[j+1];
				y2[j+1]=hold;
				flag=1;
			}
		}
		if(0==flag)
		{
			break;
		}
	}
}

int main()
{
	int n,i=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	    num[i]=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&x1[i]);
		scanf("%d",&y1[i]);
		scanf("%d",&x2[i]);
		scanf("%d",&y2[i]);
	}
	sort(x1,x2,y1,y2,n);
	search(x1,x2,y1,y2,num,n);
	printf("%d ",max_num(num,n)+1);
	for(i=0;i<n;i++)
	{
		if(num[i]==max_num(num,n))
		{
			printf("%d %d",x1[i],y1[i]);
			break;
		}
	}
}
	
