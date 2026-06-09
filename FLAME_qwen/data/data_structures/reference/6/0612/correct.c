#include<stdio.h>
int main()
{
	int stack[1000];
	int a,b;
	int top=0;
	while(scanf("%d",&a)!=EOF)
	{
		if(a==1)
		{
			if(top<100)
			{
				top++;
				scanf("%d",&b);
				stack[top]=b;
			}
			else
			{
				printf("error ");
			}
			
		}
		if(a==0)
		{
			if(top>=1)
			{
			    printf("%d ",stack[top]);
			    top--;
			}
			else
			{
				printf("error ");
			}
			
		}
	}
	return 0;
} 

