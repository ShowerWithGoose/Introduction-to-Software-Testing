#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
typedef struct bond{
    int a;
    struct bond *next;
}SB;
SB *top; 
void intbond()
{
top=NULL;
}//初始化栈 
int empty()
{
    return top==NULL;
}//检验是否栈空 
void push(int x) // @@ 错误：缺少栈满检查（最大容量100），若栈满应输出"error "并不执行入栈操作
{
    SB *p;
    if((p=(SB*)malloc(sizeof(SB)))==NULL)
    printf("No memory!");
    else{
        p->a=x;
        p->next=top;
        top=p;
    }
}//入栈 
int pop()
{
    SB *p;
    int x;
    if(empty())
    printf("error "); // @@ 错误：栈空时没有return语句，函数返回int却无返回值，导致未定义行为；且main中printf会打印该未定义值，造成输出多余整数
    else
    {
        p=top;
        x=top->a;
        top=top->next;
        free(p);
        return x;
    }
}//出栈 
int main()
{
intbond();
int m,n;
while(~scanf("%d",&m))
{
    if(m==-1)
    break;
    else if(m==0)
    {
        printf("%d ",pop()); // @@ 错误：当栈空时，pop()已打印"error "，但此处又打印pop()的返回值（未定义），导致输出格式错误
    }
    else
    {
        scanf("%d",&n);
        push(n);
    }
}
 return 0;
}