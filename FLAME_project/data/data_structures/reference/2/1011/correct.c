#include<stdio.h>
int readmum(){
	int a;//a是输入的数字 
	scanf("%d",&a);
	return a;
}
char readletter(){
	char b;//b为输入的运算符 
	do{
		scanf("%c",&b);
	}
	while(b==' ');
	return b;
}
int check(char b1,char b2)//判断运算的优先级 
{
	if(b1=='*'||b1=='/')
		return 0;
	else if(b2=='*'||b2=='/')
		return 1;
	else 
		return 0;
}
int calculate(int x,char b,int y)//计算式 
{
	if(b=='*')
		return x*y;
	if(b=='/')
		return x/y;
	if(b=='+')
		return x+y;
	if(b=='-')
		return x-y;	
}
int main(){
	int one,two,three;//one代表左边的数字，two代表中间的数字，three代表右边的数字 
	char left,right;//left是one和two之间的运算符，right是two和three之间的运算符 
	one=readmum();//读入最左边的数字 
	left=readletter();//读入第一个运算符 
	if(left=='=')
		printf("%d",one);//如果表达式第一个直接跟= 
	else{
		two = readmum();//读入中间的数字 
		right = readletter();//读入右边的运算符 
		if(right == '=')
			printf("%d",calculate(one,left,right));//计算输出结果 
		else{
			while(right!='=')//停止条件读入 = 
			{
				three=readmum();//读入右边的数字 
				if(check(left,right)==0)//判断优先级 
				{//说明left的优先级高 
					one=calculate(one,left,two);//将one更新 
					two=three;//将two跟新 
					left=right;//将left跟新 
				}
				else
				{//说明right的优先级高 
					two=calculate(two,right,three);//更新two 
				}
				right=readletter();//读入下一个运算符 
			}
			printf("%d",calculate(one,left,two));
		}
	}
	return 0;
}






