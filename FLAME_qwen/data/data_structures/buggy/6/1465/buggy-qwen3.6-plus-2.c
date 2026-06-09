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
    scanf("&d",&n); // @@ Invalid format specifier "&d", should be "%d"
    printf("%d ",n); // @@ Incorrectly prints input n; should only output popped elements or "error"
        /*int a,n; // @@ Essential stack operation logic is incorrectly commented out
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
        else */if(n==-1) // @@ Comment block ends here, leaving only termination check active; push/pop logic is disabled
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
    printf("%d ",Stack[top--]); // @@ Executes unconditionally; should be in an else block to avoid invalid access when stack is empty
}

void push(int A[],int a)
{
    if(top==99)
    {
        printf("error ");
    }
    Stack[++top]=a; // @@ Executes unconditionally; should be in an else block to avoid overflow when stack is full
}