#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE	100
int stack[MAXSIZE];
int	Top=-1;
int	isEmpty(int s[]);
int isFull(int s[]);
int pop(int s[]);
void push(int s[],int item);
void Error(char s[]);
int main(){
	int i=0,a,b;

	while(scanf("%d",&a)!=-1){
		if(a==1){
			scanf("%d",&b);
			push(stack,b);
		}
		if(a==0){
			pop(stack);
		}
	}
	return 0;
}
int	isEmpty(int a[])
{
	return Top==-1;
}
int isFull(int a[])
{
	return Top==MAXSIZE-1;
}
void push(int s[],int item)
{
	char a[6]="error ";
	if(isFull(stack))
	printf("%s",a);
	else
	s[++Top]=item;
}
int pop(int s[])
{	char a[6]="error ";
	if(isEmpty(stack)){
		printf("%s",a);		
		}
	else
		printf("%d ",s[Top--]);
}


