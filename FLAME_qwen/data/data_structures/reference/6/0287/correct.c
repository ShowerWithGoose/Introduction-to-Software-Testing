#include<stdio.h>
int stack[105];
int main()
{
	int i=0,j=0,k=0,op,item;
	while(1)
	{
		scanf("%d",&op);
		if(op==1)
		{
			i++;
			if(i<=100)
			{
				scanf("%d",&item);
				stack[i]=item;
			}
			else
			{
				printf("error ");
				i--;
			}
		}
		else if(op==0)
		{
			if(i>=1&&i<=100)
			{
				printf("%d ",stack[i]);
				i--;
			}
			else
			{
				printf("error ");
			}
		}
		else
		{
			break;
		}
	}
	return 0;
}

