
#include<stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
int suan(int a, int b, char op);	// 运算函数
int dushu();						// 读一个数
char fuhao();						// 读一个运算符
int main() {
	int a[2];				// ao()a1
	char b[1];				// 符号c
	int num;				// 下一个数
	char op;				// 下一个操作符
	a[0] = dushu();
	b[0] = fuhao();
	if (b[0] != '=')//防止直接数字+等于号
		a[1] = dushu();
	while (b[0] != '=') {
		//乘除法先算
		if (b[0] == '*' || b[0] == '/') {	// 乘除马上运算，运算完之后回到开始状态
			a[0] = suan(a[0], a[1], b[0]); //把前面的式子变成a0
			b[0] = fuhao();//再输入新的运算符
			if (b[0] != '=')//新的运算符不是等于号
				a[1] = dushu();//再读入新的后面需运算的数字
		}
		// 说明第一个运算是加减法，需要看后面的运算是否有乘除法，先运算乘除
		else {
			op = fuhao();//输入新的符号（储存 
			if (op == '+' || op == '-' || op == '=') {//符号是加减法 
				a[0] = suan(a[0], a[1], b[0]);//进行前面的运算 
				b[0] = op;// 赋值 
				if (op != '=')//不等于零 
					a[1] = dushu();//进行新的读取 
			} else if (op != '=') {	// 第二个是高优先级运算符，需要先计算
				num = dushu();
				a[1] = suan(a[1], num, op);//重新赋值a1 
			} else	// op == '='
				b[0] = op;
		}

	}
	// b[0] == '=', 结束
	printf("%d\n", a[0]);

	return 0;
}

int suan(int a, int b, char op) {
	int result;
	/*	switch (op) {
			case '+' :
				result = a + b;
				break;
			case '-' :
				result = a - b;
				break;
			case '*'  :
				result = a * b;
				break;
			case'/':
				result = a / b;
				break;
			}
				*/
	if (op == '+')
		result = a + b;
	else if (op == '-')
		result = a - b;
	else if (op == '*')
		result = a * b;
	else
		result = a / b;
	return result;



}
int dushu() {
	int num;
	scanf(" %d", &num);
	return num;
}
char fuhao() {
	char op;
	scanf(" %c", &op);
	return op;
}



