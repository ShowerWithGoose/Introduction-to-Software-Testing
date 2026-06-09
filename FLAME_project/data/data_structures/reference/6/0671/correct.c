#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int stack[105];
char output[300];
int main()
{
	int op, top = -1;
	while(scanf("%d", &op) != EOF)
	{
		switch(op)
		{
			case 1:
				top++;
				scanf("%d", &stack[top]);
				break;
			case 0:
				if(top != -1)
				{
					printf("%d ", stack[top--]);
				}
				else 
				{
					printf("error ");
				}
				break;
			case -1:
				break;
		}
		if(op == -1)
			break;
	}
	return 0;
}

