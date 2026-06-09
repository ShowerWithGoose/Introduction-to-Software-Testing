#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
int stack[100];
int top=-1;
int main()
{
	int n,m;
	scanf("%d",&n);
	while(n!=-1)
	{
		if(n==1)
		{
			scanf("%d",&m);
			if(top==99)
			printf("error ");
			else
			stack[++top]=m;
		}
		if(n==0)
		{
			if(top==-1)
			printf("error ");
			else
			printf("%d ",stack[top--]);
		}
		scanf("%d",&n);
	}
	return 0;
}

