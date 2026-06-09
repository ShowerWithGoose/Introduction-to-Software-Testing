#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <tgmath.h>
#include <complex.h>
#include <assert.h>
#include <stdarg.h>
#include <stdbool.h>

int stack[100]; 
int flag=-1;

bool isFull()
{
	return flag==99;
}

bool isEmpty()
{
	return flag==-1;
}


int main (void)
{
	int op;
	scanf("%d",&op);
	while(op!=-1)
	{
		if(op==1)
		{
			if(isFull())
				printf("error ");
			else
			{
				int element;
				scanf("%d",&element);
				flag++;
				stack[flag]=element;
			}
		}	
		else if(op==0)
		{
			if(isEmpty())
				printf("error ");
			else
			{
				printf("%d ",stack[flag]);
				flag--;
			}
		}
		scanf("%d",&op);	
	}
    return 0;
}


