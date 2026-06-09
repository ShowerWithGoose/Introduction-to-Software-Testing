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
    scanf("&d",&n); // @@ [Error: incorrect format specifier "&d" should be "%d", causing no input to be read.]
    printf("%d ",n); // @@ [Error: prints operation code unnecessarily; should not be in output.]
        /*int a,n; // @@ [Error: This comment block disables the required push/pop logic, so no operations are performed.]
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
    printf("%d ",Stack[top--]); // @@ [Error: Should not attempt to pop when stack empty; after printing error, it still pops leading to undefined behavior.]
}

void push(int A[],int a)
{
    if(top==99)
    {
        printf("error ");
    }
    Stack[++top]=a; // @@ [Error: Should not push when stack full; after printing error, it still pushes leading to overflow.]
}