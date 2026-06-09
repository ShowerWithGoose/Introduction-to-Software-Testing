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
 	int i,a,b;	
	s.top=0;
	while(~scanf("%d",&a))
	{
		if(a==-1)
		{
			break;
		}
		else if(a==1)
		{
			scanf("%d",&b);
			if(s.top>=100)
			{
				printf("error ");
			}
			else
			{
				s.n[s.top]=b;
				s.top++;
			}
		}
		else if(a==0)
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


