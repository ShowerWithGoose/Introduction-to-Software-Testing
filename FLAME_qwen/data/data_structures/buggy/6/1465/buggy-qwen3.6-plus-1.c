#include<stdio.h>
void pop(int A[]);
void push(int A[],int a);
int Stack[100];
int top = -1;
int main()
{
    while(1)
    {
    int n;
    scanf("&d",&n); // @@ Format specifier typo: "&d" should be "%d" to correctly read an integer.
    printf("%d ",n); // @@ Incorrect output: prints the operation code instead of the required popped elements or error messages.
        /*int a,n;
        scanf("%d",&n);
        if(n==1)
        {
            scanf("%d",&a);
            push(Stack,a);
        }
        else if(n==0)
        {
            pop(Stack);
        }
        else */if(n==-1) // @@ Logical error: the code handling push (1) and pop (0) is commented out, so only the termination condition (-1) is processed.
        {
            break;
        }
    }
    return 0;
}

void pop(int A[])
{
    if(top==-1)
    {
        printf("error ");
    }
    printf("%d ",Stack[top--]); // @@ Missing else clause: when stack is empty, it prints "error " but still executes Stack[top--], causing out-of-bounds access.
}

void push(int A[],int a)
{
    if(top==99)
    {
        printf("error ");
    }
    Stack[++top]=a; // @@ Missing else clause: when stack is full, it prints "error " but still increments top and assigns a value, causing overflow.
}