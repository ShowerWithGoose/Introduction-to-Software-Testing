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
    while(scanf("%d",&f)!=-1) // @@ [错误：应使用 != EOF 而不是 != -1，因为 scanf 返回的是成功读取的项目数，EOF 是文件结束标志，而 -1 是操作结束标志，但这里需要检测输入结束，应使用 != EOF]
    {
    switch (f)
    {
        case 1:
            scanf("%d",&e);
            push(e);
             break;
        case 0:
            d=pop();
            if(d!=0) // @@ [错误：pop() 函数在栈空时输出 "error " 但不返回值，导致 d 未定义，且栈空时不应打印任何值；应直接调用 pop() 并处理输出，而不是依赖返回值判断]
            printf("%d ",d );
             break;
        case -1:
             break; // @@ [错误：遇到 -1 时应结束程序，但这里只是 break 出 switch，导致程序继续循环，应使用 return 0 或 exit(0)]
        default:
             break;
    }
    }

} // @@ [错误：main 函数缺少 return 0; 语句，虽然某些编译器允许，但不符合标准]

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
             error("error "); // @@ [错误：函数声明返回 int，但在栈空时没有返回值，导致未定义行为；应返回一个特殊值（如 0）或修改函数设计]
      else
        {
            int a=s[top];
            s[top]=0;
            top--;
            return a;
        }    //出栈成功  
}