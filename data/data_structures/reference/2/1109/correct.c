
#include<stdio.h>
  int fu( char s){
     if(s>='0'&&s<='9')return 1;
     if(s=='+')return 2;
      if(s=='-')return 3;
      if(s=='*')return 4; 
      if(s=='/')return 5; 
      if(s=='=')return 6;
      else return;
 }
int cal(int a, int b, char op)
{
	int result;
	if (fu(op) == 2)//fu(op)
		result = a + b;
	else if (fu(op)==3)
		result = a - b;
	else if (fu(op)==4)
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

 
int main()
{
	int a[2];			
	char b[1];				
 
	int num;				//2222
	char op;			
 
	a[0] = readNum();
	b[0] = readOp();
	if (fu(b[0]) != '=')
		a[1] = readNum();
	for (;fu(b[0]) != 6;)
	{
		if (fu(b[0]) == 4 || fu(b[0]) == 5)	
		{
			a[0] = cal(a[0], a[1], b[0]);
			b[0] = readOp();
			if (fu(b[0]) != 6)
				a[1] = readNum();
		}
		else // 说明第一个运算是加减法，需要看后面的运算
		{
			op = readOp();
			if (fu(op)  == 2 || fu(op) == 3 ||fu(op) == 6)
			{
				a[0] = cal(a[0], a[1], b[0]);
				b[0] = op;
				if (fu(op) != 6)
					a[1] = readNum();
			}
			else if (fu(op) != '=')	// 第二个是高优先级运算符，需要先计算
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
 


