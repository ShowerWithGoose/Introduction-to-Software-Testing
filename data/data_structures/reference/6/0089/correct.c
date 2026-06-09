#include <stdio.h>
#include <stdlib.h> 
#define MAX 100
int STACK[MAX];
int top;
void iniSTACK()
{
	top=-1;
}
int isEMPTY()
{
	return top==-1;
}
int isFULL()
{
	return top==MAX-1;
}
void Error(char s[])
{
	printf("%s ",s);
	//exit(-1);
}
void push(int a[],int b)
{
	if(isFULL())
	Error("FULL Stack!");
	else
	a[++top]=b;
}
void pop(int a[])
{
	if(isEMPTY())
	Error("error");
	else
	printf("%d ",a[top--]);
}
int main()
{
	int n,ch;
	iniSTACK();
	while(1){
		scanf("%d",&ch);
		if(ch==1){
			scanf("%d",&n);
			push(STACK,n);
		}
		else if(ch==0)
		pop(STACK);
		else break;
	}
	return 0;
 } 

