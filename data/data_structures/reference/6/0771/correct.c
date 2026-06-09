#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int top2=-1;
int top1=-1;
int stack[100];
int isempty();
int isfull();
void push(int s[],int item);
void pop(int s[]);
int main()
{
	int n;
	while(100)
	{
		int key;
		int i,j,k;
		char str[100];
		scanf("%d",&key);
		int a;
		if(key==1)
		{
			scanf("%d",&a);
			push(stack,a);
		}
	 if(key==0)
		{
			pop(stack);
		}
		else if(key==-1)break;
		else if(key!=-1&&key!=0&&key!=1)continue;
	}
	return 0;
 } 
 int isempty()
 {
 	return top1==-1;
 }
 int isfull()
 {
 	return top1==100-1;
 }
 void push(int s[],int item)
 {
 	if(isfull())printf("error ");
 	else s[++top1]=item;
 }
 void pop(int s[])
 {
 	if(isempty())printf("error ");
 	else printf("%d ",s[top1--]);
 }




