#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
void push(int s[], int a);//压一个元素进栈
void pop(int s[]);//从栈中弹出一个元素
int isEmpty(int s[]);
int isFull(int s[]);
//int getTop(int s[]);
int top;
int stack[100];
void initStack();
int main() {

	int n;
	int x;
	initStack();
	while (scanf("%d", &n)) {
		if (n > 0) {
			scanf("%d", &x);
			push(stack, x);
		}
		if (n == 0) {
			pop(stack);
		}if (n < 0) {
			break;
		}
	}


	return 0;

}
void initStack() {
	top = -1;
}
int isEmpty(int s[]) {
	return top == -1;
}
int isFull(int s[]) {
	return top == 99;
}
void push(int s[], int a) {
	if (isFull(s)) {
		printf("error ");
		//printf("Full Stack!");
		//exit(-1);
	}
	else s[++top] = a;
}
void pop(int s[]) {
	if (isEmpty(s)) {
		printf("error ");
		//printf("Empty Stack!");
		//exit(-1);
	}
	else printf("%d ", s[top--]);
}


