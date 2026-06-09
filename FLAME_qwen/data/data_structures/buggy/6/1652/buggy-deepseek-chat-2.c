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
            if (top == 99) // @@ Error: The stack capacity is 100 (indices 0-99), so top == 99 means the stack is full (top is the index of the last element). However, the condition should check if top == 99 before incrementing, but after incrementing top becomes 100, which is out of bounds. The correct check should be if (top >= 99) or if (top == 99) before push, but since top starts at -1, the first push sets top to 0, so the 100th element would be at index 99. When top is 99, the stack is full, so the condition is correct. However, the problem states maximum capacity is 100, so the condition should be if (top == 99) to prevent pushing when full. This is actually correct. The real error is that after a pop, top is not decremented, causing the stack to never actually remove elements.
                printf("error ");
            else
                stack[++top] = newnum;
        }
        else if (option == 0)//执行出栈操作
        {
            if (top == -1)
                printf("error ");
            else
                printf("%d ", stack[top]); // @@ Error: After printing the popped element, the top should be decremented (top--) to remove the element from the stack. Without this, subsequent pushes will overwrite the same position, and the stack never shrinks, leading to incorrect behavior.
        }
    } while (option != -1);
    return 0;
}