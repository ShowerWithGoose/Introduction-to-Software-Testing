#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100
int stack[MAXSIZE], Top = -1;
int isFull(){
	return Top == MAXSIZE-1;
}
int isEmpty(){
	return Top == -1;
}
void push(int item){
	if(isFull())
		printf("error ");
	else{
		stack[++Top] = item;
	}
}
void pop(){
	if(isEmpty())
		printf("error ");
	else{
		printf("%d ", stack[Top--]);
	}
}
int main(){
	int op /*, num[200], i*/, item;
//	for(i = 0; num[i-1] != -1; i++)
//		scanf("%d",num[i]);
	while(scanf("%d", &op) != -1){
		if(op){
			scanf("%d", &item);
			push(item);
		}
		else pop();
	}
	return 0;
}

