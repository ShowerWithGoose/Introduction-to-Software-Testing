#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int sta[110];
int main()
{
	int top=0,op,x;
	while(scanf("%d",&op)!=EOF)
	{
		if(op==-1) break;
		if(op==1)
		{
			scanf("%d",&x);
			if(top==100){printf("error ");continue;}
			sta[++top]=x;
		}
		else
		{
			if(top==0){printf("error ");continue;}
			printf("%d ",sta[top]);top--;
		}
	}
	return 0;
}

