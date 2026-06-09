#include <stdio.h>
#include<string.h>
char s[1003];
int num[1003];
char op[1003];
int top_num=-1,top_op=-1;
int isnumber(char ch)
{
	return ch>='0'&&ch<='9';
}
int cal(int a,int b,char c)
{
	switch(c)
	{
		case '+':return a+b;
		case '-':return a-b;
		case '*':return a*b;
		case '/':return a/b;
		default:return 0;
	}
}
int better(char p)
{
	if(p=='+'||p=='-')return 1;
	if(p=='*'||p=='/')return 2;
}
int than(char p1,char p2)
{
	if(better(p1)<=better(p2))return 1;
	return 0;
}
int POP(void *stack,int *top,int type,void *item)
{
	int *a=(int *)stack;
	int *c=(int *)item;
	char *b=(char *)stack,*d=(char *)item;
	if(*top==-1)return 0;
	if(type==0)*c=a[*top];
	else if(type==1)*d=b[*top];
	(*top)--;
	return 1;
}
int PUSH(void *stack,int *top,int type,void* item)
{
	int *a=(int *)stack;
	int *c=(int *)item;
	char *b=(char *)stack,*d=(char *)item;
	if(type==0)a[++*top]=item;
	else if(type==1)b[++*top]=item;
	else return 0;
	return 1;
}
int EMPTY(int top)
{
	return top==-1;
}
void op_deal(char p)
{
	int lnum,rnum,temp;
	POP(num,&top_num,0,&rnum);
	POP(num,&top_num,0,&lnum);
	temp=cal(lnum,rnum,p);
	PUSH(num,&top_num,0,temp);
}
int main()
{
	int i=0,temp=0;
	char c,p;
	for(i=0;;i++)
	{
		scanf("%c",&s[i]);
		if(s[i]=='=')break;
	}
	i=0;
	while((c=s[i++])!='\0')
	{
		if(isnumber(c))
		{
			do
			{
				temp=temp*10+c-'0';
			}while(isnumber(c=s[i++]));
			PUSH(num,&top_num,0,temp);
			temp=0;
		}
		if(c=='+'||c=='-'||c=='*'||c=='/')
		{
			while(!EMPTY(top_op)&&than(c,op[top_op]))
			{
				POP(op,&top_op,1,&p);
				op_deal(p);
			}
			PUSH(op, &top_op, 1, c);
		}
		if(c=='=')
		while(POP(op,&top_op,1,&p))op_deal(p);
	}
	printf("%d",num[top_num]);
	return 0;
}

