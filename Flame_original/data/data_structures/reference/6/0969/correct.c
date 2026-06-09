#include<stdio.h>
int stack[105];
int main()
{
	int n,number,top=-1;
	while(scanf("%d",&n)!=-1)
	{
		if(n==1)
		{
			scanf("%d",&number);
			if(top>=100)
			    printf("error ");//´íÎó
			else
			{
				top++;
			    stack[top]=number; 
			}
			continue;
		}
		if(n==0)
		{
			if(top<=-1)
			    printf("error ");
			else
			{
			    printf("%d ",stack[top]);
			    top--;
			}
			continue;
		}
	}
	return 0;
}

