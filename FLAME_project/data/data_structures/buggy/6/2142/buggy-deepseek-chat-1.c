#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct sum{
    int op;//操作 
    int summ;//插入数值 
}SUM;
SUM s[1008];
void INITIALS(int top) // @@ [Error: top is passed by value, so the initialization does not affect the top variable in main. Should pass by reference or use a global variable.]
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
void push(int STACK[], int top, struct sum s[], int item) // @@ [Error: top is passed by value, so modifications to top inside push do not affect the top in main. Also, item is passed but not used correctly; the function reuses item as a local variable.]
{
    int i=0;
    while(1)
    {
        item=0; // @@ [Error: This overwrites the parameter item, which is unnecessary and confusing.]
        if(s[i].op ==1)//插入（进栈） 
        {
            if(s[i].op <100) // @@ [Error: This condition is always true because s[i].op is 1, so it does not check stack capacity correctly. Should check if top < MAXSIZE-1.]
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
                if(item==0) // @@ [Error: This condition incorrectly prints "error " when the popped value is 0, but the problem only requires "error" for invalid operations, not for popping a 0 value.]
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
    INITIALS(top); // @@ [Error: top is uninitialized here, and INITIALS does not modify it, so top remains garbage.]
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
    push(STACK, top, s, item); // @@ [Error: top is uninitialized, and item is uninitialized. The function push does not return the updated top, so the stack state is lost.]
    return 0;
}