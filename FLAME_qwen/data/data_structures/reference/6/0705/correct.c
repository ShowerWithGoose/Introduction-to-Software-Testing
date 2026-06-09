#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>
#include <assert.h>
#include<ctype.h>
#define ll long long //9223372036854775807（>10^18）   int -2^31=-21 4748 3648  2^31-1=21 4748 3647
#define ull unsigned ll
#define db double

typedef struct Stack
{
	int data[200];
 
	int top;//定义栈顶
 
	int size;//定义栈的大小
 
}Stack;

Stack* InitStack(int Capacity);
int main()
{
	int flag=0;
	int num;
	Stack* LinkList=InitStack(111);
	while(scanf("%d",&num)!=EOF)
	{
		if(num==0)
	    {
		    if(LinkList->top>-1)
		    {
		        printf("%d ",LinkList->data[LinkList->top]);
			    LinkList->top-=1;
	    	}
		    else 
	    	{
		    	printf("error ");
	    	}
		
	   	}
	   	else if(num==1)
		    {
			    flag=1;
		    }
		else if(flag==1)
		{
		    LinkList->top+=1;
		    LinkList->data[LinkList->top]=num;
			
	    }
		   
	
		
	}
}


Stack* InitStack(int Capacity)//定义结构为指针函数，方便后续返回值应用指针，参数是希望初始栈的大小
{
	Stack* LinkList = (Stack* )malloc(sizeof(Stack));//初始化一个栈空间
 
	LinkList->top = -1;//把新创建的结构体――LinkList中的栈顶初始化为-1，栈从0开始算
 
	LinkList->size = Capacity;//根据输入记录栈数组空间最大值
 
	return LinkList;
}

 
 



 



