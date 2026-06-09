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
        Error11("error"); // @@ [Error11 is not a standard function; this will cause a compilation error because Error11 is used before being declared/defined in a way the compiler can resolve at this point (though it's defined later, in C this may still be allowed if no prototype exists, but more critically, in pop() the same function is used without printing the popped value correctly)]
    else 
        stack[++top]=item;
}
void Error11(char s[])
{
    printf("%s ",s);
}
int pop(int s[])
{
    if(isEmpty(s))
        Error11("error"); // @@ [When the stack is empty, "error " is printed via Error11, but the function still returns an undefined value (since there's no return statement in this branch). The calling code in main() then prints that undefined return value as "%d ", leading to undefined behavior and incorrect output. Also, the problem requires that on error, only "error " is printed — but here, main() always prints the return value of pop(), even when it's an error.]
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
            printf("%d ",ans=pop(stack)); // @@ [This line always prints the return value of pop() as an integer followed by a space. However, when pop() encounters an empty stack, it prints "error " via Error11 but still returns an undefined value (due to missing return in the error branch), which is then printed as a garbage integer. This leads to output like "error <garbage> " instead of just "error ". Additionally, even if pop() returned nothing on error, this design forces printing a number, which violates the spec. The printing of popped values or errors should be handled entirely inside pop(), not in main().]
        }
    }
}