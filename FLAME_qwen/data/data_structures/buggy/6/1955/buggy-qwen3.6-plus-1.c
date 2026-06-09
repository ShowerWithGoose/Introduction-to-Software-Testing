/*错误 
1，未初始化栈数组导致出问题 
*/
/*新使用或复习的代码 
1，尝试使用函数来实现栈操作 
*/
/*代码思路学习 

*/
/*代码风格学习 
1，尝试声明函数以使得界面整洁 
*/
/*编程思路学习 

*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXSIZE     100//要调!
int STACK[MAXSIZE];
int  Top;//全局变量方便调用，初始值设置为-1 

void initStack();//初始化函数 
void Error(char s[]); //前置报错函数 
int isEmpty();//判断是否栈空 是1 否0 
int isFull();//判断是否栈满 是1 否0
void push( int s[],  int item );//压进栈 
int pop( int s[]);//弹出栈 

int main()
{
    int op, item;
    
    initStack();//记得要初始化！！！ 
    
    while(1)
    {
        scanf("%d", &op);
        if(op == -1)
        {
            break;
        }
        else if(op == 1)
        {
            scanf("%d", &item);
            push(STACK, item);
        }
        else
        {
            pop(STACK);
        }
    }
    
    return 0;
}

void initStack()
{
    Top = -1;
}

void Error(char s[])//这个不错 
{
    printf("%s", s);//可改 
    //exit(-1);//退出程序并返回给操作系统 //可以不加 
}

int isEmpty()
{
    return Top == -1;
} 

int isFull()
{
    return Top == MAXSIZE - 1;
}

void push( int s[],  int item )
{
    if( isFull() )
        Error("Error "); // @@ [Should output "error " (lowercase) as specified in the problem description]
    else
        s[++Top] = item;        
}

int pop( int s[])
{
    if(isEmpty())
        Error("Error "); // @@ [Should output "error " (lowercase) as specified, and function lacks a return statement when stack is empty]
    else
    {
        printf("%d ", s[Top]);
        return s[Top--];
    }     
} // @@ [Missing return statement for non-void function when stack is empty, causing compilation error]