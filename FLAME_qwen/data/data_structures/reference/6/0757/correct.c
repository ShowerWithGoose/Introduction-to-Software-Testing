#include<stdio.h>
int top=-1;
int n;
int op; 
int s[100];
int main()
{
	while(scanf("%d",&op)!=EOF)
	{
		if(op==-1)
		return 0;
		else if(op==1)
		{
			scanf("%d",&n);
			if(top==99)
			{
				printf("error ");
			}
			else
			s[++top]=n;
		}
		else if(op==0)
		{
			if(top==-1)
			printf("error ");
			else
			printf("%d ",s[top--]);
		}
	}
}



