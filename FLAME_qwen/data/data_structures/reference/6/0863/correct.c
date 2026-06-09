#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};

struct stack
{
	struct node* stacktop;//栈顶标记 
	int size;//栈中元素个数
};
//创建节点
struct node* createnode(int data) 
{
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->next =NULL;
	return newnode;
}
//创建栈 ，就是创建一个struct stack的变量
struct stack* createstack()
{	//创建过程就是初始化过程
	struct stack* mystack=(struct stack*)malloc(sizeof(struct stack)) ;
	mystack->stacktop =NULL;
	mystack->size =0;
	return mystack; 
 } 
 //入栈
 void push(struct stack*mystack,int data)
 {
 	if(mystack->size==100)
 	{
 		printf("error ");
	 }
	 else
	 {
	 	struct node* newnode=createnode(data);
	 	//入栈操作就是链表的的表头插入 
	 	newnode->next =mystack->stacktop;
	 	mystack->stacktop=newnode;
	 	mystack->size++; 
	 }
 	
 }
int top(struct stack* mystack)//获取栈顶元素 
{
	//考虑空的情况
	if(mystack->size ==0)
	{
		printf("empty\n");
		return mystack->size;
	 } 
	 return mystack->stacktop->data ;
}
//出栈
void pop(struct stack* mystack)
{
	if(mystack->size==0)
	{
		printf("error ");
	}else
	{
		printf("%d ",top(mystack));
		struct node* nextnode=mystack->stacktop->next ;
		free(mystack->stacktop );
		mystack->stacktop =nextnode;
		mystack->size--;
	}
 } 
 int empty(struct stack* mystack)//判断栈是否为空 
 {
 	if(mystack->size ==0)
 	{
 		return 0;
	 }
	 return 1;
 }
int main()
{
	int op;int num;
	struct stack* mystack=createstack();
	while(1)
	{
		scanf("%d",&op);
		if(op==-1)
		{
			break;
		}else if(op==1)
		{
			scanf("%d",&num);
			push(mystack,num);
		}else if(op==0)
		{
			pop(mystack);
		}
	 } 
	return 0; 
} 

