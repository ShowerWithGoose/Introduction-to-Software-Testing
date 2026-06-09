#include<stdio.h>//1 3 1 5 1 7 0 0 1 8 0 1 12 1 13 0 0 0 0 1 90 1 89 0 -1
#include<string.h>
#include<stdlib.h>
int Operation;//操作判断，只读1/0
int Number; //压入栈的数据
#define INITSIZE 100 //储存空间的初始分配
typedef int ELemType;
typedef struct
{
    ELemType *base; //存放元素的动态数组的起始地址
    int top;//栈顶指针
    int stacksize;//当前栈的空间大小
}SeqStack;
void InitStack(SeqStack*s);//创建一个空栈
void Push(SeqStack*s,ELemType x);//压栈操作
void Pop(SeqStack*s,ELemType *e);//弹栈+输出栈操作
int main()
{
    int i=0,j=0;
    SeqStack s;
    ELemType e;
    InitStack(&s);//初始化空栈
    while (scanf("%d",&Operation)!=-1)
    {
    	if(Operation==-1)
    	break;
        if (Operation==1)//如果结果为1
        {
           scanf("%d",&Number);
           Push(&s,Number);//将数据压入栈中
        }
        else//如果结果为0
        {
           Pop(&s,&e);//弹栈,输出相应的数
        }
    }
    printf("\n");
    return 0;
}
void InitStack(SeqStack*s)
{
    s->base=(ELemType*)malloc(INITSIZE*sizeof(ELemType));//申请储存空间
    s->top=0;//栈顶指针初始值为0
    s->stacksize=INITSIZE;//栈容量为初始值
}
void Push(SeqStack*s,ELemType x)
{
    if(s->top>=s->stacksize)
    {
        s->base=(ELemType *)realloc(s->base,(s->stacksize+1)*sizeof(ELemType));
        //栈满则增加一个储存单元
        if(!s->base)//分配失败返回0
        printf("error ");
        s->stacksize++;
    }
    s->base[s->top++]=x;//插入元素指针后移
}
void Pop(SeqStack*s,ELemType *e)
{
    if(s->top==0)
    printf("error ");
    else
   {
        printf("%d ",s->base[s->top-1]);
        *e=s->base[--s->top];//栈顶指针减1，再取顶元素值
   }
}

