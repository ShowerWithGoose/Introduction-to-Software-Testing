#include<stdio.h>
#include<string.h>

int top=-1;
int stack[105];

int main()
{
	int a,b,x;
	while((scanf("%d",&a)!=EOF)) 
	{
		if(a==1)
		{
			scanf("%d",&b);
			if(top>99) 
				printf("error ");
			else 
				stack[++top]=b;
		}
		else if(a==0)
		{
			if(top==-1) 
				printf("error ");
			else
			{
				x=stack[top--];
				printf("%d ",x);
			}
		}
		else if(a==-1) 
			break;
	}
	
	return 0;
} 

