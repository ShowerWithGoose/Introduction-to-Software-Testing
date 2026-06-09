#include<stdio.h>
#define MAX 100
int Stack[MAX];
int top=-1; 
void push(int item)
{
	if(top==MAX-1) printf("error ");
	else Stack[++top]=item;
}
void pop()
{
	if(top==-1) printf("error ");
	else
	{
		printf("%d ",Stack[top--]);
	}
}
int main()
{
	int op,item;
	while(scanf("%d",&op)!=EOF)
	{
		if(op==-1) return 0;
		
		if(op==1) {
			scanf("%d",&item);
			push(item);
		}
		else if(op==0)  pop();
	}
	return 0;
}

