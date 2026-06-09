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
    while(scanf("%d",&f)!=-1) // @@ [The loop condition should check for EOF, not -1. scanf returns EOF on failure or end-of-input, not -1. This causes the program to not terminate properly on -1 input and may lead to infinite loop or undefined behavior.]
    {
    switch (f)
    {
        case 1:
            scanf("%d",&e);
            push(e);
             break;
        case 0:
            d=pop();
            if(d!=0) // @@ [This condition incorrectly suppresses output when pop() returns 0. The value 0 is a valid integer that can be pushed and popped. The program should output all popped values, including 0. Also, pop() returns 0 in error case due to missing return after printing "error ", leading to undefined behavior.]
            printf("%d ",d );
             break;
        case -1:
             break; // @@ [This break only exits the switch, not the loop. The program should terminate immediately upon reading -1, but it continues reading more input. It should use return 0; or break out of the loop.]
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
    return 0; // @@ [This function always returns 0 regardless of stack state. Though unused in main, it's logically incorrect. However, the critical issue is in pop(): when stack is empty, it prints "error " but doesn't return a distinguishable value, and falls through to return uninitialized/undefined behavior.]
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
             error("error "); // @@ [After printing "error ", the function does not return a value in this branch, leading to undefined behavior when the caller uses the return value. Also, the main function checks if(d!=0), which fails to detect error because error case doesn't return a special sentinel.]
      else
        {
            int a=s[top];
            s[top]=0;
            top--;
            return a;
        }    //出栈成功  
} // @@ [Missing return statement in the error (empty stack) path of pop(). This causes undefined behavior when pop() is called on empty stack and its return value is used.]