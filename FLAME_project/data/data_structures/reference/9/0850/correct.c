#include<stdio.h>
#include<stdlib.h>
#include<string.h>	
struct line{
	int	qd[2];
	int zd[2];
	int time;
	};
struct line l[100];
int qd[1000];
int searchq(int a,int i,int n)
{
	int j;
	for(j=0;j<n;j++)
	{
		if(l[j].zd[0]==l[i].qd[0]&&l[j].zd[1]==l[i].qd[1])
		{
			return searchq(a,j,n)+1;
		}
	}
	qd[a]=i;
	return 1;
}

int searchz(int i,int n)
{
	int j;
	for(j=0;j<n;j++)
	{
		if(l[j].qd[0]==l[i].zd[0]&&l[j].qd[1]==l[i].zd[1])
		{
			return searchz(j,n)+1;
		}
	}
	return 1;
}
/*int search(int qd[],int zd[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		if(l[i].qd[0]==zd[0]&&l[i].qd[1]==zd[1])
		{
			return(qd,l[i].zd,n)+1;
		}
		if(l[i].zd[0]==qd[0]&&l[i].zd[1]==qd[1])
		{
			return(l[i].qd,zd,n)+1;
		}
	}
	return 1;
}*/

int main()
{


	int i,n,j;
	scanf("%d",&n);
	while(getchar()!='\n');
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&l[i].qd[0],&l[i].qd[1],&l[i].zd[0],&l[i].zd[1]);
		l[i].time=1;
		while(getchar()!='\n');
	}
	int *q,*z;
	int max=0,t[100];
	for(i=0;i<n;i++)
	{
		t[i]=searchq(i,i,n)+searchz(i,n)-1;
	//	printf("%d %d %d\n",searchq(i,i,n),searchz(i,n),t[i]);
		if(t[i]>max)
		max=t[i];
	}
	printf("%d ",max);
	for(i=0;i<n;i++)
	{
		if(t[i]==max)
		{
			printf("%d %d",l[qd[i]].qd[0],l[qd[i]].qd[1]);
			break;
		}
	}
	return 0;
	
	
	
}

