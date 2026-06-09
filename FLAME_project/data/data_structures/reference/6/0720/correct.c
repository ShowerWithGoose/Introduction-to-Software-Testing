#include<stdio.h>
#define MAX 200
int stack[MAX];
int top;
void pop(){printf("%d ",stack[top--]);}
void insert(int item){stack[++top]=item;}
int main()
{
	int op,m;
	while(scanf("%d",&op))
	{
		if(op==-1)return 0;
		else if(op==1)
		{
			scanf("%d",&m);
			if(top==100)printf("error ");
			else insert(m);
		}
		else if(op==0)
		{
			if(top==0)printf("error ");
			else pop();
		}
	}
	return 0;
} 

