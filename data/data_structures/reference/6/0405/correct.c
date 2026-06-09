#include<stdio.h>
#include<string.h>
#define MAXSIZE 100
int stack[MAXSIZE];
int top=-1;
int main()
{
	int op;
	while(1)
	{
		scanf("%d",&op);
			if(op==1)
			{
				top++;
				if(top==101)
				{
					printf("error ");
					continue;
				}
				scanf("%d",&stack[top]);
			}else if(op==0)
			{
				if(top==-1)
				{
					printf("error ");
					continue;
				}
				printf("%d ",stack[top]);
				top--;
			}else if(op==-1)
			{
				break;
			}
	}
	return 0;
}

