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
            if(d!=0) // @@ [错误原因：当栈为空时，pop()函数会打印"error "并返回未定义的值（因为没有return语句），这里d可能为0或垃圾值，导致条件判断错误。应直接打印pop()的返回值，或修改pop()函数在空栈时返回特定值。]
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
             error("error "); // @@ [错误原因：当栈为空时，函数打印"error "但没有return语句，导致返回值未定义。调用者使用这个未定义的值进行判断，造成逻辑错误。应在打印错误后返回一个明确的值（如0），或修改调用逻辑。]
      else
        {
            int a=s[top];
            s[top]=0;
            top--;
            return a;
        }    //出栈成功  
}