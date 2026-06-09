#include<stdio.h>

int main()
{
	int zhilin;
	int top=-1;
	int cun[100];
	
	scanf("%d",&zhilin);
	
	while(zhilin!=-1)
	{
		if(zhilin==1) scanf("%d",&cun[++top]);
		else 
		{
			if(top>=0)printf("%d ",cun[top--]);
			else printf("error ");
		}
		
		scanf("%d",&zhilin);
	}
	
	return 0;
}

