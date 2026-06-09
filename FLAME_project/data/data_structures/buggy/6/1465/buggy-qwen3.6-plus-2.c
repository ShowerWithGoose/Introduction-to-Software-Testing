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
    scanf("&d",&n); // @@ The format string "&d" is incorrect; it should be "%d". This causes scanf to fail to read the integer properly, likely leading to an infinite loop or undefined behavior, resulting in Time Limit Exceeded. Additionally, the logic inside the loop is flawed as it prints 'n' immediately instead of performing stack operations.
    printf("%d ",n);
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
        else */if(n==-1)
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
    printf("%d ",Stack[top--]); // @@ This line executes regardless of whether the stack is empty. If top is -1, it accesses Stack[-1], which is out of bounds. It should be inside an else block or guarded by the error check.
}

void push(int A[],int a)
{
    if(top==99)
    {
        printf("error ");
    }
    Stack[++top]=a; // @@ This line executes regardless of whether the stack is full. If top is 99, it increments to 100 and accesses Stack[100], which is out of bounds for an array of size 100. It should be inside an else block or guarded by the error check.
}