#include<stdio.h>//将栈设置为全局变量 
#define MAXN 105
typedef struct Stack
{
	int mem[MAXN];
	int top;
} numStack;

numStack numArray;
int item;//item记录被弹出的元素 

void init_Stack()
{
	numArray.top = -1;
}

int pop_Stack()
{
	if(numArray.top != -1)
	{
		item = numArray.mem[numArray.top];
		numArray.top--;
		return 1;
	} 
	return 0;//删除失败 
}

int push_Stack(int num)
{
	if(numArray.top != 99)
	{
		numArray.top++;
		numArray.mem[numArray.top] = num;
		return 1;
	}
	return 0;//插入失败 
}

int main()
{
	int op, num, flag = 0;
	init_Stack();
	while (scanf("%d", &op) != EOF)
	{
		switch(op)
		{
			case 1:
				scanf("%d", &num);
				if(push_Stack(num) == 0)
				{
					printf("error ");
				}
				break;
			case 0:
				if(pop_Stack() == 0)
				{
					printf("error ");
				}
				else
				{
					printf("%d ", item);
				}
				break;
			case -1:
				flag = 1;
				break;
		}
		if (flag == 1)
		{
			break;
		}
	}
	return 0;
}

