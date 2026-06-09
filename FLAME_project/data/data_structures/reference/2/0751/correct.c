#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
char stack1[20];                      //符号栈 栈顶指针p2，栈底指针p1 
int stack2[20];
struct t1
{
	int M[100];
	int top1;
};   //数字栈 
struct t2
{
	char N[100];
	int top2;
};   //符号栈 
int fh(char a,char b)                           //符号优先级比较,a为当前读入，b为栈顶元素 
{
	int c;                                              //c反馈指令信息 0.结束 1.弹出 2.进栈 3.删除当前元素及栈顶元素 4.报错 
	switch(b)
	{
		case '#':if(a=='#') c=0;
				 else c=1;break;
		case '+':if(a=='#') c=2;
		         else c=1;break;
		case '-':if(a=='#') c=2;
		         else c=1;break;
		case '*':if(a=='*'||a=='/') c=1;
		         else c=2;break;
		case '/':if(a=='*'||a=='/') c=1;
		         else c=2;break;
		default :c=4;break; 
	}
	return c;
} 
int main()
{
	char str[50]={"\0"};
	char *p=str;
	int *p3,*p4,a=0,b=0;
	char *p1,*p2; //数字栈 栈顶指针p4，栈底指针p3 
	p1=p2=stack1;
	p3=p4=stack2;
	*p2++='#';
	gets(str);
	strcat(str,"#");
	while(*p!='\0')
	{
		if(*p<='9'&&*p>='0') 
		{
			a=a*10+(*p-'0');
			if(*(p+1)>'9'||*(p+1)<'0')
			{
				*p4++=a;
				a=0;
			}
			p++;
		}
		else
		{
			switch(fh(*(p2-1),*p))
			{
				case 0:
						printf("%d",*p3);
						p++;
						break;
				case 1:
						b=*--p4;
						switch(*(--p2))
						{
							case '+':*(p4-1)=*(p4-1) + b;break;
							case '*':*(p4-1)=*(p4-1) * b;break;
							case '-':*(p4-1)=*(p4-1) - b;break;
							case '/':*(p4-1)=*(p4-1) / b;break;
						}
						break;
				case 2:
						*p2++=*p++;
						break;
				case 3:
						p++;
						p2--;
						break;
				case 4:
						p++;
						break;
			}
		 } 
	}
	return 0;
}

