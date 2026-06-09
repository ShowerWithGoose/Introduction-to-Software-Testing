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
    scanf("&d",&n); // @@ [Incorrect format specifier: "&d" should be "%d". This causes undefined behavior and likely input failure.]
    printf("%d ",n); // @@ [Unnecessary output of 'n' which is not part of the expected output; also, due to scanf error, 'n' may be uninitialized or incorrect.]
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
    printf("%d ",Stack[top--]); // @@ [This line executes even when stack is empty, leading to undefined behavior (accessing invalid memory) after printing "error ".]
}

void push(int A[],int a)
{
    if(top==99)
    {
        printf("error ");
    }
    Stack[++top]=a; // @@ [This line executes even when stack is full, causing buffer overflow beyond Stack[99].]
}