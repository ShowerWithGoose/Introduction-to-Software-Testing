#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 100

int sta[100], top;
void init()
{
    top = -1;
}
void err()
{
    printf("error ");
    //exit(-1);
}
int isEmpty()
{
    return top == -1;
}
int isFull()
{
    return top == MAXSIZE - 1;
}
void push(int x)
{
    if(isFull()) err();
    else sta[++top] = x;
}
void pop()
{
    if(isEmpty()) err();
    else printf("%d ", sta[top--]);
}
int main() @@ [The linker reports "undefined reference to `main'". This indicates that the function name is likely misspelled (e.g., "mian") or the function definition is missing. Ensure the function is correctly named "main".]
{
    init();
    int op;
    while(1)
    {
        scanf("%d", &op);
        if(op == -1)
        {
            break;
        }
        else if(op == 0)
        {
            pop();
        }
        else if(op == 1)
        {
            int x;
            scanf("%d", &x);
            push(x);
        }
    }

    return 0;
}