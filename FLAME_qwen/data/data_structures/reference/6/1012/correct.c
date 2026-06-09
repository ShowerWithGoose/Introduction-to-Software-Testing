#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define MAXLINE 1024
int main()
{
	int stack[100];
	int i=0;
	int ctrl,num;
	scanf("%d",&ctrl);
	while(ctrl!=-1)
	{
		if(ctrl==1)
		{
			if(i<=99)
			{
				scanf("%d",&num);
				stack[i]=num;
				i++;
			}
			else
			{
				printf("error");
			}
		}
		else if(ctrl==0)
		{
			if(i>0)
			{
				i--;
				printf("%d ",stack[i]);
				stack[i]=0;
			}
			else printf("error ");
		}
		scanf("%d",&ctrl);
	}
	return 0;
}

