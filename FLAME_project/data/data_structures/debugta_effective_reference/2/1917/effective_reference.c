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
struct element data[1000005], post[1000005], cal[1000005];
int n1;
int num[1000005];
int n2 = -1, topnum = -1;
int i;
int main()
{
	int d;
	char c;
	
	while (1)
	{
		scanf("%d %c", &d, &c);
		data[n1].flag = 1;//1表示是整数
		data[n1].data = d;
		n1++; 
		if (c == '=')
		break;
		data[n1].flag = 0;
		data[n1].c = c;
		if (c == '*'||c == '/')
		{
			data[n1].level = 2;
		}
		else if (c == '+'||c == '-')
		{
			data[n1].level = 1;
		}
		n1++;
	}
	initstack(topnum);
	initstack(n2);
	
	cal[0].flag = 0;
	cal[0].level = 0;//符号栈中加入'#'
	n2++;
	
	int i = 0, j = 0, z = 0;//不要忘记初始化 
	//x运算符，y数字，z后缀 
	
	//中缀转后缀
	for (i = 0; i < n1; i++)
	{
		if (data[i].flag == 1)
		{
			post[z++] = data[i];
		}
		else if (data[i].flag == 0)
		{
			if (data[i].level > cal[n2].level)
			{
				push(cal,data[i], &n2);
			}
			else
			{
				while (data[i].level <= cal[n2].level)
				{
					post[z++] = pop(cal, &n2);
				}
				push(cal, data[i], &n2);  
			}
		}
	}
	
	//剩余符号弹入后缀
	while (!isempty(&n2))
	{
		post[z++] = pop(cal, &n2);
	 } 
	int n1 = 0, n2 = 0;
	for (i = 0; i < n1; i++)
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

