#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int stack[100];
int top=-1;
int op,n;
int main()
{
	while(1)
	{
	scanf("%d ",&op);
	if(op==-1)
	{
		break;
	}
	else if(op==0 && top!=-1)
	{
		printf("%d ",stack[top-1]);
		top--;
	}
	else if(op==0 && top==-1)
	{
		printf("error ");
	}
	else if(op==1)
	{
		scanf("%d ",&n);
		stack[top]=n;
		top++;
	}
	}
	
return 0;
}


