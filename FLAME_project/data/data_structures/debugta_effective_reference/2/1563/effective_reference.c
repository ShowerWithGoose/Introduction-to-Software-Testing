#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXSIZE 1024

char expression[MAXSIZE], c[MAXSIZE];
int num_stack[MAXSIZE];
int on = -1;
char op_stack[MAXSIZE];
int otop = -1;

void pushNum(int num);
int popNum();
void pushOp(char op);
char popOp();

int main() {
	char op, op2, op1, temp2;
	int t, j, num, temp, num1, opnum;
	gets(c);
	t = j = 0;
	while (c[t] != '\0') {
		if (c[t] != ' ') expression[j++] = c[t++];
		else t++;
	}
	t = 0;
	while (expression[t] != '=') {
		num = 0;
		while (isdigit(expression[t])) 
			num = num * 10 + expression[t++] - '0';
		pushNum(num);
		if (expression[t] == '+' || expression[t] == '/' || expression[t] == '-' || expression[t] == '*')
			pushOp(expression[t++]);
	}
	for (t = 0; t <= on / 2; t++) {
		temp = num_stack[t];
		num_stack[t] = num_stack[on - t];
		num_stack[on - t] = temp;
	}
	for (t = 0; t <= otop / 2; t++) {
		temp2 = op_stack[t];
		op_stack[t] = op_stack[otop - t];
		op_stack[otop - t] = temp2;
	}
	while (on != 0) {
		opnum = 0;
		op1 = popOp();
		num1 = popNum();
		op2 = popOp();
		if ((op1 == '-' || op1 == '+') && (op2 == '/' || op2 == '*')) {
			op = op2;
			opnum = 1;
		} 
		else {
			op = op1;
			pushOp(op2);
			pushNum(num1);
		}
		switch(op) {
			case '+':
				pushNum(popNum() + popNum());
				break;
			case '-':
				pushNum(popNum() - popNum());
				break;
			case '*':
				pushNum(popNum() * popNum());
				break;
			case '/':
				pushNum(popNum() / popNum());
				break;
		}
		if (opnum) {
			pushNum(num1);
			pushOp(op1);
		}
	}
	printf("%d\n", num_stack[on]);
	return 0;
}
void pushNum(int num) {
	num_stack[++on] = num;
}
int popNum() {
	return num_stack[on--];
}
void pushOp(char op) {
	op_stack[++otop] = op;
} 
char popOp() {
	return op_stack[otop--];
}



