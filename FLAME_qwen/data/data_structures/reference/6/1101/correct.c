#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
struct stack{
	int top;
	int data[200];
};
struct stack s;
void initstack()
{
	s.top==0;
}
int isempty()
{
	return s.top==0;
}
int isfull()
{
	return s.top==100;
}
int main()
{
	int n,m;
	initstack();
	while((scanf("%d",&n))!=EOF)
	{
		if(n==1)
		{
			scanf("%d",&m);
			if(isfull())
			{
				printf("error ");
			}
			else
			{
				s.data[s.top]=m;
				s.top++;
			}
		}
		else if(n==0)
		{
			if(isempty())
			{
				printf("error ");
			}
			else
			{
				printf("%d ",s.data[s.top-1]);
				s.top--;
			}
		}
		else if(n==-1)
		{
			break;
		}
	}
	return 0;
}


