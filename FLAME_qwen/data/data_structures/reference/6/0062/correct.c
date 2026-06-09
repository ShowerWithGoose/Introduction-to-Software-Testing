#include<stdio.h>
int top=-1;
int x[105];
int main()
{
	int a,data;
	while(1)
	{
		scanf("%d",&a);
		if(a==1)//½øÕ» 
		{
			if(top<99)
			{
				scanf("%d",&data);
				x[++top]=data;
			}
			else
			{
				printf("error ");
			}

			
		}
		else if(a==0)//³öÕ» 
		{
			if(top>=0)
			{
				printf("%d ",x[top--]);
			}
			else
			{
				printf("error "); 
			}
			
		}
		else
		break;
	}
	return 0;
}


