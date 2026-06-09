#include<stdio.h>
int s[101];
int top;
int main()
{
	int op,x;
	while(scanf(" %d",&op),op!=-1)
	{
		switch(op)
		{
			case 1:
				scanf("%d ",&x);
				if(top==99)
				{
					printf("error ");
					break;
				}
				s[++top]=x;
				break;
			case 0:
				if(top==0)
				{
					printf("error ");
					break;
				}
				printf("%d ",s[top--]);
				break;
			default:
				break; 
		}
	}
	return 0;
}

