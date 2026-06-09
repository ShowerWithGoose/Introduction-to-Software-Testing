#include<stdio.h>
#define M 100

int stack[100];
int top=-1;

int EMPTYS(int top)
{
	return top==-1;
}

int FULLS(int top)
{
	return top==M-1;
}

int main()
{
	int m,n;
	scanf("%d",&m);
	int i;
	for(i=0;m!=-1;i++)
	{
		if(m)
		{
			scanf("%d",&n);
			if(!FULLS(top))
				stack[++top]=n;
			else
				printf("error ");
		}		
		else if(!m)
		{
			if(EMPTYS(top))
				printf("error ");
			else
			{
				printf("%d ",stack[top--]);
			}
		}
		scanf("%d",&m);
	}
	return 0;
}

