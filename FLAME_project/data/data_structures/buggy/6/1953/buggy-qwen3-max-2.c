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
             break;
        case -1:
             break;
        default:
             break;
    }
    if(f == -1) break; // @@ [The loop does not break immediately when -1 is read, causing extra iterations or undefined behavior. The 'break' inside switch only exits the switch, not the while loop.]
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
    return 0; // @@ [This function always returns 0 and is unused, but more critically, the pop() function returns 0 on error, which conflicts with valid data value 0. However, the real issue is in main's handling of pop return value.]
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
      return 0; // @@ [When the stack is empty, this function prints "error " but then implicitly returns 0 (due to missing explicit return after error). In main, this 0 is interpreted as a valid popped value and skipped due to 'if(d!=0)', causing missing "error " output for empty pop. Also, returning 0 conflates error state with valid data.]
}