#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a,x[205]={1};
	int i,c=0;
	i=0;
	while(scanf("%d",&a)!=EOF)
	{
		if(a==1)
		{
		c++;	
		continue;}
		else if(a==-1)
			break;
		else if(a==0)
			i=i;
		else
		{
			x[c-1]=a;
			i++;
		}
		if(a==0&&(i<=0))
			{printf("error ");
			i=0;
			}
		if(a==0&&i>=1&&i<=100)
		{
			printf("%d ",x[c-1]);
			c--;
			i--;
		}
		if(c>100&&a==1)
		printf("error "); 
		    
	}
	return 0;	
}

