#include<stdio.h>
int s[101],top,op;

int main()
{
	while(~scanf("%d",&op))
	{
		int x;
		if(op==-1)break;
		else if(op)
		{
			scanf("%d",&x);
			if(top==100)printf("error ");
			else s[++top]=x;
		}
		else
		{
			if(!top)printf("error ");
			else printf("%d ",s[top--]);
		}
	}
}

