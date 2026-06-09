#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MAXSIZE 100
typedef int ElemType;
ElemType stack[MAXSIZE];
int top;
void  initStack()
{
    top = -1;
}
int  isEmpty()
{
    return top == -1;
}
int isFull()
{
    return top == MAXSIZE-1;
}
void  push(ElemType s[], ElemType item) {
    if (isFull())
        printf("error ");
    else
        s[++top] = item;
}
ElemType pop(ElemType s[])
{
    if (isEmpty())
        printf("error ");
    else
        printf("%d ", s[top]); // @@ The logic for handling empty stack error and normal pop output is flawed. When the stack is empty, it prints "error " but then proceeds to execute 'return s[top--]', which accesses invalid memory (index -1) and causes undefined behavior. Furthermore, even when not empty, the structure implies the print happens, but the return value is unused in main, making the function's return type misleading if intended to signal error state via return value like the reference. However, the critical bug here is that when isEmpty() is true, it prints "error " but falls through to the return statement below because there are no braces enclosing the else block's statements properly relative to the if/else logic flow intended or missing braces for the else block containing both print and return. Actually, looking closely: if isEmpty() is true, it prints "error ". Then it executes 'return s[top--]'. This is a logical error. If isEmpty() is false, it prints the element, then returns s[top--]. The main issue is that when isEmpty() is true, we should NOT access s[top--]. We need braces to group the statements in the else block, or handle the error case by returning early.
        return s[top--]; // @@ This line is executed regardless of whether the stack was empty or not, due to missing braces around the else block. If the stack was empty, 'top' is -1, so s[top--] accesses s[-1], which is out of bounds. Additionally, if the stack was not empty, it prints the correct value but then decrements top again in the return, effectively popping twice or accessing the wrong index if the print used s[top] before decrement. Wait, 's[top]' in printf uses current top. 's[top--]' in return uses current top then decrements. So if not empty: prints s[top], returns s[top] and decrements top. This part is logically okay for the non-empty case IF the else block was properly braced. But without braces, the 'return' is outside the else. So: if empty -> print error -> return s[-1] (CRASH/ERROR). If not empty -> print s[top] -> return s[top] and decrement. The crash on empty pop is the primary error.
}

int main() {
    initStack();
    int n, x;
    while (scanf("%d", &n)) {
        if (n == -1)break;
        else if (n == 1) {
            scanf("%d", &x);
            push(stack, x);
        }
        else if (n == 0)pop(stack);
    }
    return 0;
}