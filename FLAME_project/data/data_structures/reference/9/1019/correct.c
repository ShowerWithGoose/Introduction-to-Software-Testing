#include<stdio.h>

int chuli(int *x1,int *y1,int *x2,int* y2,int wei,int n)
{
	int cishu=1;
	for(int i=0;i<n;i++)
	{
		if(x1[i]==x2[wei]&&y1[i]==y2[wei])
		{
			cishu=chuli(x1,y1,x2,y2,i,n)+1;
		}
	}
	
	
	return cishu;
	
}

int main()
{
	int n;
	int x1[100]={};
	int y1[100]={};
	int x2[100]={};
	int y2[100]={};
	int xianduan[100]={};
	
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
	}
	
	for(int i=0;i<n;i++)
	{
		xianduan[i]=chuli(x1,y1,x2,y2,i,n);
	}
	
	int j=0;
	for(int i=1;i<n;i++)
	{
		if(xianduan[j]<xianduan[i]) j=i;
	}
	
	printf("%d %d %d",xianduan[j],x1[j],y1[j]);
	
	return 0;
	
}

