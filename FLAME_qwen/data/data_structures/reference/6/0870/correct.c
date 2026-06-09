#include<stdio.h>
#include<stdio.h>
int stack[100];
int trush;
char str[6]="error";
int top=-1;
int isempty();
int isfull();
void push();
void out();
int main()
{
	int option;
	while(~scanf("%d",&option))
	{
	if(option==1)
		push();
	if(option==0)
		out();
	if(option==-1)
		return 0;
	}	
}
int isempty()
{
	if(top==-1)return 1;
	else return 0;
}
int isfull()
{
	if(top==99)return 1;
	else return 0;
}
void push()
{
	if(!isfull())
		scanf("%d",&stack[++top]);
	else
	{
		scanf("%d",&trush);
		printf("%s ",str);
	}	
}
void out()
{
	if(!isempty())
		printf("%d ",stack[top--]);
	else
		printf("%s ",str);
}


