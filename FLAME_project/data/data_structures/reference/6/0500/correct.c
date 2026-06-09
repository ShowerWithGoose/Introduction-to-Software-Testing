#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define M 100
struct stack{
	int s[1050];
	int top;
};
int main()
{
	int n;
	int flag;
	struct stack a;
	a.top=0;
	while(~scanf("%d",&flag))
	{
		if(flag==1)
		{
			scanf("%d",&n);
			if(a.top>=100)
				printf("error ");
			else{
				a.s[a.top]=n;
				a.top++;
			}
		}
		else if(flag==0)
		{
			if(a.top<=0)
				printf("error ");
			else{
				printf("%d ",a.s[a.top-1]);
				a.top--;
			}
		}
		else if(flag==-1)
		{
			break;
		}
	}
	return 0;

}



