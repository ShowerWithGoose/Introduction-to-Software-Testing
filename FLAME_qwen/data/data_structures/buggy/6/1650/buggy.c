#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
char stack[MAX];
int top=-1;
int main()
{
	int a,b;
	scanf("%d",&a);
	while(a!=-1)
	{
		if(a==1)
		{
			scanf("%d",&b);
			if(top==100)
			printf("error ");
			else
			{
				stack[++top]=b;
			}
		}
		else if(a==0)
		{
			if(top==-1)
			printf("error ");
			else
			{
				printf("%d ",stack[top]);
				top--;	
			}
		}
	scanf("%d",&a);	
	}	
	return 0;
}

