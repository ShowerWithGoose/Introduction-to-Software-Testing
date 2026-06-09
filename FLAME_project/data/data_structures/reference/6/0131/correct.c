#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define maxmize 100
int stack_1[maxmize];
int top=-1;
int	isEmpty( )
{
return top==-1;
}
int isFull(	)
{
return top==maxmize-1;
}
void push(int s[],int item);
void pop(int s[]);
//void Error(char s[]);
int main(){
	int n,list;
	while(1){
	//initStack();
	scanf("%d",&n);
	if(n==-1)
	break;
	else if(n==1){
		int item;
		scanf("%d",&item);
		push(stack_1,item);
	}
	else if(n==0){
		pop(stack_1);
	}
	int i=0;
	for(i=0;i<n;i++){
		list=i;
	}
}	
	
	
	
	
	return 0;
}
void push(int s[],int item){
	if(isFull()){
	printf("error ");
}
	else
	s[++top]=item;
	
}
void pop(int s[]){
	if(isEmpty()){
	printf("error ");
}
    else{
    printf("%d ",s[top--]);
    //return s[Top--];
	}
}



