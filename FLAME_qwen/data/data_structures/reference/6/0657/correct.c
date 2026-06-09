#include<stdio.h>
#define M 100
int stack[M]={0};
int main()
{
	int top=0,op;
	while(scanf("%d",&op)!=EOF)
	{
		if(op==-1)
		{
			break;
		}
		else if(0==op)
		{
			if(0==top) printf("error ");
			else
			{
				printf("%d ",stack[top-1]);
				top--; 
			} 
		}
		else if(1==op)
		{
			if(top==M-1) printf("error ");
			else
			{
				scanf("%d",&stack[top++]);
			}
		}
	}
	return 0;
}

