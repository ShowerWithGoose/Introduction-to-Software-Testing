#include<stdio.h>
#define MAXSIZE 100
int STACK[MAXSIZE];
int Top;
//栈操作指令
void initStack()
{
	Top=-1;
}
int isEmpty()
{
	return Top==-1;
}
int isFull()
{
	return Top==MAXSIZE-1;
}
void Error()
{
	printf("error ");
}
int push(int s[],int item)
{
	if(isFull()){
		Error();
		return 1;
	}
	else{
		s[++Top]=item;
		return 0;
	}
}
int pop(int s[])
{
	if(isEmpty()){
		Error();
		return -1;
	}
	else return s[Top--];
}

int main()
{
	initStack();
	int n,m,tmp;
	while(scanf("%d",&n)!=-1){
		if(n==1){
			scanf("%d",&m);
			tmp=push(STACK,m);
			if(tmp==1) continue;
		}
		if(n==0){
			tmp=pop(STACK);
			if(tmp==-1) continue;
			else printf("%d ",tmp);
		}
	}
	return 0;
}
