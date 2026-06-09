#include <stdio.h>
int main()
{
	int A[102]={0};
	int i=1;
	int op;
	int num;
	while(1)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf(" ");
			scanf("%d ",&num);
			if(i<=100)
			{
				A[i]=num;
				i++;
			}
			else
			{
				printf("error ");
			}
		}
		else if(op==0)
		{
			scanf(" ");
			if(i>1)
			{
				printf("%d ",A[i-1]);
				i--;
			}
			else
			{
				printf("error ");
			}
		}
		else if(op==-1)
		break;
	}
	return 0;
}

