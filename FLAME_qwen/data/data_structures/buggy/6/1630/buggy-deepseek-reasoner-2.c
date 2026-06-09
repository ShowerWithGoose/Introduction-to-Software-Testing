#include<stdio.h>
#include<string.h>
#define MAXSIZE 100
int s[MAXSIZE];
int top = -1;
int isFull()
{
    return top == MAXSIZE - 1;
}
int isEmpty()
{
    return top == -1;
}
void initStack()
{
    top = -1;
}
void push(int s[], int item)
{
    if(isFull()) printf("error ");
    else s[++top] = item;
}
int pop(int s[])
{
    if (isEmpty()) printf("error "); // @@ [When stack is empty, this branch prints "error " but does not return a value. The function is declared to return int, so this path results in undefined behavior. Moreover, the caller expects a valid integer to print, leading to garbage output after "error ".]
    else return s[top--];
}
int main()
{
    int n,x;
    initStack();
    while(scanf("%d",&n)!=EOF )
    {
        if(n==-1) break;
        
        if(n==1)
        {
            scanf("%d",&x);
            push(s,x);
        }
        else if(n==0)
        {
            printf("%d ",pop(s)); // @@ [This line unconditionally prints the return value of pop(s). When the stack is empty, pop(s) prints "error " and returns an undefined value, causing an extra integer to be printed (e.g., "error 12345 " instead of only "error "). The output format requires only "error " in that case.]
        }
    }
    
}