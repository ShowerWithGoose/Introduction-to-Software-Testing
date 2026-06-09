#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define maximum 100 
int A[maximum];
int Top;
void initStack(){//≥ı ºªØ 
	Top=-1;
}
int isEmpty(){
	return Top==-1;
}
int isFull(){
	return Top==maximum-1;
}
void pop(int s[]){//chuzhan
	if(isEmpty()){
	    printf("error ");
	}
	else {
		printf("%d ",s[Top--]) ;
	}
}
void push (int s[],int b){//jinzhan
	if(isFull())printf("error ");
	else A[++Top]=b;
}
int main (){
	int a,b;
	initStack();
	while((scanf("%d",&a)!=-1)){
		if(a==1) {
			scanf("%d",&b);
			push(A,b);
		}
		else if(a==0) pop(A);
		else if(a==-1) break;
	}
	return 0; 
}

//int comp(const Word* a,const Word* b){
//   return  strcmp((*a).word,(*b).word);
//}

