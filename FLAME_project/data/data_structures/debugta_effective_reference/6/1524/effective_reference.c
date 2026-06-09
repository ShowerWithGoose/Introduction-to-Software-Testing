#include <stdio.h>

struct Zhan
{
	int a;
	int x;
}date[100];

int top, n;

int main()
{
	while(n != -1)
	{
		scanf("%d", &date[top].a );
		
		if(date[top].a == 1)
		{
		if(top<100)
		scanf("%d", &date[top].x );
		else
		{
		printf("error ");
		top--;
		}
		}
		
		if(date[top].a == 0)
		{
			//printf("n%d ", n);
			if(top > 0)
			{
			top--;
			printf("%d ", date[top].x );
			top--;
			}
			else
			{
			printf("error ");
			top--;
			}
		}
		
		if(date[top].a == -1)
		n=-1;
		
		top++;
	}
	
	return 0;
}

