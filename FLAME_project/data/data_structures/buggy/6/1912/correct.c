#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int a[105];
#define ARRAY_LEN(x) (sizeof(x)/sizeof(x[0]))
int main()
{
	int num,num1;
	int top=-1;
	while(1)
	{
		scanf("%d",&num);
		if(num==-1)
			break;
		else if(num==1)//»Î’ª
		{
			scanf("%d",&num1);
			if(top==100)
			{
				printf("error ");
			}
			else
			{
				top++;
				a[top]=num1;	
			}
	
		}
		else//≥ˆ’ª
		{
			if(top==-1)
			{
				printf("error ");
			}
			else
			{	
				printf("%d ",a[top]);
				top--;
			}
						
		}
	}
	
	return 0;
}

