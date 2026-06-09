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
    while(scanf("%d",&f)!=-1)
    {
    switch (f)
    {
        case 1:
            scanf("%d",&e);
            push(e);
             break;
        case 0:
            d=pop();
            if(d!=0)
            printf("%d ",d );
             break; // @@ [The condition `if(d!=0)` incorrectly suppresses printing when the popped value is 0. According to the problem, all successfully popped values (including 0) should be printed. Also, the `pop()` function returns 0 both when popping a 0 and when the stack is empty (due to missing return in error case), leading to ambiguity.]
        case -1:
             break;
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
    return 0; // @@ [This function always returns 0 and is unused, but more critically, the `pop()` function does not return a distinguishable value on error, causing the main logic to misinterpret error as a valid pop of 0.]
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
             error("error "); // @@ [This prints "error " but does not return a value that can be distinguished from a valid popped 0. The function falls through without returning, leading to undefined behavior. It should return a special value or handle output entirely within pop without relying on return value for error detection.]
      else
        {
            int a=s[top];
            s[top]=0;
            top--;
            return a;
        }    //出栈成功  
}