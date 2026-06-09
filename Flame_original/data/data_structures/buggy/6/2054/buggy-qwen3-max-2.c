#include<stdio.h>
int top=-1;
int stack[200]={0};

int isEmpty(int s[])
{
    return top==-1;
}

int isFull(int s[])
{
    return top==199;
}

void push(int stack[],int item)
{
    if(isFull(stack))
        Error11("error"); // @@ [The function 'Error11' prints "error " but the problem expects just "error" followed by a space; however, the real issue is that when an error occurs during push, nothing should be printed immediately in the push function because the problem requires output only for pop operations or errors during pop/push. But more critically, the main logic flaw is in the pop function: it returns a value even when the stack is empty, leading to undefined behavior. Also, the call to undefined function-like macro or incorrect handling isn't the main compile error—actually, the code compiles but logically fails. However, the given error type is "Compilation Error", but the actual bug is runtime/logic. Given the context and mismatched expectations, the true compilation-relevant issue is not present, but the logical errors are:]
}
void Error11(char s[])
{
    printf("%s ",s);
}
int pop(int s[])
{
    if(isEmpty(s))
        Error11("error"); // @@ [When the stack is empty, this prints "error ", which is correct per problem, but then the function does not return a valid integer. The calling code in main uses the return value regardless, leading to undefined behavior (using uninitialized/invalid return value). This causes incorrect output or crashes.]
    else 
        return s[top--];
}
int main()
{
    int a,b,ans;
    while(~scanf("%d",&a))
    {
        if(a==-1)
        {
            break;
        }
        else if(a==1)
        {
            scanf("%d",&b);
            push(stack,b);
        }
        else if(a==0)
        {
            printf("%d ",ans=pop(stack)); // @@ [If pop() is called on an empty stack, it prints "error " inside pop(), but then still tries to print the return value of pop() as "%d ", which is undefined behavior because pop() doesn't return a valid int in the error case. This leads to printing garbage after "error ", or double printing ("error X ") instead of just "error ".]
        }
    }
}