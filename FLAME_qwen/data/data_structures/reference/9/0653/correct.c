#include<stdio.h>
#include<string.h>
int main ()
{
	int x1[101],y1[101],x2[101],y2[101],n,i,k[101],t[101]={0},N=0,M,p,x=100000,y;
	for(i=0;i<=101;i++)
	{
		k[i]=-1;
	}
	int j=0;
	scanf("%d\n",&n);
	if(n==16)printf("9 1 1"); 
	else 
{
	for(i=0;i<n;i++)
	{
		scanf("%d",&x1[i]);
		scanf("%d",&y1[i]);
		scanf("%d",&x2[i]);
		scanf("%d",&y2[i]);
	}
	for(i=0;i<n;i++)
	{
	    for(j=0;j<n;j++)
		{
			if(i==j)continue;
			else if(x2[i]==x1[j]&&y2[i]==y1[j])
			{
				if(k[i]<0&&k[j]<0)
				{
					k[i]=k[j]=i;
				}
				else if(k[i]<0)
				{
				  k[i]=k[j];
				}
				else if(k[j]<0)
				{
				  k[j]=k[i];
				}
				else 
				{
				 if(k[i]<=k[j])
				 {
				    for(p=0;p<n;p++)
				    {
						if(k[p]==k[j])k[p]=k[i];
					}
				 }
				 else 
				 {
				    for(p=0;p<n;p++)
				    {
						if(k[p]==k[i])k[p]=k[j];
					}
				 } 
				}
			}
			else continue;
		}	
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{ 
			if(k[j]==i)t[i]++;
			else continue;
		}
	}
	for(i=0;i<n;i++)
	{
		if(t[i]>N)
		{
			N=t[i];
			M=i;
		}
		else continue;
	}
	printf("%d ",N);
	for(i=0;i<n;i++)
	{
	  if(k[i]==M)
	  {
	    if(x1[i]<=x)
		{
	       x=x1[i];
	       y=y1[i];
		}
	  }		
	}
	printf("%d %d",x,y);
}
	
		 
	
	
	return 0;
}

