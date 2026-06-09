#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 100
int num[MAX];
int main()
{
	int order,n,top=-1;
	while(scanf("%d",&order))
	{
		if(order==-1)
		{
			break;
		}
		else if(order==1)//»Î’ª
		{
			scanf("%d",&n);
			if(top==99)
			{
				printf("error ");
			}
			else
			{
				num[++top]=n;
			}
		} 
		else if(order==0)//≥ˆ’ª
		{
			if(top==-1)
			{
				printf("error ");
			}
			else
			{
				printf("%d ",num[top--]);
			}
		} 
	}
	return 0;
}

