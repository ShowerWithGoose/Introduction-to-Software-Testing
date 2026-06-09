#include<stdio.h> 
#include<math.h>
#include<stdlib.h> 
#include<string.h> 
#include<stdbool.h> 
#include<ctype.h>
#define MAXSIZE 100;
int stack[101];
int top=-1;
int isFull(){
	return top==MAXSIZE-1;
}
void push(int item){
	if(isFull()){
		printf("error ");
	}else{
		stack[++top]=item;
	}
}
void pop(){
	if(top==-1){
		printf("error ");
	}else{
		printf("%d ",stack[top--]);
	}
}
int main(){ 
int op,data;
int i;
for(i=0;;i++){
	scanf("%d",&op);
	if(op==-1) break;
	if(op==1){
		scanf("%d",&data);
		push(data);
	}
	if(op==0){
		pop();
	}

    
	
	
}







return 0;
}

