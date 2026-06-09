#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int stack[100];
int top=-1;
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==1)
		{
			int num;
			scanf("%d",&num);
			if(top==99)
			{
				printf("error ");
			}
			else
			{
				stack[++top]=num;
			}
		}
		if(n==0)
		{
			if(top==-1)
			{
				printf("error ");
			}
			else
			{
				printf("%d ",stack[top--]);
			}
		}
		if(n==-1)
		{
			break;
		}
	}
	return 0;
}

