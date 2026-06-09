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
    scanf("&d",&n); // @@ [Incorrect format specifier: "&d" should be "%d"]
    printf("%d ",n); // @@ [Unnecessary print that alters output; also executes even for -1]
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
    printf("%d ",Stack[top--]); // @@ [Always prints popped value even when stack is empty, causing undefined behavior and wrong output]
}

void push(int A[],int a)
{
    if(top==99)
    {
        printf("error ");
    }
    Stack[++top]=a; // @@ [Performs push even when stack is full, leading to buffer overflow]
}