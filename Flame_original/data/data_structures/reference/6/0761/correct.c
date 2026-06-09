#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct stack
{
	int data[100];
	int top;
}s;
int main()
{
	struct stack s;
	int n,m;
	s.top=-1;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==1)
		{
			scanf("%d",&m);
			if(s.top==99) printf("error ");
			else 
			{
				s.top++;s.data[s.top]=m;
			}
		}
		if(n==-1) break;
		if(n==0)
		{
			if(s.top==-1) printf("error ");
			else
			{
				printf("%d ",s.data[s.top]);
				s.top--;
			}
		}
	}
	return 0;
}

