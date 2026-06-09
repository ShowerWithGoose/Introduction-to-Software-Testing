#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
struct stack{
	int top;
	int n[1020];
};
struct stack s;
int main()
{
 	int i,n,a;	
	s.top=0;
	while(~scanf("%d",&n))
	{
		if(n==-1)
		{
			break;
		}
		else if(n==1)
		{
			scanf("%d",&a);
			if(s.top>=100)
			{
				printf("error ");
			}
			else
			{
				s.n[s.top]=a;
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
				printf("%d ",s.n[s.top-1]);
				s.top--;
			}
		}
	
	}
	return 0;
}


