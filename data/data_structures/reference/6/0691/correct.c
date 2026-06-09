#include<stdio.h>
int stack[1000];
int top=-1;
int main()
{
	int i,num;
	while(scanf("%d",&i)&&i!=-1)
	{
		if(i==1)
		{
			scanf("%d",&num);
			stack[++top]=num;
		}
		if(i==0)
		{
			if(top==-1) printf("error ");
			else
			{
				printf("%d ",stack[top]);
				top--;
			}
		}
	}


	return 0;
}


