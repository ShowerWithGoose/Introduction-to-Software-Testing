#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct sum{
    int op;//操作 
    int summ;//插入数值 
}SUM;
SUM s[1008];
void INITIALS(int top) // @@ Error: 'top' is passed by value, so modifications inside the function do not affect the 'top' variable in main.
{
    top=-1;//初始化堆栈  // @@ Error: This only modifies the local parameter 'top', leaving 'top' in main uninitialized.
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
void push(int STACK[], int top, struct sum s[], int item) // @@ Error: 'top' is passed by value, so increments/decrements inside this function will not be reflected in main.
{
    int i=0;
    while(1)
    {
        item=0;
        if(s[i].op ==1)//插入（进栈） 
        {
            if(s[i].op <100)//堆栈不满完成操作  // @@ Error: Checks the operation code 's[i].op' instead of checking if the stack is full (e.g., using fulls(top) or top < MAXSIZE-1).
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
                if(item==0) // @@ Error: Incorrectly treats a popped value of 0 as an error. The problem states pushed values are not 0, 1, or -1, but even if 0 is popped, it should be printed normally.
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
    INITIALS(top); // @@ Error: 'top' is uninitialized before passing to INITIALS, and INITIALS cannot modify it due to pass-by-value.
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
    push(STACK, top, s, item); // @@ Error: Passes uninitialized 'top' and 'item' by value. Changes to 'top' inside push are lost, and 'item' is unused/incorrectly passed.
    return 0;
}