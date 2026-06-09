#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct sum{
    int op;//操作 
    int summ;//插入数值 
}SUM;
SUM s[1008];
void INITIALS(int top) // @@ The parameter 'top' is passed by value, so modifying it here does not affect the 'top' variable in main. It should be passed by pointer or returned.
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
void push(int STACK[], int top, struct sum s[], int item) // @@ The parameter 'top' is passed by value. Modifications to 'top' inside this function (top++, top--) are local and do not update the stack state in the caller. Also, the logic iterates through all operations instead of processing them sequentially with a maintained state.
{
    int i=0;
    while(1)
    {
        item=0;
        if(s[i].op ==1)//插入（进栈） 
        {
            if(s[i].op <100)//堆栈不满完成操作  @@ The condition 's[i].op < 100' checks the operation code, not whether the stack is full. It should check if 'top < MAXSIZE - 1'.
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
                if(item==0) // @@ This check incorrectly prints "error " if the popped value is 0. The problem states values pushed are not 1, 0, or -1, but even if 0 was valid, printing error for a successful pop is wrong.
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
    int top; // @@ 'top' is uninitialized. Even if INITIALS worked, it wouldn't update this variable because it's passed by value in the buggy INITIALS.
    int i=0;
    INITIALS(top); // @@ As noted, this does not initialize 'top' in main.
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
    push(STACK, top, s, item); // @@ Calls the flawed push function which processes all stored operations at once with incorrect state management.
    return 0;
}