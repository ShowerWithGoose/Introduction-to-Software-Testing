#include <stdio.h>
typedef struct stack
{
    int top;
    int data[150];
} Stack;
Stack st;
int main(int argc, char const *argv[])
{
    st.top = 0;
    int n, m;
    while (~scanf("%d", &n))
    {
        if (n == 1)
        {
            scanf("%d", &m);
            if (st.top == 100) // @@ Error: The stack capacity is 150 (data[150]), but the check uses 100, which is inconsistent with the problem's maximum capacity of 100. However, the reference program uses 100, so this is correct per the problem. The actual error is that when the stack is full, the output should be "error " (with a space), but here it prints "error" without a space.
                printf("error"); // @@ Error: Missing space after "error". The problem requires "error " (with a trailing space) to match the output format.
            else
            {
                st.data[st.top] = m;
                st.top++;
            }
        }
        else if (n == 0)
        {
            if (st.top == 0) // @@ Error: The condition should be st.top < 1 to check for empty stack, but st.top == 0 is functionally equivalent since top starts at 0. However, the output should be "error " (with a space), but here it prints "error" without a space.
                printf("error"); // @@ Error: Missing space after "error". The problem requires "error " (with a trailing space) to match the output format.
            else
            {
                printf("%d ", st.data[st.top - 1]);
                st.top--;
            }
        }
        else if (n == -1)
            break;
    }
    return 0;
}