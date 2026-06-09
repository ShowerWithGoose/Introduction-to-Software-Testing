#include<stdio.h>
#define M 100
int stack[M];
int top;
int main()
{
	top=-1;
	int flag=2;
	scanf("%d",&flag);
	int in;
	while(flag!=-1)
	{
		if(flag==1)
		{
		scanf("%d",&in);
		if(top==99){
		printf("error ");scanf("%d",&flag); continue;}
		top++;
		
		stack[top]=in;}
		if(flag==0)
		{
			if(top==-1)
			{
				printf("error ");
				scanf("%d",&flag);
				continue;
			}
			printf("%d ",stack[top]);
			top--;
		}
		scanf("%d",&flag);
	}
	return 0;
}


