#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int top=-1;
int arr[100];
int isempty()
{
	return top==-1;
 } 
int isfull()
 {
 	return top==99;
 }
void push(int s[],int y){
 	if(isfull()==1)
 	printf("error ");
 	else
 	s[++top]=y;
 }
void pop(int s[]){
 	if(isempty()==1)
 	printf("error ");
 	else
 	printf("%d ",s[top--]);
 	
 }

 int main()
{
  int n=0;
  int num=0;
 while(1)
 {	
 	scanf("%d",&n);
 	if(n==1){
 	scanf("%d",&num);
	 push(arr,num);
	 }
 	else if(n==0)
 	pop(arr);
 	else if(n==-1)
 	break;
 }
 return 0;
}

