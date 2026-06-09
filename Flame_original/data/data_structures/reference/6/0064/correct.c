#include<stdio.h>

int main()
{
	int stack[100];
	int movement,intnum=0,top=-1;
	while(1)
	{
		scanf("%d",&movement);
		if(movement == -1)
		{
			break;
		}
		if(movement == 0)
		{
			if(top==-1)
			{
				printf("error ");
				continue;
			}
			printf("%d ",stack[top--]);
		}
		else
		{
			scanf("%d",&intnum);
			if(top==99)
			{
				printf("error ");
				continue;
			}
			stack[++top] = intnum;
		}
	}
	
	return 0;
}


