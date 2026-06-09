#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
#define Datatype int 
#define LinkDatatype int
#define maxsize 100
//typedef struct node {
//	int data;
//	struct ndoe* next;
//}node;
//void binsort(node *head)//有size个元素的a链表
//{
//	if (!head)return;
//	//if (!head->next)add(head, a);
//	double max = maxelement(head);
//	double min = minelement(head);
//	double length = (max - min) / 4;
//	node* p[4];
//	for(int i = 0; i < 4; i++)
//	{
//		p[i] = (node*)malloc(sizeof(node));
//	}
//	binpush(p, head,min,length);
//	for (int i = 0; i < 4; i++)
//		binsort(p[i]);
//	for (int i = 0; i < 4; i++)
//		connect(p[i],p[i+1]);
//}
//顺序栈
typedef struct {
	Datatype data[maxsize];
	int top;
}Seqstack;
Seqstack* InitStack(Seqstack* S)
{
	S->top = -1;
	return S;
}
Seqstack* SetStack() {
	Seqstack* S;
	S = (Seqstack*)malloc(sizeof(Seqstack));
	S->top = -1;
	return S;
}
int StackEmpty(Seqstack* S) {
	if (S->top >= 0)return 0;
	else return 1;//栈空时返回1，不空返回0
}
int StackFull(Seqstack* S) {
	if (S->top < maxsize - 1 && S->top >= -1)
		return 0;
	else return 1;//栈满时返回1，不满返回0
}
Datatype GetTop(Seqstack* S) {
	if (S->top <= maxsize - 1 && S->top >= 0)
		return S->data[S->top];
	else printf("error");
}
void Push(Seqstack* S, Datatype x) {
	if (S->top < maxsize - 1 && S->top >= -1)
	{
		S->top++;
		S->data[S->top] = x;
	}
	else printf("error");
}
void Pop(Seqstack* S)
{
	if (S->top >= 0)
		S->top--;
	else printf("error");
}
//链栈
typedef struct node{
	LinkDatatype data;
	struct node* next;
}LinkStack;
LinkStack* SetLinkStack() {
	LinkStack* LS;
	LS = NULL;
	return LS;
}
int LinkStackEmpty(LinkStack* LS) {
	if (LS == NULL)
		return 1;
	else return 0;
}
LinkDatatype GetLinkTop(LinkStack* LS)
{
	if (LS != NULL)
		return LS->data;
	else printf("栈空");
}
LinkStack* PushLink(LinkStack* LS, LinkDatatype x) {
	LinkStack* p;
	p = (LinkStack*)malloc(sizeof(LinkStack));
	p->data = x;
	p->next = LS;
	LS = p;
	return LS;
}
LinkStack* PopLink(LinkStack* LS)
{
	LinkStack* u;
	u = LS;
	LS = u->next;
	free(u);
	return LS;
}
LinkStack* InitLinkStack(LinkStack* LS) {
	while (LS) {
		LS = PopLink(LS);
	}
	return LS;
}
//堆栈的应用
//1.数制转换问题，余数的存储符合栈的先入后出
//int main()
//{
//	int n,d;
//	scanf("%d%d", &n, &d);
//	//顺序栈
//	Seqstack* s = setstack();
//	if (!n) {
//		printf("0"); return 0;
//	}
//	while (n) {
//		push(s, n % d);
//		n /= d;
//		if (stackfull(s))return -1;
//	}
//	while (!stackempty(s))
//	{
//		printf("%d",gettop(s));
//		pop(s);
//	}
//	return 0;
//	//链栈写法
//	LinkStack* S = SetLinkStack();
//	if (!n) {
//		printf("0"); return 0;
//	}
//	while (n) {
//		S = PushLink(S, n % d);
//		n /= d;
//	}
//	while (!LinkStackEmpty(S))
//	{
//		printf("%d", GetLinkTop(S));
//		S = PopLink(S);
//	}
//	return 0;
//}
//2.简单的文字编辑器问题，栈的作用：缓存
//int main()
//{
//	LinkStack* LS = SetLinkStack();
//	char sentence[1000];
//	scanf("%s", sentence);
//	int i = 0;
//	while (sentence[i] != '\0') {
//		if (sentence[i] == '#' && !LinkStackEmpty(LS))
//			LS = PopLink(LS);
//		else if (sentence[i] == '@')
//			 LS = InitLinkStack(LS);
//		else if (sentence[i] == '*')
//		{
//			while (!LinkStackEmpty(LS))
//			{
//				//在这儿不应该用链栈，要用顺序栈输出，
//				/*printf("%c", GetLinkTop(LS));
//				LS = PopLink(LS);*/
//			}
//			return 0;
//		}
//		else LS = PushLink(LS,sentence[i]);
//		i++;
//	}
//	return 0;
//}
//3.括号匹配问题，三种括号
//int main()
//{
//	char ch[1000];
//	scanf("%s", ch);
//	Seqstack* S = SetStack();
//	int i = 0;
//	while (ch[i] != '\0') {
//		if (StackEmpty(S) && (ch[i] == '}' || ch[i] == ')' || ch[i] == ']'))
//		{
//			printf("error");
//			return 0;
//		}
//		else if (ch[i] == '(' || ch[i] == '{' || ch[i] == '[')
//			Push(S,ch[i]);
//		else if (S->data[S->top] == '(' && ch[i] == ')' || S->data[S->top] == '{' && ch[i] == '}' || S->data[S->top] == '[' && ch[i] == ']')
//			Pop(S);
//		i++;
//	}
//	if (StackEmpty(S))printf("OK");
//	else printf("error");
//	return 0;
//}
//4.表达式计算，分为三种逐步递进的情况
//4.1.无括号的算术表达式计算问题，设置两个栈，opnd,optr,事实上，我这个是出不来结果的，因为我是用char型的数据，应该重新写栈了
// 要去理解这种《局部的，条件的》栈问题处理具有优先级的问题
//void mmyoperate(Seqstack* opnd, Seqstack* optr) {
//	int a = GetTop(opnd);
//	Pop(opnd);
//	int b = GetTop(opnd);
//	Pop(opnd);
//	char op = GetTop(optr);
//	Pop(optr);
//	switch (op)
//	{
//	case '+': Push(opnd, a + b); break;
//	case '-': Push(opnd, b - a); break;
//	case '*': Push(opnd, a * b); break;
//	case '/': Push(opnd, b / a); break;
//	case '%': Push(opnd, b % a); break;
//	default:
//		break;
//	}
//}
//int inferior(char a, char b) {
//	if ((a == '+' || a == '-') && (b == '*' || b == '/' || b == '%'))
//		return 1;
//	else return 0;
//}//a弱于b
//int main() {
//	char ch[500];
//	scanf("%s", ch);
//	Seqstack* opnd, * optr;
//	opnd = SetStack();
//	optr = SetStack();
//	int i = 0;
//	while (ch[i] != '\0') {
//		if (ch[i] <= '9' && ch[i] >= '0')
//		{
//			int a = 0;
//			while (ch[i] <= '9' && ch[i] >= '0')
//				a = a * 10 + (ch[i++] - '0');
//			Push(opnd, a);
//		}
//		if (ch[i] == '+' || ch[i] == '-' || ch[i] == '*' || ch[i] == '/' || ch[i] == '%') {
//			if (StackEmpty(optr))
//				Push(optr, ch[i++]);
//			else {
//				while (!StackEmpty(optr)&&!inferior(GetTop(optr),ch[i]))
//					mmyoperate(opnd, optr);
//				Push(optr, ch[i++]);
//			}
//		}
//		if (ch[i] == '#')
//		{
//			while (!StackEmpty(optr))			
//				mmyoperate(opnd, optr);
//			printf("%d", GetTop(opnd));
//			return 0;
//		}
//	}
//	printf("error");
//	return 0;
//}
//4.2带括号形式的表达式计算
//LinkStack* myoperate(LinkStack* opnd, Seqstack* optr) {
//	int a = GetLinkTop(opnd);
//	opnd = PopLink(opnd);
//	int b = GetLinkTop(opnd);
//	opnd = PopLink(opnd);
//	char op = GetTop(optr);
//	Pop(optr);
//		switch (op)
//	{
//		case '+': return  PushLink(opnd, a + b); 
//		case '*': return PushLink(opnd, a * b); 
//		case '-': return PushLink(opnd, b - a); 
//		case '/': return PushLink(opnd, b / a); 
//		case '%': return PushLink(opnd, b % a); 
//	default:
//		break;
//	}
//}
//int compare(char a, char b) {
//	if (((a=='+'||a=='-')&&(b=='+'||b=='-'))||((a=='*'||a=='/'||a=='%')&& (b == '*' || b == '/' || b == '%')))return -1;
//	else if ((a == '+' || a == '-') && (b == '*' || b == '/' || b == '%'))return -1;
//	else if (a == ')' && b == '(')return 0;
//	else if (a == ')')return -1;
//	else return 1;
//}
//int main() {
//	char ch[500];
//	scanf("%s", ch);
//	Seqstack* optr;
//	LinkStack* opnd;
//	optr = SetStack();
//	opnd = SetLinkStack();
//	int i = 1;
//	while (ch[i] != '\0') {
//		if (ch[i] <= '9' && ch[i] >= '0')
//		{
//			int a = 0;
//			while (ch[i] <= '9' && ch[i] >= '0') 
//				a = a * 10 + (ch[i++] - '0');
//			opnd = PushLink(opnd, a);			
//		}
//		if (ch[i] == '+' || ch[i] == '/' || ch[i] == '*' || ch[i] == '-' || ch[i] == '%' || ch[i] == '(' || ch[i] == ')') {
//			if (StackEmpty(optr)) Push(optr, ch[i++]);
//			else {
//				while (!StackEmpty(optr)&&compare(ch[i], GetTop(optr)) < 0)
//					opnd = myoperate(opnd, optr);
//				if (!StackEmpty(optr) && !compare(ch[i], GetTop(optr))) {
//					Pop(optr);
//					i++;
//				}
//				else Push(optr, ch[i++]);
//			}
//		}
//		if (ch[i] == '#') {
//			while (!StackEmpty(optr))
//				opnd = myoperate(opnd, optr);
//			printf("%d", GetLinkTop(opnd));
//			return 0;
//		}
//		}
//}
int main() {
	int a;
	scanf("%d", &a);
	Seqstack* S;
	S = SetStack();
	while (a != -1) {
		if (a == 1) {
			if (StackFull(S))
				printf("error ");
			else {
				int b = 0;
				scanf("%d", &b);
				Push(S, b);
			}
		}
		else if(!a) {
			if (StackEmpty(S))
				printf("error ");
			else {
				printf("%d ", GetTop(S));
				Pop(S);
			}
		}
		scanf("%d", &a);
	}
	return 0;
}

