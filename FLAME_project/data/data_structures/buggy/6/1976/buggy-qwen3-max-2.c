#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
int stack[100];
int top=-1;
int isempty()
{
    return top==-1;
}
int isfull()
{
    return top==99;
}
void push(int s[],int item)
{
    if(isfull())
        printf("error ");
    else
        s[++top]=item;
}
int pop(int s[])
{
    if(isempty())
        printf("error ");
    else
        return s[top--];
}
int main()
{
    int m,n;
    while(scanf("%d",&m)!=-1)
    {
        if(m==1)
        {
            scanf("%d",&n);
            push(stack,n);
        }
        else if(m==0)
        {
            pop(stack); // @@ [The pop function already prints "error " when the stack is empty, but in the non-error case, it returns the popped value without printing it. However, in main(), after calling pop(stack), the code unconditionally prints stack[top+1], which is incorrect because: (1) if pop() printed "error ", then printing stack[top+1] adds an extra wrong number; (2) even when successful, pop() has already decremented top, so stack[top+1] is the popped value, but this approach fails when pop() printed "error " since top wasn't changed and stack[top+1] may be garbage or previous value. The correct approach is to handle printing only inside main() based on whether the stack is empty, not inside pop().]
            printf("%d ",stack[top+1]); // @@ [This line causes the first popped value '5' to be printed again as the second output because after the first pop (which succeeds and returns 5), top becomes -1, then stack[top+1] is stack[0] which is still 5. Then the next pop operation finds the stack empty and prints "error ", but this line still prints stack[0] = 5 again, leading to the erroneous second '5' in the output.]
        }
        else
            break;
    }
    return 0;
}