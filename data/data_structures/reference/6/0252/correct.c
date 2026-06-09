#include<stdio.h>
#define MAXLEN 100
int stack[MAXLEN];
int main()
{
	int a;
	int top=-1;
	scanf("%d",&a);
	while(a!=-1)
	{
		if(a==1)
		{
			scanf("%d",&a);
			stack[++top]=a;
		}
		else if(a==0)
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
		scanf("%d",&a);
	}
} 



