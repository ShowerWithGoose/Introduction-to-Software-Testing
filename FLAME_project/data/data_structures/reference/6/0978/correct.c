#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXSIZE 100 
int STACK[MAXSIZE];
int Top;
void initStack(){//≥ı ºªØ 
	Top=-1;
}
int isEmpty(){
	return Top==-1;
}
int isFull(){
	return Top==MAXSIZE-1;
}
void pop(int s[]){//chuzhan
	if(isEmpty()){
	    printf("error ");
	}
	else {
		printf("%d ",s[Top--]) ;
	}
}
void push (int s[],int item){//jinzhan
	if(isFull())printf("error ");
	else STACK[++Top]=item;
}
int main (){
	int a,item;
	initStack();
	while((scanf("%d",&a)!=-1)){
		if(a==1) {
			scanf("%d",&item);
			push(STACK,item);
		}
		else if(a==0) pop(STACK);
		else if(a==-1) break;
	}
	return 0; 
}

//int comp(const Word* a,const Word* b){
//   return  strcmp((*a).word,(*b).word);
//}

