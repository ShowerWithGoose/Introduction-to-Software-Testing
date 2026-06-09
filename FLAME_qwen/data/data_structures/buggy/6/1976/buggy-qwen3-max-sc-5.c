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
        printf("error "); // @@ [When the stack is empty, this prints "error ", but then the function falls through and returns an undefined value. However, the main issue is in main(): after calling pop(), it unconditionally prints stack[top+1], which is invalid when pop() printed "error ".]
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
            pop(stack); // @@ [The pop function may print "error ", but then main() always prints stack[top+1] regardless. If the stack was empty, top is -1, so stack[top+1] is stack[0], which is undefined behavior and wrong output. Also, if pop succeeded, the popped value was already returned by pop(), but main() prints stack[top+1] which is the same value, but this approach fails when error occurs.]
            printf("%d ",stack[top+1]); // @@ [This line causes incorrect output: (1) When pop fails (stack empty), it still tries to print stack[0] as "error " was already printed, leading to extra wrong number; (2) Even when pop succeeds, it prints the value, but if multiple pops happen, top changes, and this access might be okay, but the logic is flawed because pop() doesn't print the value—it's printed here. However, the real bug is that when pop() encounters an empty stack, it prints "error ", and then this line prints an arbitrary value from stack[0], causing wrong output. The reference program prints the popped value inside pop(), but this program tries to print it in main(), which breaks error handling.]
        }
        else
            break;
    }
    return 0;
}