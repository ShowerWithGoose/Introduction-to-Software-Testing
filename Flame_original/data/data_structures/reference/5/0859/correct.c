#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int delet[100];
struct node{
	int a;
	int x;
	int b;
	int y;
}index[500];
struct node1{
	long long A;
	long long X;
	int a;
}manu[500];
void swap(int a,int b)
{
	long long m;
	m=manu[a].A;
	manu[a].A=manu[b].A;
	manu[b].A=m;
	m=manu[a].X;
	manu[a].X=manu[b].X;
	manu[b].X=m;
	m=manu[a].a;
	manu[a].a=manu[b].a;
	manu[b].a=m;
	
}
int main()
{
	int i=0,j=0;
	for(i=0;scanf("%d %d",&index[i].a,&index[i].x)!=EOF;i++)
	{
		if(getchar()=='\n')
		break;
	}
	i++;
	for(j=0;scanf("%d %d",&index[j].b,&index[j].y)!=EOF;j++);
	int m,n,k=0;
	for(m=0;m<i;m++)
	{
		for(n=0;n<j;n++)
		{
			manu[k].A=index[m].a*index[n].b;
			manu[k].X=index[m].x+index[n].y;
			manu[k].a=1;
			k++;
		}
	}
	for(j=0;j<k-1;j++)
	{
	for(i=0;i<k-1-j;i++)
	{
		if(manu[i].X<manu[i+1].X&&manu[i].a>0&&manu[i+1].a>0)
		swap(i,i+1);
	}
	}
	for(i=0;i<k-1;i++)
	{
		if(manu[i].X==manu[i+1].X&&manu[i].a>0&&manu[i+1].a>0)
		{
			manu[i+1].A+=manu[i].A;
			manu[i].a=-1;
		}
	} 
	for(i=0;i<k;i++)
	{
		if(manu[i].a>=0)
		printf("%lld %lld ",manu[i].A,manu[i].X);
	}
	return 0;
}

