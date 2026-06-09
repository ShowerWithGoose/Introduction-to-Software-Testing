#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXSIZE 1024

char s[MAXSIZE], t[MAXSIZE];
int num_stack[MAXSIZE];
int ntop = -1;
char op_stack[MAXSIZE];
int otop = -1;

void pushNum(int num);
int popNum();
void pushOp(char op);
char popOp();

int main() {
	char op, op2, op1, temp2;
	int i, j, num, temp, num1, flag;
	gets(t);
	i = j = 0;
	while (t[i] != '\0') {
		if (t[i] != ' ') s[j++] = t[i++];
		else i++;
	}
	i = 0;
	while (s[i] != '=') {
		num = 0;
		while (isdigit(s[i])) 
			num = num * 10 + s[i++] - '0';
		pushNum(num);
		if (s[i] == '+' || s[i] == '/' || s[i] == '-' || s[i] == '*')
			pushOp(s[i++]);
	}
	for (i = 0; i <= ntop / 2; i++) {
		temp = num_stack[i];
		num_stack[i] = num_stack[ntop - i];
		num_stack[ntop - i] = temp;
	}
	for (i = 0; i <= otop / 2; i++) {
		temp2 = op_stack[i];
		op_stack[i] = op_stack[otop - i];
		op_stack[otop - i] = temp2;
	}
	while (ntop != 0) {
		flag = 0;
		op1 = popOp();
		num1 = popNum();
		op2 = popOp();
		if ((op1 == '-' || op1 == '+') && (op2 == '/' || op2 == '*')) {
			op = op2;
			flag = 1;
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
		if (flag) {
			pushNum(num1);
			pushOp(op1);
		}
	}
	printf("%d\n", num_stack[ntop]);
	return 0;
}
void pushNum(int num) {
	num_stack[++ntop] = num;
}
int popNum() {
	return num_stack[ntop--];
}
void pushOp(char op) {
	op_stack[++otop] = op;
} 
char popOp() {
	return op_stack[otop--];
}



