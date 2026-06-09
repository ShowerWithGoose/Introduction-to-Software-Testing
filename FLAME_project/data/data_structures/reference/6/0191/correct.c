#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
int main()
{
	int a[100]={0};
	int op,num,i=0;
	while(scanf("%d ",&op)!=EOF)
	{
		switch(op)
		{
			case 1:
				scanf("%d ",&num);
			if(i<=98)
			{
				a[i]=num;
				i++;
			}
			else
			printf("error ");
			break;
			case 0:
			if(i>=1)
			{
				i--;
				printf("%d ",a[i]);
				a[i]=0;
				
			}
			else 
			printf("error ");
			break;
			case -1:break;
		}
	}
	
	
	return 0;
}

