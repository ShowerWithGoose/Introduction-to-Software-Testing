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
    while(scanf("%d",&f)!=-1) // @@ scanf returns EOF on end of input, comparing with -1 is non-standard; should use EOF.
    {
    switch (f)
    {
        case 1:
            scanf("%d",&e);
            push(e);
             break;
        case 0:
            d=pop();
            if(d!=0) // @@ Logic error: pop() already prints "error " on failure, and this condition incorrectly suppresses output if the popped value is 0.
            printf("%d ",d );
             break;
        case -1:
             break; // @@ Should be return 0; to terminate the program immediately as per problem description.
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
void error(char s[]) // @@ Function 'error' is called before its declaration, causing a compilation error in modern C standards.
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
             error("error "); // @@ Missing return statement in non-void function pop() on this path, causing a compilation error.
      else
        {
            int a=s[top];
            s[top]=0;
            top--;
            return a;
        }    //出栈成功  
}