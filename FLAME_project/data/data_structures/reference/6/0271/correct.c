#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int s[100];
int top=-1;
int main()
{
	int op;
	int num;
	while(~scanf("%d",&op))
	{
		if(op==1)
		{
			scanf("%d",&num);
			if(top==99)
				printf("error ");
			else
				s[++top]=num;
		}
		else if(op==0)
		{
			if(top==-1)
				printf("error ");
			else
				printf("%d ",s[top--]);
		}
		else return 0;
	}
}

