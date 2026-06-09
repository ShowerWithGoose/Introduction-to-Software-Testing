#include <stdio.h>

int main()
{
	int i,data,a[100];
	for(i=0;;)
	{
		scanf("%d",&data);
		if(data==-1) return 0;
		if(data==1)
		{
			scanf("%d",&a[i++]);
		    if(i==101)
		    {
		    	printf("error ");
		    	i--;
			}
		}
		if(data==0) 
		{
			if(i==0) printf("error ");
			else printf("%d ",a[--i]);
		}
	}
	

	
	return 0;
} 

