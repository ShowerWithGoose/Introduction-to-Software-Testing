#include <stdio.h>

int num_input(void); //输入一个数字
char op_input(void); //输入一个运算符 如果输入的是空格需要输到一个非空格的为止才算可以 
int calculate(int num1, char op, int num2);
int judge(char ch1,char ch2);//此函数是为了判断运算的优先级  a op b op c
int main(void)
{
	//考虑 a op1 b op2 c 的这样一个三个数两个运算符的结构 
	int left_num,middle_num,right_num; //left_num 对应 a, middle_num对应b, right_num对应c 
	char left_op, right_op; //left_op 对应 左侧的第一个op right_op 对应 右侧的第二个op
	left_num = num_input(); //输入第一个数 
	left_op=op_input();//输入第一个字符 
	if(left_op=='=')//如果输入的字符直接就是等号，意味着直接就结束了，输出数值 
	{
		printf("%d",left_num);
	} 
	else//输入的字符不是等号，而是别的有意义的字符，注意输入字符的函数一定会保证输到 + - * / 为止 不会只有空格 
	{
		middle_num = num_input();
		right_op = op_input();
		if(right_op=='=')
		{
			printf("%d",calculate(left_num,left_op,middle_num));
		}
		else
		{
			while(right_op!='=') //右侧运算符不为等号 
			{
				//需要持续输入最右侧的数字
				right_num=num_input(); 
				if(judge(left_op,right_op))
				{
					middle_num=calculate(middle_num,right_op,right_num);
				}
				else
				{
					left_num =  calculate(left_num,left_op,middle_num);
					left_op=right_op;
					middle_num=right_num;
				}
				right_op=op_input();
			}
			printf("%d",calculate(left_num,left_op,middle_num));
			
		}
	} 
	return 0;
}
int num_input(void)
{
	int a;
	scanf("%d",&a);
	return a;
}
char op_input(void)
{
	char ch;
	do
	{
		scanf("%c",&ch);
	}while(ch==' ');
	return ch;	//正好返回的是非空格的有意义的字符 
} 
int calculate(int num1, char op, int num2)
{
	switch(op)
	{
		case '+':
			return num1+num2;
			break;
		case '-':
			return num1-num2;
			break;
		case '*':
			return num1*num2;
			break;
		case '/':
			return num1/num2;
			break;
	}
}
int judge(char ch1,char ch2)//此函数是为了判断运算的优先级  a op b op c
{
	if(ch1=='*'||ch1=='/')
	{
		return 0;
	}
	else
	{
		if(ch2=='*'||ch2=='/')
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}

