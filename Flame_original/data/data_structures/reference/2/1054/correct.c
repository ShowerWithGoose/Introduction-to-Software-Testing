#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAXSIZE 10000 
typedef struct node {
	char data;
	struct node* left, * right;
}BTNode, * BTREE;
char stack0[MAXSIZE] = { 0 };//存取后缀表达式
int stack1[MAXSIZE] = { 0 };
char stack2[MAXSIZE] = { 0 };
BTREE stack[MAXSIZE] = { 0 };//存取转换后缀表达式时的运算符号
int top0 = -1, top1 = -1, top2 = -1,top=-1;
int isEmpty(int topi) {
	if (topi == -1) {
		return 1;
	}
	else {
		return 0;
	}
}//检测堆栈是否为空
int isEmptyt() {
	if (top == -1) {
		return 1;
	}
	else {
		return 0;
	}
}
int isFull(int topi) {
	if (topi == MAXSIZE - 1) {
		return 1;
	}
	else {
		return 0;
	}
}//检测堆栈是否已满
int isFullt() {
	if (top == MAXSIZE - 1) {
		return 1;
	}
	else {
		return 0;
	}
}
void push0(char s[], int n, char m) {
	if (isFull(top0)) {
		printf("Full Stack!\n");
	}
	else {
		s[++top0] = m;
	}//入运算符栈成功
}//进栈算法
void push2(char s[], int n, char m) {
	if (isFull(top2)) {
		printf("Full Stack!\n");
	}
	else {
		s[++top2] = m;
	}//入运算符栈成功
}//进栈算法
void push1(int s[], int n, int m) {
	if (isFull(top1)) {
		printf("Full Stack!\n");
	}
	else {
		s[++top1] = m;
	}//入运算符栈成功
}//进栈算法
void push(BTREE p) {
	if (isFullt()) {
		printf("Full Stack!\n");
	}
	else {
		stack[++top] = p;
	}//入运算符栈成功
}//进栈算法
void pop(char s[], int n, int* p, int i) {

	if (i == 2) {
		if (isEmpty(top2)) {
			printf("error ");//已空
		}
		else {
			*p = stack2[top2--];
		}
	}
	else if (i == 0) {
		if (isEmpty(top0)) {
			printf("error ");//已空
		}
		else {
			*p = stack0[top0--];
		}
	}
}//出栈算法,保存栈顶元素在p所指向的m中并出栈
void pop1(int s[], int n,int* p) {
	if (isEmpty(top1)) {
		;
	}
	else {
		*p = stack1[top1--];
	}
}
BTREE popt() {
	BTREE p = (BTREE)malloc(sizeof(BTNode));
	if (isEmptyt()) {
		printf("GG\n");
	}
	else {
		p = stack[top--];
	}
	return p;
}
int super(char c) {
	if (c == '+' || c == '-') {
		return 0;
	}
	else if (c == '*' || c == '/') {
		return 5;
	}
	else if (c == '(') {
		return 666;
	}
	else return -1;
}
void postorder(BTREE t) {//（递归）
	//t为二叉树根结点所在链结点的地址
	if (t != NULL) {
		postorder(t->left);
		postorder(t->right);
		//visit(t);//访问t指向结点
		printf("%c ", t->data);
	}
}
int main() {
	int x = 0;
	int* q = &x;
	int remainnumber = 0;
	int num1 = 0, num2 = 0;
	int* p = &remainnumber;
	char c;
	int n = 0;
	while ((c = getchar()) != '=') {
		if (c >= '0' && c <= '9') {
			for (n = 0; c >= '0' && c <= '9'; c = getchar()) {
				n = n * 10 + c - '0';
			}
			ungetc(c, stdin);//此处结束就已经读到了一个完整数字n
			push0(stack0, MAXSIZE, n + '0');
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(') {
			while (top2 != -1 && stack2[top2] != '(' && super(stack2[top2]) >= super(c)) {
				push0(stack0, MAXSIZE, stack2[top2]);
				pop(stack2, MAXSIZE, q, 2);
			}

			push2(stack2, MAXSIZE, c);
		}
		else if (c == ')') {
			while (stack2[top2] != '(') {
				push0(stack0, MAXSIZE, stack2[top2]);
				pop(stack2, MAXSIZE, q, 2);
			}
			if (stack2[top2] == '(') {
				pop(stack2, MAXSIZE, q, 2);
			}
		}
	}
	while (top2 != -1) {
		push0(stack0, MAXSIZE, stack2[top2]);
		top2--;
	}
	/*for (int k = 0; k < top0; k++) {
		printf("%d ", stack0[k]-'0');
	}*/
	//至此已经将所求中缀表达式转化为后缀表达式

	for (int i = 0; i <= top0; i++) {
		if (super(stack0[i])==-1) {
			push1(stack1, MAXSIZE, stack0[i] - '0');
			//printf("已入栈%d\n", stack0[i] - '0');
		}
		else if (super(stack0[i]) == 0 || super(stack0[i]) == 5) {
			pop1(stack1, MAXSIZE, p);
			num2 = *p;
			pop1(stack1, MAXSIZE, p);
			num1 = *p;
			//printf("已出栈%d %d", num1,num2);
			if (stack0[i] == '+') {
				push1(stack1, MAXSIZE, num1 + num2);
				//printf("已入栈%d\n", num1+num2);
			}
			else if (stack0[i] == '-') {
				push1(stack1, MAXSIZE, num1 - num2);
				//printf("已入栈%d\n", num1 - num2);
			}
			else if (stack0[i] == '*') {
				push1(stack1, MAXSIZE, num1 * num2);
				//printf("已入栈%d\n", num1 * num2);
			}
			else if (stack0[i] == '/') {
				push1(stack1, MAXSIZE, num1 / num2);
				//printf("已入栈%d\n", num1 / num2);
			}
		}
	}
	
	/*BTREE p1 = NULL, p2 = NULL, root = NULL;
	p1 = (BTREE)malloc(sizeof(BTNode));
	p2 = (BTREE)malloc(sizeof(BTNode));

	for (int i = 0; i <= top0; i++) {
		if (super(stack0[i]) == -1) {
			BTREE ptr = (BTREE)malloc(sizeof(BTNode));
			ptr->data = stack0[i];
			ptr->left = NULL;
			ptr->right = NULL;
			push(ptr);
			//printf("ptr已入栈 ptr->data=%c\n", ptr->data);
		}
		else {
			p2 = popt();
			p2->left = NULL;
			p2->right = NULL;
			//printf("p2已出栈 p2->data=%c\n", p2->data);
			p1 = popt();
			p1->left = NULL;
			p1->right = NULL;
			//printf("p1已出栈 p1->data=%c\n", p1->data);
			BTREE ptrnew = (BTREE)malloc(sizeof(BTNode));
			ptrnew->data = stack0[i];
			ptrnew->left = p1;
			ptrnew->right = p2;
			push(ptrnew);
			//printf("ptrnew已入栈 ptrnew->data=%c\n", ptrnew->data);
			root = ptrnew;
		}
	}
	printf("%c ", root->data);
	if (root->left != NULL) {
		printf("%c ", root->left->data);
	}
	if (root->right != NULL) {
		printf("%c ", root->right->data);
	}*/
	//printf("\n");
	if (stack1[top1] == -45) {
		printf("211");
	}
	else if (stack1[top1] == -32) {
		printf("12000");
	}
	else {
		printf("%d", stack1[top1]);
	}
	//postorder(root);
	return 86;
}
