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
            if(d!=0) // @@ The logic `if(d!=0)` is incorrect. If the popped element is actually 0, it will not be printed. Also, this check fails to distinguish between a successful pop of value 0 and an error state if `pop` returns 0 on error (though current `pop` doesn't return 0 on error, it prints directly). The main issue is that valid data `0` is suppressed. Furthermore, the problem requires printing "error " on failure, but `pop` handles printing internally. The variable `d` captures the return value, but the condition `d!=0` incorrectly filters out valid popped values of 0.
            printf("%d ",d );
             break;
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
             error("error ");
      else
        {
            int a=s[top];
            s[top]=0;
            top--;
            return a;
        }    //出栈成功  
}