#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 100
int Top=-1;
int stack[MAXSIZE];
void initStack();
int isEmpty();
int isFull();
void push(int );
int pop();
int Error(char []);
int main()
{
    int operate=0,mid;
    while(1)
    {
        scanf("%d",&operate);
        if(operate==-1) break;
        switch(operate)
        {
            case 1:
                scanf("%d",&mid);
                push(mid);
                break;
            case 0:
                mid=pop();
                if(mid!=-1)
                	printf("%d ",mid);
        }
    }
    return 0;
}
void initStack()//初始化堆栈
{
    Top=-1;
}
int isEmpty()//判断栈是否为空，空返回1，否则返回0
{
    return Top==-1;
}
int isFull(  )//判断栈是否为满
{
      return Top==MAXSIZE-1;
}
void push(int item )//入栈
{
        if( isFull() )
               Error("Full Stack!");
        else stack[++Top]=item;     
}
int pop()//出栈
{
        if(isEmpty())
            return Error("error ");
        else  return stack[Top--];     
}
int Error(char s[])
{
    printf("%s",s);
    return -1;
}


