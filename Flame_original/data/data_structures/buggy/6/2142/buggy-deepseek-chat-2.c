#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct sum{
    int op;//操作 
    int summ;//插入数值 
}SUM;
SUM s[1008];
void INITIALS(int top)
{
    top=-1;//初始化堆栈 
}
int fulls(int top)
{
    if(top==MAXSIZE-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int emptys(int top)
{
    if(top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(int STACK[], int top, struct sum s[], int item)
{
    int i=0;
    while(1)
    {
        item=0;
        if(s[i].op ==1)//插入（进栈） 
        {
            if(s[i].op <100)//堆栈不满完成操作 
@@ // @@ [Error: The condition `s[i].op < 100` is incorrect; it should check if the stack is not full using `fulls(top)`, not compare the operation code to 100. This will always be true when op is 1, leading to incorrect behavior.]
            {
                top++;
                STACK[top]=s[i].summ ;
            }
            else//堆栈已满报错 
            {
                printf("error ");
            }
        }
        else if(s[i].op ==0)//删除（退栈） 
        {
            if(top==-1)//堆栈已空报错 
            {
                printf("error ");
            }
            else//堆栈未空完成操作 
            {
                item =STACK[top];
                top--;
                if(item==0)
                {
                    printf("error ");
                }
                printf("%d ", item );
            }
        }
        else if(s[i].op  ==-1)
        {
            break;
        }
        i++;
    }
}
int main()
{
    int STACK[MAXSIZE], item;
    int top;
    int i=0;
    INITIALS(top);
@@ // @@ [Error: `INITIALS(top)` passes `top` by value, so the initialization `top = -1` does not affect the `top` in `main()`. The stack top remains uninitialized, causing undefined behavior.]
    while(1)
    {
        scanf("%d", &s[i].op );//输入 
        if(s[i].op ==1)
        {
            scanf("%d", &s[i].summ );
            //printf("%d ", s[i].summ );
        }
        else if(s[i].op ==0)
        {
            
        }
        else if(s[i].op  ==-1)
        {
            break;
        }
        //printf("%d ", s[i].op );
        i++;
    }
    push(STACK, top, s, item);
@@ // @@ [Error: `push` function receives `top` by value, so any modifications to `top` inside `push` (like `top++` and `top--`) do not affect the `top` in `main()`. The stack operations will not maintain a correct stack state.]
    return 0;
}