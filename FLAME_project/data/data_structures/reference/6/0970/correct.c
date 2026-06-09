#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>

int isempty(int);
int isfull(int);
int top=-1;
int stack[100];
int main()
{
	int op,num;
	while(1)
	{
		scanf("%d",&op);
		if(op==-1)//end
			break;
		else if(op==0)//chu
		{
			if(isempty(top))
				printf("error ");
			else
				printf("%d ",stack[top--]);
		}
		else if(op==1)//ru
		{
			scanf("%d",&num);
			if(isfull(top))
				printf("error ");
			else
				stack[++top]=num;
		}
	}
	return 0;
}
int isempty(int flag)
{
	return flag==-1;
}
int isfull(int flag)
{
	return flag==99;
}

