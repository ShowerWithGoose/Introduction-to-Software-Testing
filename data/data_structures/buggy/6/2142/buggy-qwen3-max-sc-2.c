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
    top=-1;//初始化堆栈 @@ [The parameter 'top' is passed by value, so modifying it inside the function does not affect the 'top' variable in main(). This leads to uninitialized or garbage value of 'top' in main().]
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
        item=0; @@ [Unnecessarily resetting 'item' to 0 at the start of each loop iteration, which overwrites any meaningful value. Also, 'item' is unused for push operations.]
        if(s[i].op ==1)//插入（进栈） 
        {
            if(s[i].op <100)//堆栈不满完成操作 @@ [Incorrect condition: should check if stack is full using 'top', not whether operation code is less than 100. This logic is completely wrong.]
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
                if(item==0) @@ [Incorrect error condition: popping a 0 is valid; only popping from empty stack is an error. This causes false "error" output when 0 is popped.]
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
    INITIALS(top); @@ [Calling INITIALS(top) does not initialize the local 'top' because it's passed by value. 'top' remains uninitialized (garbage value).]
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
    push(STACK, top, s, item); @@ [Passing 'top' by value to push(), so any changes to 'top' inside push() won't be reflected. Moreover, 'top' was never properly initialized in main(), leading to undefined behavior. Also, the entire logic of reading all input first and then processing in a separate function is unnecessarily complex and error-prone compared to processing on-the-fly.]
    return 0;
}