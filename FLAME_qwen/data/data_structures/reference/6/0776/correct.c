#include<stdio.h>
#include<string.h>
#include<ctype.h>

int op,num,top,a[100];

int isFull()
{
	if(top==99) return 1;
	return 0; 
} 


int isEmpty()
{
	if(top==-1) return 1;
	return 0;
}

int main()
{
	top=-1;
	scanf("%d",&op);
//	printf("op = %d\n",op);
	int k=0;
	while(op!=-1)
	{
		if(op==1)//入栈 
		{
			if(isFull()) printf("error ");
			else
			{
				scanf("%d",&num);
//				printf("top = %d\n",top);
				a[++top]=num;
//				printf("top = %d\n",top);
			}
		}
		else//出栈
		{
			if(isEmpty()) printf("error ");
			else
			{
				printf("%d ",a[top]);
				a[top]=0;
				top--;
			}
		}
		scanf("%d",&op);
//		printf("op = %d\n",op);
	}
	return 0;
 } 
 /*思路
1建立一个栈 
2读取一个操作数
  	为-1：结束
	  不为-1：进入3
3为1：读入num；判断栈是否满：
				满了：输出error
				不满：将num加入到栈中
 为0：输判断栈是否空：
 					空了：输出error
					 没空：出栈顶元素，删除栈中该元素 
  */

