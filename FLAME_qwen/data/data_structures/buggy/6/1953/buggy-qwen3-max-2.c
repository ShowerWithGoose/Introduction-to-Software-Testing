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
    while(scanf("%d",&f)!=-1) // @@ [The loop condition should check for EOF, not -1. scanf returns EOF on end-of-file or error, not -1. This causes the program to not terminate properly on -1 input and may lead to infinite loop or undefined behavior.]
    {
    switch (f)
    {
        case 1:
            scanf("%d",&e);
            push(e);
             break;
        case 0:
            d=pop();
            if(d!=0) // @@ [This condition incorrectly suppresses output when pop() returns 0. If 0 is a valid popped value, it won't be printed. Also, pop() returns 0 in error case due to missing return, leading to wrong logic.]
            printf("%d ",d );
             break;
        case -1:
             break; // @@ [This break only exits the switch, not the loop. The program continues reading input instead of terminating immediately upon -1. Should use return 0; or break out of loop.]
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
    return 0; // @@ [This function always returns 0 regardless of stack state. Though unused in main, it's logically incorrect. However, the critical issue is in pop(): when stack is empty, error() is called but no value is returned, leading to undefined behavior.]
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
             error("error "); // @@ [After printing "error ", the function does not return a value, but the caller expects an int. This leads to undefined behavior. Additionally, the main function checks if returned value != 0, which fails to handle actual zero values correctly.]
      else
        {
            int a=s[top];
            s[top]=0;
            top--;
            return a;
        }    //出栈成功  
}