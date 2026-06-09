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
    while(scanf("%d",&f)!=-1) // @@ [The condition should check for EOF, not -1. scanf returns EOF on failure/end, not -1. This causes infinite loop or incorrect termination.]
    {
    switch (f)
    {
        case 1:
            scanf("%d",&e);
            push(e);
             break;
        case 0:
            d=pop();
            if(d!=0) // @@ [This incorrectly suppresses output when popped value is 0. The problem requires printing all popped values, including 0. Also, pop() doesn't return a distinguishable error value.]
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
    return 0; // @@ [Unused function, but returns constant 0 instead of actual top element. Not directly causing error but logically wrong.]
}
void error(char s[])
{
        printf("%s", s); // @@ [Prints error without space suffix consistently; also, pop() calls error but still returns undefined value (fall-through).]
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
             error("error "); // @@ [After printing "error ", function falls through and returns uninitialized/garbage value because no return statement after error.]
      else
        {
            int a=s[top];
            s[top]=0;
            top--;
            return a;
        }    //出栈成功  
}