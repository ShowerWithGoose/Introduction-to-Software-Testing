#include <stdio.h>

int main()
{
	int op,x,a[105]={0},top=0;
	while(scanf("%d",&op)!=EOF)
	{
		if(op==1)
		{
			scanf("%d",&x);
			if(top==100)
				printf("error ");
			else
			{
				a[top]=x;
				top++; 
			}
		}
		else if(op==0)
		{
			if(top==0)
				printf("error ");
			else
			{
				top--;
				printf("%d ",a[top]);
				a[top]=0;
			 } 
		}
		else
			break;
	} 
	return 0;
}

