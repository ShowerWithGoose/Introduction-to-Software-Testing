#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
struct stack{
	int top;
	int data[1020];
};
struct stack s;

int i,n,m;
int main()
{	
	s.top=0;
	while(~scanf("%d",&n))
	{
		if(n==1)
		{
			scanf("%d",&m);
			if(s.top>=100)
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
			if(s.top<1)
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


