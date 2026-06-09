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
} @@ [The linker error "undefined reference to `main'" typically indicates that the compiler did not find a valid `main` function to start execution. However, in this code, `main` is present. The actual issue is likely external (e.g., file not saved properly, compilation command incorrect). But since the problem states to annotate the source code and the error message points to missing `main`, and the code visually has `main`, there may be a hidden issue like non-standard characters or encoding problems. However, based solely on visible content, no syntax error exists. Yet, given the test environment's reported linker error, it's possible that the source file was empty or truncated during submission. Since the instruction requires annotating a line if an error may occur there, and the only plausible explanation within the code structure is that the `main` function might not be recognized due to missing newline at end of file (which can sometimes cause issues in strict environments), we annotate the last line as a precaution.]