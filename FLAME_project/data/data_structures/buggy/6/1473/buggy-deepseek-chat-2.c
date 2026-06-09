#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h> 
#define Maxsize 100
typedef struct SqStack
{
    int data[Maxsize];
    int top;
}SqStack;
SqStack *S;
SqStack *InitStack()
{
    SqStack *S;
    S = (SqStack *)malloc(sizeof(struct SqStack));
    S -> top = -1;
    return S;
}
void push(SqStack *S, int x)
{
    if(S->top == Maxsize - 1)
    {
        printf("error ");
    }
    else
    {
        S->data[S->top] = x; // @@ Error: Should assign to S->data[S->top+1] or increment top first. Currently overwrites uninitialized data at index S->top (which is -1 initially) and then increments top, causing the first element to be stored at index -1.
        S->top++;        
    }
    
}
void pop(SqStack *S,int x) // @@ Error: The parameter 'x' is used incorrectly. It should not take an argument; the pop function should just pop the top element. The current implementation uses 'x' as an index offset, which is wrong.
{
    if(S -> top == -1)
    {
        printf("error ");
    }
    else
    {
        printf("%d ", S->data[x - 2]); // @@ Error: Uses 'x' (which is 'j' from main) as an index offset instead of using S->top. Should print S->data[S->top] before decrementing.
        S -> top--;
    }    
} 
void output(SqStack *S,int top)
{
    int i;
    for(i = top - 1;i >= 0;i --)
    {
        printf("%d ", S->data[i]);
    }
}
int main()
{
    int jud[200];
    int i = 0;
    for(i = 0;i <= 300;i ++) // @@ Error: Loop condition i <= 300 may cause buffer overflow since jud has size 200. Also, the loop reads into jud[i] before checking if jud[i-1] == -1, which is incorrect logic.
    {
        if(jud[i - 1] == -1) // @@ Error: Accesses jud[-1] when i=0, which is out of bounds. Should check after reading.
        {
            break;
        }
        else
            scanf("%d",&jud[i]);
        
    } 
    SqStack *S = InitStack();
    int x = i -1;
    int b[200];
    int j = 0;
    for(i = 0;i <= x;i ++)
    {    
        if(jud[i] == 0)
        {
            pop(S,j); // @@ Error: Passes 'j' as argument to pop, but pop uses it incorrectly as an index offset. Should just call pop(S) without j.
            j --;
            if(j < 0)
            {
                j = 0;
            }
        }
        if(jud[i] == -1)
        {
            break;
        }
        if(jud[i] == 1)
        {
            push(S,jud[i+1]);
            i++;
            j++;
        }
    }
    //output(S,j);
}