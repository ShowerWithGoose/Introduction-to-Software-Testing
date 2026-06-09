#include<stdio.h>
int main()
{
	int stack[100];
	int top=0;
	int n;
	int item;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==1)
		{
			if(top!=99)
			{
			scanf("%d",&item);
			stack[top++]=item;
		    }
		    else
		    printf("error ");
		}
		if(n==0)
		{
			if(top-1>=0)
			{
			printf("%d ",stack[top-1]);
			stack[top-1]=0;
			top--;
		    }
			else 
			printf("error ");
		}
		if(n==-1)
		break;
	}
}

