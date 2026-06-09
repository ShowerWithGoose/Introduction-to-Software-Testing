#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define M 100
int main()
{
	int a[M],n,top=-1,op;
	while(1)
	{
		scanf("%d",&op);
		if(op==-1)break;
		if(op==0)
		{
			if(top==-1)printf("error ");
			else
			{
				printf("%d ",a[top]);
				top--;
			}
		}
		else
		{
			scanf("%d",&n);
			if(top==M-1)printf("error ");
			else
			{
				a[++top]=n;
			}
		}
	}
	return 0;
}


