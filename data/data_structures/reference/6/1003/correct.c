#include <stdio.h>
#include <math.h>
#include <string.h>
int a[101];
int main()
{
 	int i=1;
 	int b;
 	while(scanf("%d",&b)!=-1)
 	{

 		if(b==1)
 		{
			if(i>100)
			{
				printf("error ");
				int c;
				scanf("%d",&c);
				continue;
			}
			if(i<=0)
			{
				i=1;
			}
		 	scanf("%d",&a[i]);
		 	i++;
		}
		else if(b==0)
		{
			i--;
			if(i<=0)
			{
			 	printf("error ");
			 	continue;
			}
			
			printf("%d ",a[i]);
			
		}
		
	}
 	
	return 0;
}

