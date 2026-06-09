#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXSIZE 100
int s[MAXSIZE];
int Top=-1;
int isEmpty(){
	return Top==-1;
}
int isFull(){
	return Top==MAXSIZE-1;
}

void push(int s[], int e){
	if( isFull() ){
		printf("error ");
	}else{
		s[++Top]=e;
	}
}//è¿›
void pop(int s[ ]){
	if(isEmpty()){
		printf("error ");
	}else{
		printf("%d ",s[Top--]);
	}
}
int main(){
	int n,e;
	while(scanf("%d",&n)){
		if(n==-1){
			break;
		}
		switch(n){
			case 1: scanf("%d",&e);push(s,e);break;
			case 0: pop(s);break;
		}
	}
	return 0;
}
