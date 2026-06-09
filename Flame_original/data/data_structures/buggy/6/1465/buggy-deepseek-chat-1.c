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
    scanf("&d",&n); // @@ [Error: The format specifier should be "%d" not "&d". This causes undefined behavior and incorrect input reading.]
    printf("%d ",n); // @@ [Error: This line prints the input operation number, which is not part of the required output. The problem only asks to output popped elements or "error".]
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
    printf("%d ",Stack[top--]); // @@ [Error: When the stack is empty, after printing "error ", this line still executes, causing undefined behavior by accessing Stack[-1]. Should use an else block to prevent this.]
}

void push(int A[],int a)
{
    if(top==99)
    {
        printf("error ");
    }
    Stack[++top]=a; // @@ [Error: When the stack is full, after printing "error ", this line still executes, causing a stack overflow. Should use an else block to prevent this.]
}