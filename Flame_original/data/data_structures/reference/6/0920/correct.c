#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
int STACK[MAXSIZE];
int Top;//∂®“Â’ª
void initStack(){
	Top=-1;
}
int isEmpty(){
	return (Top==-1);
} 
int isFull(){
	return (Top==MAXSIZE-1);
}
void Error(char c[]){
	printf("%s ",c);
}
void push(int s[],int item){
	if(isFull()) Error("error");//Error("Full Stack!");
	else s[++Top]=item;
}
void pop(int s[]){
	if(isEmpty()) Error("error");//Error("Empty Stack!");else return s[Top--];
	else printf("%d ",s[Top--]);
}
int main(){
	int op,s;
	initStack();
	while(scanf("%d",&op)){
		if(op==1){
			scanf("%d",&s);
			if(s!=1&&s!=0&&s!=-1) push(STACK,s);
		}
		else if(op==0) pop(STACK);
		else if(op==-1) return 0;
	}
	return 0;
}

