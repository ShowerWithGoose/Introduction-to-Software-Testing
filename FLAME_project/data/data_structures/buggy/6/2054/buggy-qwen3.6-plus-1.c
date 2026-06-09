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
        Error11("error");
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
        Error11("error");
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
            ans = pop(stack); // @@ The original code prints the return value of pop directly. However, pop returns an undefined/garbage value when the stack is empty (as it only calls Error11 and doesn't return a specific error code, or falls through). More importantly, when pop encounters an error, it prints "error " inside Error11. The main function then prints the return value of pop. If pop returns garbage or 0 (implicit return 0 in some compilers for non-void functions missing return), it prints that number after "error ". The expected output shows "error " alone. The logic should be: if pop fails, it handles printing. If it succeeds, main prints the value. But the current structure `printf("%d ",ans=pop(stack));` always prints a number. When pop fails, it prints "error " via Error11, but then main prints the return value of pop (which is likely garbage or 0) as a number. This results in "error 0 " or similar. To fix this, we need to check if the pop was successful before printing the number, or change pop to return a status. Given the constraint to not change structure significantly, the issue is that `pop` does not return a valid value on error, yet `main` prints whatever it returns. A common pattern is to have pop return a special value or use a flag. However, looking at the buggy output `5 error 6 ...`, the `6` is likely the garbage/return value printed after `error `. The correct behavior is to NOT print a number if an error occurred. Since `Error11` already prints "error ", `main` should not print the return value of `pop` if an error occurred. But `pop` is `int` and always returns something. The cleanest fix without changing signatures drastically is to check `isEmpty` in main before calling pop, or modify pop to return a specific error code like -1 and check it, but -1 is a valid stack element. 
            // Actually, looking closely at the provided "Buggy Output": `5 error 6 8 ...`. The `6` appears where the second pop (on empty stack) happens. The first pop returns 5. The second pop triggers Error11("error "), printing "error ". Then `printf("%d ", ans)` prints the return value of pop. In C, if a non-void function reaches the end without returning, the behavior is undefined. It seems it returned 6 (garbage). 
            // To fix: We should only print the result if the stack was not empty.
            // Let's refactor the logic slightly within the line constraints.
            // We can check isEmpty before popping.
            if (isEmpty(stack)) {
                Error11("error");
            } else {
                printf("%d ", pop(stack));
            }
        }
    }
}