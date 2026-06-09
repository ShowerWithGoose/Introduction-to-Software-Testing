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
int main()
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
} @@ [The compilation error "undefined reference to `main'" typically indicates that the linker cannot find the main function. However, main is present. This error in the test environment likely stems from an external issue (e.g., file not saved properly, incorrect compilation command), but since the problem asks to annotate based on provided info and the code appears syntactically correct, no actual code line is at fault. Yet, the error message suggests the system didn't recognize main, which may imply a hidden issue like non-standard characters or encoding. Given constraints, we annotate the closing brace of main as the last possible location where linkage could be affected, though this is unconventional.]