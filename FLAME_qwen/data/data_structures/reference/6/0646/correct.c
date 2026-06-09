#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define maxn 100

int stack[maxn];

int push(int num,int* stack,int *top)
{
	if(*top==maxn)
	return 0;
	stack[(*top)++]=num;
	return 1;
}

int pop(int* stack,int*top)
{
	if(*top==0)
	{
		return 0;
	}else{
		return stack[--(*top)];
	}
}
int main()
{
	int op,num;
	int kase=0;
	int top=0;int ans;
	while(scanf("%d",&op)&&op!=-1)
	{
		switch(op)
		{
			case 1:
				scanf("%d",&num);
				if(push(num,stack,&top)==0)
				{
					if(kase++)printf(" ");
					printf("error");
				}
				break;
			case 0:
				ans=pop(stack,&top);
				if(ans==0)
				{
					if(kase++)printf(" ");
					printf("error");
				}else{
					if(kase++)printf(" ");
					printf("%d",ans);
				}
		}
	}
	return 0;
 } 

