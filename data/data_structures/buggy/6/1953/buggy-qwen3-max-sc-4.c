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
    while(scanf("%d",&f)!=-1) // @@ [The condition should check for EOF, not -1. scanf returns EOF on failure/end-of-input, not -1. This causes infinite loop or incorrect termination.]
    {
    switch (f)
    {
        case 1:
            scanf("%d",&e);
            push(e);
             break;
        case 0:
            d=pop();
            if(d!=0) // @@ [This incorrectly suppresses output when pop returns 0. Popping 0 is valid and should be printed. Also, error handling via return value is flawed because pop() doesn't return a distinguishable error code.]
            printf("%d ",d );
             break;
        case -1:
             break; // @@ [Missing 'return 0;' or exit logic. Loop continues after -1 instead of terminating program.]
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
    return 0; // @@ [Always returns 0 regardless of stack state. Should return s[top] if not empty, but unused in main anyway.]
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
             error("error ");
      else
        {
            int a=s[top];
            s[top]=0;
            top--;
            return a;
        }    //出栈成功  
} // @@ [Function does not return a value in the error case (when stack is empty), leading to undefined behavior when caller uses the return value.]