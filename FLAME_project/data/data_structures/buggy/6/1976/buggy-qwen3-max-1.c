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
            pop(stack); // @@ [The pop function may print "error " but still returns undefined value when stack is empty. Also, after popping, accessing stack[top+1] is incorrect because top has already been decremented in pop(), and if the stack was empty, top+1 is invalid. Moreover, even when pop succeeds, this prints the popped value twice: once inside pop() (which it doesn't) — actually, pop() doesn't print on success, but main() prints stack[top+1], which is the just-popped value. However, if pop() printed "error ", then main() still prints an integer, causing extra output like the erroneous second '5'.]
            printf("%d ",stack[top+1]); // @@ [This line always prints an integer even after an error. When the stack is empty, pop() prints "error ", but then this line accesses stack[top+1] where top is -1, so stack[0] is printed (which is leftover from previous operations, e.g., 5), causing the wrong extra '5' in output.]
        }
        else
            break;
    }
    return 0;
}