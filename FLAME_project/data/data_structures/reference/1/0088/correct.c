#include<stdio.h>
#include<string.h>

int a[20],b[20],n;





void re(int x)
{
	
	int i;
	if(x==n)
	
	{
	for(i=0;i<n;i++)
	{
	printf("%d ",a[i]);
	}
	printf("\n") ;
	
	}
	else
	for(i=0;i<n;i++)
	{
		if(b[i]==0)
		  {
		  	b[i]=1;
		    a[x]=i+1;
		    re(x+1);
		    b[i]=0;
	      }
	}
	
	
}



int main()
{
	scanf("%d",&n);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            	
	re(0);
	return 0;
	
	
	
 } 

