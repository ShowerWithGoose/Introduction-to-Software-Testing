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
    top=-1;//初始化堆栈 @@ [Passing 'top' by value means the change inside the function does not affect the caller's variable. Should pass by pointer or return the value.]
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
        item=0; @@ [Unnecessarily resetting 'item' to 0 at start of each loop iteration, overwriting any passed-in value and causing incorrect pop output.]
        if(s[i].op ==1)//插入（进栈） 
        {
            if(s[i].op <100)//堆栈不满完成操作 @@ [Incorrect condition: should check if stack is full using 'top', not compare operation code with 100.]
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
                if(item==0) @@ [Incorrectly treating popped value 0 as an error. Zero is a valid integer to store and pop.]
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
    INITIALS(top); @@ [The function INITIALS does not modify the local 'top' because it's passed by value. 'top' remains uninitialized.]
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
    push(STACK, top, s, item); @@ [Passing 'top' by value to push(), so modifications inside push() won't reflect in main. Also, 'top' was never properly initialized.]
    return 0;
}