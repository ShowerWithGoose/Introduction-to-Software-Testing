#include<stdio.h>
#define MAXSIZE 100
int Stack[MAXSIZE];
int Top=-1;
int isFull();
int isEmpyt(); 
void push(int [],int);
void pop(int []);
int main(){
	int order;//1代表入栈 0代表出栈 -1操作结束
	int number; 
	while(scanf("%d",&order)!=EOF){
		if(order==1){
			scanf("%d",&number);
			push(Stack,number);
		}
		else if(order==0){
			pop(Stack);
		}
		else if(order==-1)
		    break;
	}
	
	return 0;
}


int isFull(){
	return Top==MAXSIZE-1;//1代表已满 0代表未满 
}
int isEmpyt(){
	return Top==-1;//1代表已空 0代表未空 
}
void push(int Stack[],int x){
	if(isFull()){
		printf("error ");
	}
	else{
		Top++;
		Stack[Top]=x;
	}
}
void pop(int Stack[]){
	if(isEmpyt()){
		printf("error ");
	}
	else{
		printf("%d ",Stack[Top]);
		Top--;
	}
}


