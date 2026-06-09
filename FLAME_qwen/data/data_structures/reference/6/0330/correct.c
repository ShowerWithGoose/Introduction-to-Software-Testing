#include<stdio.h>
#include<string.h>
int main()
{
	
	int a[105];
	int top=1;
	int b;
	scanf("%d",&b);
	while(b!=-1)
	{
		if(b==1)
		{
			if(top!=101)
			scanf("%d",&a[top++]);
			else
			printf("error ");
		}
		else if(b==0)
		{
			if(top!=1)
			{
			printf("%d ",a[top-1]);
			top--;
			}
			else
			printf("error ");
		}
		scanf("%d",&b);
	}
	
	
	
	
}

