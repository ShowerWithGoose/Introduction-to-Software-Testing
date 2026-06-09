#include<stdio.h>
int main()
{
	int Stack[100]={0};
	int top=0;
	int a=0;
	while(a+1)
	{
		scanf("%d",&a);
		if(a==1)
		{
			if(top!=99)
			{
			scanf("%d",&Stack[top]);
			top++;
		    }
		    else if(top==99)
		    {
		    	printf("error ");
			}
		}
		else if(a==0)
		{
			if(top!=0)
			{
				printf("%d ",Stack[top-1]);
				Stack[top]=0;
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

