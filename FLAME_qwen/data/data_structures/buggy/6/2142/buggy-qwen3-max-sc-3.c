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
    top=-1;//初始化堆栈 @@ [The function parameter 'top' is passed by value, so modifying it here does not affect the 'top' variable in main(). This leads to uninitialized stack behavior.]
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
        item=0; @@ [This line resets 'item' to 0 on every iteration, which is unnecessary and overwrites any previous value. However, the real issue is that 'top' is passed by value, so changes to 'top' inside this function do not persist.]
        if(s[i].op ==1)//插入（进栈） 
        {
            if(s[i].op <100)//堆栈不满完成操作 @@ [This condition checks s[i].op < 100, which is always true since op is 1 for push. It should check if the stack is full using 'fulls(top)' instead.]
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
                if(item==0) @@ [This condition incorrectly treats a popped value of 0 as an error. But 0 is a valid integer that can be pushed and popped. The error should only occur when popping from an empty stack.]
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
    INITIALS(top); @@ [Because 'top' is passed by value to INITIALS, the local 'top' in main remains uninitialized (garbage value), leading to undefined behavior.]
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
    push(STACK, top, s, item); @@ [The 'top' variable is uninitialized (due to pass-by-value issue), and all modifications to 'top' inside 'push' are lost because it's also passed by value. This causes incorrect stack state tracking.]
    return 0;
}