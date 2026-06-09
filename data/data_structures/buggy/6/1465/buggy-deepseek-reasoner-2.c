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
    scanf("&d",&n); // @@ [Wrong format specifier; should be "%d", causing undefined behavior]
    printf("%d ",n); // @@ [Prints input number which is not part of required output; should only print popped elements or "error"]
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
    printf("%d ",Stack[top--]); // @@ [When stack is empty, still prints top and decrements top, leading to undefined behavior; should return after printing "error"]
}

void push(int A[],int a)
{
    if(top==99)
    {
        printf("error ");
    }
    Stack[++top]=a; // @@ [When stack is full, still increments top beyond bounds, causing overflow; should not execute push after printing "error"]
}