#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct dat{
	int x1;
	int y1;
	int x2;
	int y2;
}xianduan[105];

void paixu(struct dat in[],int lenth);
int pipei(int i,int lenth,int x);
int shumu;

int main()
{
	int n,i;
	int jishu=1;
	int maxshu=0;
	int maxduan=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&xianduan[i].x1,&xianduan[i].y1,&xianduan[i].x2,&xianduan[i].y2);
	}
	paixu(xianduan,n);
	for(i=0;i<n;i++)
	{
		shumu=pipei(i,n,jishu);
		if(shumu>maxshu)
		{
			maxshu=shumu;
			maxduan=i;
		}
	}
	printf("%d %d %d",maxshu,xianduan[maxduan].x1,xianduan[maxduan].y1);
	return 0;
 } 
 
void paixu(struct dat in[],int lenth)
{
	int i,j;
	struct dat temp;
	for(i=0;i<lenth;i++)
	{
		for(j=i+1;j<lenth;j++)
		{
			if(in[i].x1>in[j].x1)
			{
				temp=in[i];
				in[i]=in[j];
				in[j]=temp;
			}
		}
	}
}

int pipei(int i,int lenth,int x)
{
	int flag=0,j;
	for(j=i+1;j<lenth;j++)
	{
		if(xianduan[j].x1==xianduan[i].x2&&xianduan[j].y1==xianduan[i].y2)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		x++;
		pipei(j,lenth,x);
	}
	else
	return x;
}

