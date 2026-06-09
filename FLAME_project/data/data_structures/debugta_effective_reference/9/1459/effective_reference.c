#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	int x1;
	int x2;
	int y1;
	int y2;
	int num;
}array[500];
void sort(struct node array[],int n);
void sort1(struct node array[],int n);
int main()
{
	int n;
	int i;
	int m=0;
	int j=0;
	int a[100]={0};
	int b[100]={0};
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&array[i].x1,&array[i].y1,&array[i].x2,&array[i].y2);
	}
	sort(array,n);
	for(i=0;i<n;i++)
	{
		array[i].num=1;
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(array[i].x2==array[j].x1&&array[i].y2==array[j].y1)
			{
				array[i].x2=array[j].x2;
				array[i].y2=array[j].y2;
				array[i].num=array[i].num+1;
			}
		}
	}
	sort1(array,n);
	printf("%d %d %d",array[n-1].num,array[n-1].x1,array[n-1].y1);
	return 0;
}
void sort(struct node array[],int m)
{
	struct node tmp;
	int i;
	int j;
	for(i=0;i<m;i++)
	{
		for(j=i+1;j<m;j++)
		{
			if(array[i].x1>array[j].x1)
			{
				tmp=array[i];
				array[i]=array[j];
				array[j]=tmp;
			}
			if(array[i].x1==array[j].x1&&array[i].y1>array[j].y1)
			{
				tmp=array[i];
				array[i]=array[j];
				array[j]=tmp;
			}
		}
	}
}
void sort1(struct node array[],int m)
{
	int i;
	int j;
	struct node temp;
	for(i=0;i<m;i++)
	{
		for(j=i+1;j<m;j++)
		{
			if(array[i].num>array[j].num)
			{
				temp=array[i];
				array[i]=array[j];
				array[j]=temp;
			}
		}
	}
}



