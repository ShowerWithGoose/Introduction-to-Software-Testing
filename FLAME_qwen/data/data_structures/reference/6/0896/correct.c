#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXSIZE 102
struct stack{
	int Top;
	int data[MAXSIZE]; 
};
struct stack s;
int main()
{	
	s.Top = 0;
	int n,num;
	while(~scanf("%d",&n))
	{
		if(n == 1)
		{
			scanf("%d",&num);
			if(s.Top >=100)
			printf("error ");
			else
			{	
				s.data[s.Top] = num;
				s.Top ++;
			}
		}
		else if(n == 0)
		{
			if(s.Top <= 0)
			printf("error ");
			else
			{
				printf("%d ",s.data[s.Top - 1]);
				s.Top--;
			}
		}
		else if(n == -1)
		break;
	}
	return 0;	

}


