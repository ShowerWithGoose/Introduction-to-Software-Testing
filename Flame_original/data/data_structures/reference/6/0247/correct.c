#include<stdio.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
int main()
{
	int s[100];
	int top=-1;
	int n=78,m;
	while(n!=-1)
	{
		scanf("%d",&n);
		if(n==0)
		{
			if(top==-1)
			{
				printf("error ");
			}
			else
			{
				printf("%d ",s[top--]);
			}
		}
		if(n==1)
		{
			scanf("%d",&m);
			if(top==99)
			{
				printf("error ");
			}
			else
			{
				top++;
				s[top]=m;
			}
		}
	}
	return 0;
}
