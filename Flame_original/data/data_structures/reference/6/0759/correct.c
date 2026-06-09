#include<stdio.h>
int stack[100];
int top=-1;
void push(int s[],int e);
int pop(int s[]);
int isempty();
int isfull();
int main()
{
	int a,b;
	scanf("%d",&a);
	while(a!=-1){
		if(a){
			scanf("%d",&b);
			push(stack,b);
		}
		else{
			b=pop(stack);
			if(b!=-1)
				printf("%d ",b);
		}
		scanf("%d",&a);
	}
	return 0;
}
void push(int s[],int e)
{
	if(isfull()){
		printf("error ");
		return;
	}
	top++;
	s[top]=e;
}
int pop(int s[])
{
	if(isempty()){
		printf("error ");
		return -1;
	}
	top--;
	return s[top+1];
}
int isempty()
{
	return top==-1;
}
int isfull()
{
	return top==99;
}

