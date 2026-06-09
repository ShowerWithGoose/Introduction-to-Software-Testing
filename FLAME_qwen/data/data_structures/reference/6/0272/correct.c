#include <stdio.h>
#define max 100
int main()
{
	int stack[max];
	int top=-1,a,num;
	do{
		scanf("%d",&a);
	    if(a==1)
	    {
	    	scanf("%d",&num);
	    	if(top==99)
	    	{
	    		printf("error ");
			}
			else
			{
				top++;
				stack[top]=num;
			}
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
	}while(a!=-1);
	return 0;
}

