/*#include<stdio.h>
#include<stdlib.h>
struct coordinate{
	int x1,y1,x2,y2;
	struct coordinate *next;
}*a[105];
int len[105];
int main()
{
	int n,i,j,k,max=0,flag;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&a[i]->x1,&a[i]->y1,&a[i]->x2,&a[i]->y2);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n,j!=i;j++)
		{
			if(a[i]->x2==a[j]->x1&&a[i]->y2==a[j]->y1)
			{
				a[i]->next=a[j];
				a[j]->next=NULL;
			}
			else if(a[i]->x1==a[j]->x2&&a[i]->y1==a[j]->y2)
			{
				a[j]->next=a[i];
				a[i]->next=NULL;
			}
			else
			{
				a[i]->next=NULL;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		while(a[i]!=NULL)
		{
			len[i]++;
			a[i]=a[i]->next;
		}
		if(len[i]>max)
		{
			max=len[i];
			flag=i;
		}
	}
	printf("%d %d %d",max,a[flag]->x1,a[flag]->y1);
	return 0;
}*/


#include<stdio.h>
struct coordinate{
	int x1,y1,x2,y2;
}a[105],temp;
int main()
{
	int n,i,j,k,max=0,len,flag;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i].x1>a[j].x1)
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		len=1;k=i;
		for(j=i+1;j<n;j++)
		{
			
			if(a[k].x2==a[j].x1&&a[k].y2==a[j].y1)
			{
				len++;
				k=j;
			}
		}
		if(len>max)
		{
			max=len;
			flag=i;
		}
	}
	printf("%d %d %d",max,a[flag].x1,a[flag].y1);
	return 0;
}



