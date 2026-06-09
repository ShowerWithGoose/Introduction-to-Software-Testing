#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int a[100],top=-1,opr;

int main()
{
	for(;;)
	{
		scanf("%d",&opr);
		if(opr==1)
		{
			if(top>99)
			{
				printf("error ");
			}
			else
			{
				top++;
				scanf("%d ",&a[top]);
			}
		}
		else if(opr==0)
		{
			if(top<0)
			{
			    printf("error ");
			}
			else
			{
				printf("%d ",a[top]);
				top--;
			}
		}
		else if(opr==-1) 
		{
			break;
		}
	}
}

