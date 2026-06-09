#include<stdio.h>
#include<string.h>
#include<ctype.h>
char str1[10000]={0};
char str[10000]={0};//字符串 
char op[10000]={0};
int num[10000]={0};//建立分别存储数字，字符的两个栈 
int idx1=0,idx2=0;//分别为两个栈的指针 
void pop1(){idx1--;}//数字栈出栈 
void push1(int x){num[idx1++]=x;}//数字栈入栈 
void pop2(){idx2--;}//算符栈出栈 
void push2(char x){op[idx2++]=x;}//算符栈入栈 
int f(char c)//定义运算符的优先级 
{
    if(c=='+'||c=='-') return 1;
    else 
    {if(c=='*'||c=='/') return 2;}
}
int calculate(int a,int b,char c)//运算符计算函数 
{
	if(c=='+') return a+b;
	else if(c=='-') return a-b;
	else if(c=='*') return a*b;
	else
	{ return a/b;
	 } 
}
int main()
{	int sum=0;
   gets(str1);
    int n=strlen(str1)-1;
    int k=0;
    int l; 
    for( l=0;l<=n;l++)
    {
    	if(str1[l]!=' ') str[k++]=str1[l];
	}//去掉所有空格 
    str[k]='\0';
    int i;
    for ( i = 0; str[i]!='='; i++)
    {
        if(isdigit(str[i])) //判断是否为数字 
		{int u=(int)str[i]-'0';
		i++;
		while(isdigit(str[i]))
		{	
			u=((u*10)+((int)str[i]-'0'));
			i++;
		}
		push1(u);
		i--;
		}//将字符转化为数字压入栈中 
        else
        {   
        	if(idx2==0) push2(str[i]);
            else
			{
			if(f(str[i])>f(op[idx2-1])) push2(str[i]);
            else
            {
                while(f(str[i])<=f(op[idx2-1])&&idx2>=0)//让运算符出栈，直到当前的待入栈算符的优先级严格大于栈顶算符优先级 
                { int a1=num[idx1-1];
                    pop1();
                char b1=op[idx2-1];
                    pop2();
                    int a2=num[idx1-1];
                    pop1();
                    
                   sum=calculate(a2,a1,b1);
                    push1(sum);
                }
                push2(str[i]);//让待入栈的运算符入栈 
            }
        }
        }
        
    }
    //最后再计算一下 
    if(idx2!=0)
    {
    	 while(idx2!=0)
                { int a1=num[idx1-1];
                    pop1();
                char b1=op[idx2-1];
                    pop2();
                    int a2=num[idx1-1];
                    pop1();
                    
                    sum=calculate(a2,a1,b1);
                    push1(sum);
                }
	}
	if(num[idx1-1]==-0) num[idx1-1]=0;
	
    printf("%d",num[idx1-1]);    //此刻留下的栈顶元素即为计算结果 

    return 0;
}

