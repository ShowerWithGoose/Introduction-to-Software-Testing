#include<stdio.h>

#define MAXNUM 100

int s[MAXNUM];
int front=0,rear=-1,count=0;
void Insert_Stack(int data);
int Delete_Stack();

int isFull();
int isEmpty();

int main()
{
	int mode,data;
	while(scanf("%d",&mode)!=EOF)
	{
		if(mode==1)
		{
			scanf("%d",&data);
			//如果栈已满,那么输出error并进行下一次循环
			if(isFull()) 
			{
				printf("error ");
				continue;
			}
			//没满就插入
			else
			{
				Insert_Stack(data);
			}
		}
		else if(mode==0)
		{
			//如果栈为空,那么输出error并进行下一次循环
			if(isEmpty())
			{
				printf("error ");
				continue;
			}
			//不为空就输出并删除
			else
			{
				printf("%d ",Delete_Stack());
			}
		}
		//如果mode为-1就推出
		else
		{
			break;
		}
	}
	return 0;
}

int isFull()
{
	return count==MAXNUM;
}

int isEmpty()
{
	return count==0;
}

void Insert_Stack(int data)
{
	rear++;
	s[rear]=data;
	count++;
}

int Delete_Stack()
{
	int data=s[rear];
	rear--; count--;
	return data;
}
