#include<stdio.h>
int main()
{
	int s[200];
	int top;
	int n=0;
	while(~scanf("%d",&top))
	{
		if(top==1)
		{
			if(n>99)
		{
			printf("error ");
		}
		else
		{
			scanf("%d ",&s[n]);
			n++;
		}
		}
		if(top==0)
		{
			if(n<1)
		{
			printf("error ");
		}
		else
		{
			--n;
			printf("%d ",s[n]);
		}
		}
		if(top==-1)
		break;
	}
	return 0;
 } 

