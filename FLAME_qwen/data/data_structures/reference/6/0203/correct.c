#include <stdio.h>
int stack[100],top=-1;
int isempty(){
return (top==-1);}//Õ»¿Õ·µ»Ø1
int isfull(){
return (top==99);} 
void push(int x)
{
	if(isfull())
	printf("error ");
	else
	stack[++top]=x;
}
void pop()
{
	if(isempty())
	printf("error ");
	else
	printf("%d ",stack[top--]);
}
int main()
{
	int order,tmp;
	char ch;
	do
	{
		scanf("%d%c",&order,&ch);
		if(order==1)
		{
		scanf("%d ",&tmp);
		push(tmp);
		}
		else if(order==0)
		pop();
	}while(ch!='\n');
	
	return 0;
}

