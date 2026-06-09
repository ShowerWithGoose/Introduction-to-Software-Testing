#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
    int stack[100] = { 0 };
    int top = -1;
    int option;
    do
    {
        scanf("%d", &option);
        if (option == -1)
            break;
        else if (option == 1)//执行入栈操作
        {
            int newnum;
            scanf("%d", &newnum);
            if (top == 99) // @@ Error: The stack capacity is 100 (indices 0-99), so top == 99 means the stack is full (top is the index of the last element). However, the condition should check if top == 99 before incrementing, but after incrementing top becomes 99, which is valid. The correct check should be if (top == 98) to prevent overflow, or if (top >= 99) to be safe. As written, when top is 99, the stack is actually full (since top is the index of the last element), but the condition allows pushing when top is 99, which would cause stack[++top] to access stack[100], out of bounds.
                printf("error ");
            else
                stack[++top] = newnum;
        }
        else if (option == 0)//执行出栈操作
        {
            if (top == -1) // @@ Error: This correctly checks for empty stack (top == -1 means no elements). However, when popping, the code does not decrement top after printing, so the element remains on the stack and subsequent pops will print the same element again. The missing line is: top--;
                printf("error ");
            else
                printf("%d ", stack[top]); // @@ Error: After printing, top should be decremented to remove the element from the stack. Missing: top--;
        }
    } while (option != -1);
    return 0;
}