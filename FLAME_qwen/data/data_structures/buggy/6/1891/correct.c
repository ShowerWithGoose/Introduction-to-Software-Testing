# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>

typedef struct Stack
{
	int top;
	int data[100];
}stack;
int main()
{
	int x;
	stack s;
	s.top=0;
	while(1)
	{
		scanf("%d",&x);
		if(x==-1) break;
		if(x==1)
		{
			if(s.top==100) printf("error ");
			else
			{
				scanf("%d",&s.data[s.top]);
				s.top+=1;
			}
		}
		else if(x==0)
		{
			if(s.top==0) printf("error ");
			else
			{	
				printf("%d ",s.data[s.top-1]);
				s.top-=1;
			}
		}
	}
	return 0;
}
