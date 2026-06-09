#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAX 500
int top=0;
int s[MAX];
int main()
{
	int m,n;
	while(scanf("%d",&m)!='\0')
	{
		if(m==-1)
			break;
		else if(m==1)
		{
			if(top>=100)
			{
				printf("error ");
			}
			else if(top<100)
			{
				scanf("%d",&n);
				s[top]=n;
				top++;
			}
		}
		else if(m==0)
		{
			if(top<=0)
			{
				printf("error ");
			}
			else
			{
				printf("%d ",s[top-1]);
				top--;
			}
		}
	}
	return 0;
}

