#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
int zdd( int a[] ,int b[] ,int c[] ,int d[] ,int ,int);
int ts(int a[] ,int b[] ,int c[] ,int d[] ,int ,int ,int);

int main()
{
	int n,ans=0,i,p;
	int x=0,y=0,tm=0;
	int x1[105],y1[105],x2[105],y2[105];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&x1[i],&y1[i],&x2[i],&y2[i]);
	}	//把所有的线段读进来 并且保证x1<x2，保证x1为端点 
	for(i=0;i<n;i++)
	{
	int k=1;
	if(tm<ts(x1,x2,y1,y2,i,k,n))
	{
	tm=ts(x1,x2,y1,y2,i,k,n);
	p=zdd(x1,x2,y1,y2,i,n);
	x=x1[p];
	y=y1[p];
	}
	}
	printf("%d %d %d",tm,x,y);
 } 
  int zdd(int x1[],int x2[] ,int y1[],int y2[] ,int i,int n)
 {
 	int j=0;
	for(j=0;j<n;j++)
	{if((x1[i]==x2[j])&&(y1[i]==y2[j]))
	{
	i=j;
    return	zdd(x1,x2,y1,y2,i,n);
	}
	}
	return i;	 
	
	
	 }
int ts( int x1[],int x2[] ,int y1[],int y2[] ,int i,int k,int n)
 {
 	int j;
	for(j=0;j<n;j++)
	{if((x1[i]==x2[j])&&(y1[i]==y2[j]))
	 return ts(x1,x2,y1,y2,j,k+1,n);}
	return k;
	 }



