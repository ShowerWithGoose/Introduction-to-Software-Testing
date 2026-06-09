#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define ll long long //9223372036854775807（>10^18）   int -2^31=-21 4748 3648  2^31-1=21 4748 3647
#define ull unsigned ll
#define db double

int cal(int a, int b, char op);		// 做运算
int readNum();						// 读一个数
char readOp();						// 读一个运算符
 
int main()
{
	int a[2];				// 放置开始的两个数值
	char b[1];				// 放置第一个操作符
 
	int num;				// 下一个数
	char op;				// 下一个操作符
 
	a[0] = readNum();
	b[0] = readOp();
	if (b[0] != '=')
		a[1] = readNum();
	while (b[0] != '=')
	{
		if (b[0] == '*' || b[0] == '/')	// 表示可以马上运算，运算后，又回到初始状态
		{
			a[0] = cal(a[0], a[1], b[0]);
			b[0] = readOp();
			if (b[0] != '=')
				a[1] = readNum();
		}
		else // 说明第一个运算是加减法，需要看后面的运算
		{
			op = readOp();
			if (op == '+' || op == '-' || op == '=')
			{
				a[0] = cal(a[0], a[1], b[0]);
				b[0] = op;
				if (op != '=')
					a[1] = readNum();
			}
			else if (op != '=')	// 第二个是高优先级运算符，需要先计算
			{
				num = readNum();
				a[1] = cal(a[1], num, op);
			}
			else	// op == '='
				b[0] = op;
		}
 
	}
	// b[0] == '=', 结束
	printf("%d\n", a[0]);
 
	return 0;
}
 
int cal(int a, int b, char op)
{
	int result;
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
 
int readNum()
{
	int num;
	scanf(" %d", &num);
	return num;
}
char readOp()
{
	char op;
	scanf(" %c", &op);
	return op;
}



