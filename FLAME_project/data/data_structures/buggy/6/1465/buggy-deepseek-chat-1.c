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
    scanf("&d",&n); // @@ [Error: Incorrect format specifier. Should be "%d" instead of "&d". This causes scanf to fail, leading to infinite loop and Time Limit Exceeded.]
    printf("%d ",n); // @@ [Error: This line prints the operation code, which is not required by the problem. It also outputs extra spaces and numbers, causing output mismatch.]
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
    printf("%d ",Stack[top--]); // @@ [Error: Missing else statement. When stack is empty, it prints "error " and then also attempts to pop and print an invalid element, causing undefined behavior and incorrect output.]
}

void push(int A[],int a)
{
    if(top==99)
    {
        printf("error ");
    }
    Stack[++top]=a; // @@ [Error: Missing else statement. When stack is full, it prints "error " but still pushes the element, causing stack overflow and incorrect behavior.]
}