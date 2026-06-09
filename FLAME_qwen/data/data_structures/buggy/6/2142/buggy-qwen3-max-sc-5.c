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
    top=-1;//初始化堆栈 @@ [The function parameter 'top' is passed by value, so modifying it here does not affect the 'top' variable in main(). This leads to uninitialized or garbage value of 'top' in main().]
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
        item=0; // @@ [This resets 'item' to 0 at every iteration, which is unnecessary and causes incorrect output when popping a zero (it prints "error" even if zero was legitimately pushed).]
        if(s[i].op ==1)//插入（进栈） 
        {
            if(s[i].op <100)//堆栈不满完成操作 @@ [This condition checks s[i].op < 100, but should check if the stack is full using 'top'. The logic is completely wrong: s[i].op is always 1 here, so this condition is always true. Should use fulls(top).]
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
                if(item==0) // @@ [This incorrectly treats popped value 0 as an error. Zero is a valid integer to push and pop. This condition should be removed.]
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
    INITIALS(top); // @@ [Passing 'top' by value means the initialization inside INITIALS has no effect. 'top' remains uninitialized (garbage value).]
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
    push(STACK, top, s, item); // @@ [Passing 'top' by value again means any changes to 'top' inside push() won't persist, but more critically, 'top' is uninitialized here due to earlier bug, leading to undefined behavior. Also, the entire design of reading all input first then processing is acceptable, but the implementation of push() is flawed as noted above.]
    return 0;
}