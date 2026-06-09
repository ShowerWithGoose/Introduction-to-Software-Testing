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
    scanf("&d",&n); // @@ [Incorrect format specifier: "&d" should be "%d", causing undefined behavior and likely infinite loop due to failed input parsing]
    printf("%d ",n); // @@ [Unnecessary output of operation code 'n', which is not part of expected output; also contributes to wrong output format]
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
    printf("%d ",Stack[top--]); // @@ [Always executes even when stack is empty, leading to undefined behavior (accessing Stack[-1]) after printing "error "]
}

void push(int A[],int a)
{
    if(top==99)
    {
        printf("error ");
    }
    Stack[++top]=a; // @@ [Executes even when stack is full, leading to buffer overflow (writing to Stack[100] when top==99)]
}