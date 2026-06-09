#include<stdio.h>
#define MAXSIZE 100
int  s[MAXSIZE];//全局变量 
int  top=-1;

void push(int e ); //压一个元素进栈
int pop() ;//从栈中弹出一个元素
int empty() ;//判断栈是否为空
int full() ;//判断栈是否已满
int getTop(); //获取栈顶元素


int main()
{
    int e,f,d=0;
    while(scanf("%d",&f)!=-1) // @@ [错误：scanf返回值应与EOF比较，而不是-1。当输入结束时scanf返回EOF（通常为-1），但直接比较-1在某些系统上可能不准确，应使用EOF宏。同时，当输入-1操作时，程序应结束循环，但当前代码在case -1中只break，导致循环继续，应使用return 0或修改循环条件。]
    {
    switch (f)
    {
        case 1:
            scanf("%d",&e);
            push(e);
             break;
        case 0:
            d=pop();
            if(d!=0) // @@ [错误：pop函数在栈空时输出"error "但返回值为void（实际未定义），导致d的值不确定。这里检查d!=0无法正确判断是否成功弹出，因为弹出的元素可能为0。应修改pop函数返回一个标志或使用其他方式处理。]
            printf("%d ",d );
             break;
        case -1:
             break; // @@ [错误：遇到-1操作应结束程序，但这里只break出switch，循环继续执行，导致无限循环或读取后续无效输入。应改为return 0;]
        default:
             break;
    }
    }

}

int empty( )//测试堆栈是否为空 
{
       return top==-1;
} 
int full(  )//栈满,返回1,否则,返回0
{
      return top==MAXSIZE-1;
}
int getTop()
{
    return 0;
}
void error(char s[])
{
        printf("%s", s);
}

void push(int item )
{
        if( full() )
               error("error ");
        else
        {
            top++;
            s[top]=item;
        }//入栈成功
        
}
int pop()
{
      if(empty())
             error("error "); // @@ [错误：pop函数在栈空时输出"error "但没有返回值，函数声明为返回int，导致未定义行为。应返回一个特殊值（如0）或修改函数设计。]
      else
        {
            int a=s[top];
            s[top]=0;
            top--;
            return a;
        }    //出栈成功  
}