#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define M 1000
typedef int elemtype;
elemtype STACK[M];
int top;
void Error(char s[]) {
	printf("%s",s);
}
void initial() {
	top=-1;
}
int isempty() {
	return top==-1;
}
int isfull() {
	return top==M-1;
}
void push(elemtype s[],elemtype item) {
	if(isfull()) {
		Error("error ");
	} else {
		s[++top]=item;
	}
}
elemtype pop(elemtype s[]) {
	if(isempty()) {
		Error("error ");
	} else {
		return s[top--];
	}
}
int main() {
	char ch1;
	int ch2;
	initial();
	while(scanf("%c",&ch1)!=-1) {
		getchar();
		if(ch1=='1') {
			scanf("%d",&ch2);
			getchar();
			push(STACK,ch2);
		} else if(ch1=='0') {
			if(isempty()){
				;
			}
			else printf("%d ",STACK[top]);
			pop(STACK);
		}
	}
	return 0;
}
