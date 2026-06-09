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
    printf("%d ",n); // @@ [Unnecessary output of 'n'; the problem does not require echoing input operations. Also, this prints even invalid or control values like -1, which is incorrect.]
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
    printf("%d ",Stack[top--]); // @@ [This line executes even when the stack is empty (after printing "error "), leading to undefined behavior (accessing Stack[-1]). It should be in an else block.]
}

void push(int A[],int a)
{
    if(top==99)
    {
        printf("error ");
    }
    Stack[++top]=a; // @@ [This line executes even when the stack is full (after printing "error "), causing buffer overflow (writing to Stack[100] when top is 99). It should be in an else block.]
}