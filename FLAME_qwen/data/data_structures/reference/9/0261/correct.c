#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int compare( int x1[],int x2[] ,int y1[],int y2[] ,int i,int t,int n)
 {
  	int j;
 	for(j=0;j<n;j++)
 	{
 		if((x1[i]==x2[j])&&(y1[i]==y2[j]))
  		return compare(x1,x2,y1,y2,j,t+1,n);
	}
 	return t;
  }

int record(int x1[],int x2[] ,int y1[],int y2[] ,int i,int n)
{
	int j=0;
	 for(j=0;j<n;j++)
	 {
	 	if((x1[i]==x2[j])&&(y1[i]==y2[j]))
	 	{
	 		i=j;
	    	return record(x1,x2,y1,y2,i,n);
	 	}
	 }
	 return i;  
}

int main()
{
	int n,i=0,x=0,y=0,ans=0,p;
	int x1[104],y1[104],x2[104],y2[104];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&x1[i], &y1[i], &x2[i], &y2[i]);
	}
	for(i=0;i<n;i++)
	 {
	 	int k=1;
	 	if(ans<compare(x1,x2,y1,y2,i,k,n))
	 	{
	 		ans=compare(x1,x2,y1,y2,i,k,n);
	 		p=record(x1,x2,y1,y2,i,n);
	 		x=x1[p];
	 		y=y1[p];
	 	}
	 }
	 printf("%d %d %d",ans,x,y);
}

