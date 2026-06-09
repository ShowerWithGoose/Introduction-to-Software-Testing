#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
	int stack[100];
	int top=-1;
	int func,value;
	while(scanf("%d",&func)!=-1)
	{
		if(func==1)
		{
			scanf("%d",&value);
			if(top==100)
			{
				printf("error ");
			}
			else
			{
				stack[++top]=value;
			}
		}
		else if(func==0)
		{
			if(top==-1)
			{
				printf("error ");
			}
			else
			{
				printf("%d ",stack[top]);
				top--;
			}
		}
	}
	return 0;
}

