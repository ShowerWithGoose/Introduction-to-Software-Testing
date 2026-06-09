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
    top=-1;//初始化堆栈 @@ [The parameter 'top' is passed by value, so modifying it inside the function does not affect the caller's variable. This results in 'top' remaining uninitialized in main().]
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
            if(s[i].op <100)//堆栈不满完成操作 @@ [This condition checks s[i].op < 100, which is always true since op is 1 here. It should check if the stack is full using 'fulls(top)' instead.]
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
                    printf("error "); @@ [Printing "error" when popped item is 0 is incorrect. The problem does not treat 0 as an error; only underflow/overflow are errors.]
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
    INITIALS(top); @@ [The function INITIALS does not modify the local 'top' variable because it's passed by value. Thus, 'top' remains uninitialized (garbage value).]
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
    push(STACK, top, s, item); @@ [The 'top' variable passed here is uninitialized due to the earlier pass-by-value issue, leading to undefined behavior. Also, 'push' processes all operations but uses a local copy of 'top', so changes don't persist correctly.]
    return 0;
}