#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	int x1;
	int x2;
	int y1;
	int y2;
	int k;
}list[500];
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
		scanf("%d %d %d %d",&list[i].x1,&list[i].y1,&list[i].x2,&list[i].y2);
	}
	sort(list,n);
	for(i=0;i<n;i++)
	{
		list[i].k=1;
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(list[i].x2==list[j].x1&&list[i].y2==list[j].y1)
			{
				list[i].x2=list[j].x2;
				list[i].y2=list[j].y2;
				list[i].k=list[i].k+1;
			}
		}
	}
	sort1(list,n);
	printf("%d %d %d",list[n-1].k,list[n-1].x1,list[n-1].y1);
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
			if(array[i].k>array[j].k)
			{
				temp=array[i];
				array[i]=array[j];
				array[j]=temp;
			}
		}
	}
}



