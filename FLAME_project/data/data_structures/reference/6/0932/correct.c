#include<stdio.h>
#include<string.h>
int main()
{
	int op,top=-1,a[105];
	while(1)
	{
		scanf("%d", &op);
		if(op==-1)	break;
		else if(op==1)
		{
			top++;
			scanf("%d", &a[top]);
			if(top==100)
			{
				printf("error ");
				top--;
			} 
		}
		else if(op==0)
		{
			if(top==-1)	printf("error ");
			else
				printf("%d ", a[top--]);
		}
	}
	return 0;
} 


