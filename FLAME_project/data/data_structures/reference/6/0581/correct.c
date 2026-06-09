#include <stdio.h>
#include <stdlib.h>


int main()
{
	int op,num;
	int nums[100]={0};
	int i=0;
	while(scanf("%d",&op))
	{
		if(op==-1) break;
		else if(op==1)
		{
			scanf("%d",&num);
			if(i<100)
			{
				nums[i++]=num;
			}
			else
			{
				printf("error ");
			}
		}
		else if(op==0)
		{
			if(i>0)
			{
				printf("%d ",nums[--i]);
			}
			else
			{
				printf("error ");
			}
		}
	}
	return 0;
 } 

