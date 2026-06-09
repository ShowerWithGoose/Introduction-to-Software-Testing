#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h> 

struct Node
{
	int data;
	struct Node* next;
};
//创建结点 
struct Node* createNode(int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));//动态内存申请
	newNode->data = data;
	newNode->next = NULL;
	return newNode; 
}

struct stack
{
	struct Node* stackTop;//栈顶标记
	int size;             //栈容量 
};
//创建栈-->创建变量struct stack
struct stack* createStack()
{
	//创建过程就是初始化过程
	struct stack* myStack = (struct stack*)malloc(sizeof(struct stack));//动态内存申请
	myStack->stackTop = NULL;
	myStack->size = 0;
	return myStack; 
} 

//入栈 
void push(struct stack* myStack, int data)
{
	//插入的结点
	struct Node* newNode = createNode(data);
	newNode->next = myStack->stackTop;
	myStack->stackTop = newNode;
	myStack->size++;
}

//获取栈顶元素
int top(struct stack* myStack)
{
	//防御编程
	if(myStack->size == 0){
		printf("栈为空");
		system("pause");
		return myStack->size;
	}
	return myStack->stackTop->data; 
}

//出栈
void pop(struct stack* myStack)
{
	if(myStack->size == 0)
	{
		printf("栈为空");
		system("pause");
	}
	else
	{
		struct Node* nextNode = myStack->stackTop->next;
		free(myStack->stackTop);
		myStack->stackTop = nextNode;
		myStack->size--;
	}
} 

//判断是否为空 为空0 不为空1 
int empty(struct stack* myStack)
{
	if(myStack->size == 0)
		return 0;
	return 1;
}

int main()
{
	int n=0;//数据 
	int s=0;//操作 
	struct stack* s1 = createStack();
	while(scanf("%d",&s)!=-1){
		if(s==1){
			scanf("%d",&n);
			push(s1,n);
		} 
		else if(s==0){
			if(empty(s1)==0){
				printf("error ");
			}
			else{
				printf("%d ",top(s1));
				pop(s1);
			}
		}
	}
	system("pause");//防闪屏 
	return 0;
}

