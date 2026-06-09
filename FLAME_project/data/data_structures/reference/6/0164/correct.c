#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
struct stack{
	int top;
	int data[1020];
};
struct stack zhan;

int i,n,m;
int main()
{	
	zhan.top=0;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==1)
		{
			scanf("%d",&m);
			if(zhan.top > 101)
			{
				printf("error ");
			}
			else
			{
				zhan.data[zhan.top] = m;
				zhan.top++;
			}
		}
		else if(n==0)
		{
			if(zhan.top <= 0)
			{
				printf("error ");
			}
			else
			{
				printf("%d ",zhan.data[zhan.top-1]);
				zhan.top--;
			}
		}
		else if(n==-1)
		{
			break;
		}
	}
	
	return 0;
}


