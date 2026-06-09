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
    while(scanf("%d",&f)!=-1) // @@ [The loop condition should check for EOF or the termination condition properly. The problem states that -1 ends the operations, but the loop continues even after reading -1 because it only breaks out of the switch, not the loop. Also, scanf returns the number of successfully read items, so comparing to -1 is incorrect; it should compare to EOF or handle -1 inside the loop to break.]
    {
    switch (f)
    {
        case 1:
            scanf("%d",&e);
            push(e);
             break;
        case 0:
            d=pop();
            if(d!=0) // @@ [This condition incorrectly suppresses printing when pop() returns 0. However, 0 is a valid integer that can be pushed and popped. The program should output every popped value, including 0. Additionally, when an error occurs in pop(), the function prints "error " but still returns an undefined value (since no return is specified in the error path), leading to undefined behavior.]
            printf("%d ",d );
             break;
        case -1:
             break; // @@ [This break only exits the switch, not the while loop. The program should terminate immediately upon reading -1, but instead it continues reading more input. This causes the program to not stop at -1 as required.]
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
    return 0; // @@ [This function always returns 0 regardless of the actual stack top. Though unused in main, it's logically incorrect. However, since it's not used, this may not directly cause the observed failure.]
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
             error("error "); // @@ [When the stack is empty, this prints "error ", but the function does not return any value in this path, causing undefined behavior when the caller (main) tries to use the return value. The function must return a value in all paths, but more importantly, the design of returning a value and printing errors separately is flawed. The reference program prints directly in pop(), which avoids this issue.]
      else
        {
            int a=s[top];
            s[top]=0;
            top--;
            return a;
        }    //出栈成功  
} // @@ [Missing return statement for the error case in pop(). This leads to undefined behavior when popping from an empty stack because the function reaches the end without returning a value, yet main assigns its result to 'd'.]