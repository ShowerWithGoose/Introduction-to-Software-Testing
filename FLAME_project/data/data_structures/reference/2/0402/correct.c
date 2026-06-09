#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXSIZE 100
typedef int ElemType;
struct stack{
	int Top;
	ElemType data[MAXSIZE];
};
typedef struct stack Stack;
typedef struct stack *Stackp;
Stack OPFIGURE,OPTHETA;
void  push( Stackp s,  ElemType item )
{
	s->data[++s->Top]=item; 
}
int pop( Stackp s)
{
	return s->data[s->Top--]; 
}
int Gettop( Stackp s )
{
	return s->data[s->Top];
}
char Pre(char theta1,char theta2)//运算符优先级比较
{
	int i,j;
	char pre[8][8]={// +   -   *   /   (   )   =  %
		             {'>','>','<','<','<','>','>','<'},  
                     {'>','>','<','<','<','>','>','<'},  
                     {'>','>','>','>','<','>','>','>'},  
                     {'>','>','>','>','<','>','>','>'},  
                     {'<','<','<','<','<','=','0','<'},  
                     {'>','>','>','>','0','>','>','>'},  
                     {'<','<','<','<','<','0','=','<'},
					 {'>','>','>','>','<','>','>','>'},}; 
                
    switch(theta1){
    	case '+': i=0; break;  
        case '-': i=1; break;  
        case '*': i=2; break;  
        case '/': i=3; break;  
        case '(': i=4; break;  
        case ')': i=5; break;
        case '=': i=6; break;
        case '%': i=7; break;
	}
	
    switch(theta2){
    	case '+': j=0; break;  
        case '-': j=1; break;  
        case '*': j=2; break;  
        case '/': j=3; break;  
        case '(': j=4; break;  
        case ')': j=5; break;
        case '=': j=6; break;
        case '%': j=7; break;
    }
    return(pre[i][j]);
}
int Op(int a,char theta,int b)//运算符含义表达
{
	int result;
	
	switch(theta){
		case'+':return a+b;
		case'-':return a-b;
		case'*':return a*b;
		case'%':return a%b;
		case'/':                     //判断除数是否为0，若除数为零返回错误提示
		        if(b!=0)
		        return a/b;
		        else
		        {
		        	exit(0);
				}
	}
    
}
int IsTheta(char c) //判断是否为运算符，是运算符返回1，若不是返回0
{
	switch(c){
		case '+':   
        case '-':  
        case '*':   
        case '/':   
        case '(':   
        case ')': 
        case '%': 
        case '=': 
                 return 1;
		 default:
		         return 0;		   
	}
}
int EvaluateExpression(char *expression)  //表达式运算 
{
	ElemType a,b,theta,tmp,X1,X2;
	
	char ch;
	int i=0;
	
	OPFIGURE.Top=-1;
	OPTHETA.Top=-1;
	push(&OPTHETA,'=');  //把 = 压入运算符栈 
	ch=expression[i++];     // ch 读取表达式的下一个字符  
	
	while(ch!='=' || Gettop(&OPTHETA)!='=')
	{
		if(IsTheta(ch)) //判断是否为运算符 
		{
			switch(Pre(Gettop(&OPTHETA),ch)) // 比较 ch 和栈顶运算符  OPTHETA.data 的优先级
			{
				case'<':
						push(&OPTHETA,ch);
						ch=expression[i++];
						break;
				case'>':
						theta=pop(&OPTHETA); 
					    b=pop(&OPFIGURE);
					    a=pop(&OPFIGURE);
					    push(&OPFIGURE,Op(a,theta,b));
					    break;
				case'=':
						tmp=pop(&OPTHETA);
					    ch=expression[i++]; //读取下一位字符并将指针向后偏移一位
					    break;
			} 
			
		}
		else if(isdigit(ch)) //判断是否为数字 
		{
			X1=ch-'0'; //将字符形式转化为数字
			push(&OPFIGURE,X1);
			X2=X1;
			ch=expression[i++]; //读取下一位字符并将指针向后偏移一位
			
			while(isdigit(ch)) //判断下一位是否还是数字
			{
				X1=ch-'0';
				X2=10*X2+X1; //归并至X2
				tmp=pop(&OPFIGURE);
				push(&OPFIGURE,X2);
				ch=expression[i++];  //读取下一位字符并将指针向后偏移一位
				
			} 
		}
		else if(ch==' ') //判断是否为空格
		{
			while(ch==' ')
			{
				ch=expression[i++];
			}
		}
		else //出现非法字符 
		{
			exit(0); 
		}
	}
	return(Gettop(&OPFIGURE));
}
int main()
{	
	char expression[100];
	int result;
	gets(expression);
	result=EvaluateExpression(expression);
	printf("%d\n",result);
	return 0;
}


