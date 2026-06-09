#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 100
int Stack[MAXSIZE] = { 1,2,3,4,5 };
int Top;
void  iniStack() {
	Top = -1;
}
//初始化堆栈
int isEmpty() {
	if (Top == -1) {
		return 1;
	}
	else {
		return 0;
	}
}//检测堆栈是否为空
int isFull() {
	if (Top == MAXSIZE - 1) {
		return 1;
	}
	else {
		return 0;
	}
}//检测堆栈是否已满
void push(int s[], int n, int m) {
	if (isFull()) {
		printf("Full Stack!\n");
	}
	else {
		s[++Top] = m;
	}//入栈成功
}//进栈算法
void pop(int s[], int n, int* p) {
	if (isEmpty()) {
		printf("error ");//已空
	}
	else {
		*p = Stack[Top--];
		printf("%d ", *p);
		
	}
}//出栈算法,保存栈顶元素在p所指向的m中并出栈
int main() {
	iniStack();
	int m = 0, n = 0, k = 0;
	int* p =&k;
	iniStack();
	while (scanf("%d", &m) != EOF) {
		if (m == 1) {
			scanf("%d", &n);
			push(Stack, MAXSIZE, n);
		}
		else if (m == 0) {
			pop(Stack, MAXSIZE, p);
		}
		else {
			break;
		}
	}
	
	return 86;
}
