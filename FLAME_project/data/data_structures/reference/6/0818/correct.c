#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h> 

int main(void)
{
	int stack[105]={0};
	int top=-1,temp,order;
	while((scanf("%d",&order))!=EOF)
	{
		if(order==0)
		{
				if(top>=0)
					printf("%d ",stack[top--]);
				else
					printf("error ");
				continue;			
		}
		scanf("%d",&temp);
		switch(order)
		{
			case -1:return 0;
			case 1:
				if(top<99)
					stack[++top]=temp;
				else
					printf("error ");
				break;
		}
	}
} 

