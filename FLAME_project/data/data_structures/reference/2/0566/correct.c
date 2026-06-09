#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct element
{
	int data;
	char c;
	int flag;
	int level;
};
void initstack(int top)
{
	top = -1;
}
int isempty(int *top)
{
	return *top == 0;
}
void push(struct element s[], struct element item, int *top)
{
	s[++(*top)] = item;//指针改变top值 
}
struct element pop(struct element s[], int *top)
{
	return s[(*top)--];
 } 
struct element med[1000005], post[1000005], op[1000005];
int l;
int num[1000005];
int topop = -1, topnum = -1;
int i;
int main()
{
	int a;
	char c;
	
	while (1)
	{
		scanf("%d %c", &a, &c);
		med[l].flag = 1;//1表示是整数
		med[l].data = a;
		l++; 
		if (c == '=')
		break;
		med[l].flag = 0;
		med[l].c = c;
		if (c == '*'||c == '/')
		{
			med[l].level = 2;
		}
		else if (c == '+'||c == '-')
		{
			med[l].level = 1;
		}
		l++;
	}
	initstack(topnum);
	initstack(topop);
	
	op[0].flag = 0;
	op[0].level = 0;//符号栈中加入'#'
	topop++;
	
	int x = 0, y = 0, z = 0;//不要忘记初始化 
	//x运算符，y数字，z后缀 
	
	//中缀转后缀
	for (i = 0; i < l; i++)
	{
		if (med[i].flag == 1)
		{
			post[z++] = med[i];
		}
		else if (med[i].flag == 0)
		{
			if (med[i].level > op[topop].level)
			{
				push(op,med[i], &topop);
			}
			else
			{
				while (med[i].level <= op[topop].level)
				{
					post[z++] = pop(op, &topop);
				}
				push(op, med[i], &topop);  
			}
		}
	}
	
	//剩余符号弹入后缀
	while (!isempty(&topop))
	{
		post[z++] = pop(op, &topop);
	 } 
	int n1 = 0, n2 = 0;
	for (i = 0; i < l; i++)
	{
		if (post[i].flag)
		{
			num[++topnum] = post[i].data;
		}
		else
		{
			switch(post[i].c)
			{
				case '+':n2 = num[topnum--];n1 = num[topnum--]; num[++topnum] = n1+n2;break;
				case '-':n2 = num[topnum--];n1 = num[topnum--]; num[++topnum] = n1-n2;break;
				case '*':n2 = num[topnum--];n1 = num[topnum--]; num[++topnum] = n1*n2;break;
				case '/':n2 = num[topnum--];n1 = num[topnum--]; num[++topnum] = n1/n2;break;
			}
		}
	}
	
	printf("%d", num[0]);
	
	return 0;
} 

