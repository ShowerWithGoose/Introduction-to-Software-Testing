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
    while(scanf("%d",&f)!=-1) // @@ [The loop condition should check for EOF, not -1. scanf returns EOF on failure or end-of-input, not -1. This causes the program to not terminate properly on end of input.]
    {
    switch (f)
    {
        case 1:
            scanf("%d",&e);
            push(e);
             break;
        case 0:
            d=pop();
            if(d!=0) // @@ [This condition incorrectly suppresses output when pop() returns 0 (a valid value). The problem requires printing every popped value, including 0. Also, when an error occurs, pop() doesn't return a distinguishable value to indicate error, leading to undefined behavior.]
            printf("%d ",d );
             break;
        case -1:
             break; // @@ [When encountering -1, the program should terminate immediately (e.g., return 0), but instead it just breaks out of the switch and continues the loop, potentially processing more input.]
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
    return 0; // @@ [This function always returns 0 regardless of stack state. Though unused in main, it's logically incorrect. However, the critical issue is that pop() does not return a special value on error, making error handling impossible in main.]
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
             error("error "); // @@ [After printing "error ", the function falls through without returning a value, causing undefined behavior when main tries to use the return value (d=pop()).]
      else
        {
            int a=s[top];
            s[top]=0;
            top--;
            return a;
        }    //出栈成功  
}