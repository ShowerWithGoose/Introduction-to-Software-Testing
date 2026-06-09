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
    while(scanf("%d",&f)!=-1) // @@ [The condition should check for EOF, not -1. scanf returns EOF on end-of-file or error, not -1. This causes the loop to never terminate properly when input ends, leading to infinite loop or undefined behavior.]
    {
    switch (f)
    {
        case 1:
            scanf("%d",&e);
            push(e);
             break;
        case 0:
            d=pop();
            if(d!=0) // @@ [This incorrectly suppresses output when pop() returns 0. The value 0 is a valid integer that can be pushed and popped. The program should output all popped values, including 0. Also, pop() returns 0 in error case due to missing return, compounding the issue.]
            printf("%d ",d );
             break;
        case -1:
             break; // @@ [This does not exit the program. It should return 0 or break out of the loop and terminate. As written, after reading -1, the loop continues waiting for more input, violating the spec which says -1 ends operations.]
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
    return 0; // @@ [This function always returns 0 regardless of stack state. Though unused in main, it's logically incorrect. However, the critical issue is in pop(): when stack is empty, error() is called but no value is returned, leading to undefined behavior. The function must return an int in all paths.]
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
             error("error "); // @@ [After printing "error ", the function does not return a value, but the function signature requires returning an int. This leads to undefined behavior. Additionally, the caller (main) checks if returned value != 0, which misinterprets both actual zero pops and error cases.]
      else
        {
            int a=s[top];
            s[top]=0;
            top--;
            return a;
        }    //出栈成功  
}