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
    top=-1;//初始化堆栈 // @@ [The parameter 'top' is passed by value, so modifying it here does not affect the 'top' variable in main. This leaves 'top' uninitialized in main.]
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
            if(s[i].op <100)//堆栈不满完成操作 // @@ [This condition checks if the operation code is less than 100, which is always true for valid inputs (1). It should check if the stack is full using the 'top' variable and MAXSIZE, e.g., top < MAXSIZE - 1.]
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
                if(item==0) // @@ [This check incorrectly prints "error " if the popped value is 0. The problem states that pushed integers are not 1, 0, or -1, but even if they were, popping a valid element should just print the element. This logic corrupts the output for valid pops if the value happens to be 0, or adds extra error messages.]
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
    int top; // @@ [Variable 'top' is declared but not initialized. Since INITIALS fails to update it due to pass-by-value, 'top' contains garbage value.]
    int i=0;
    INITIALS(top);
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
    push(STACK, top, s, item); // @@ ['top' is passed by value to push. Even if push modified its local copy of top, the changes would not persist, but more importantly, the initial garbage value is used. Also, the logic inside push is flawed as noted above.]
    return 0;
}