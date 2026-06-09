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
            if (st.top == 100) // @@ Error: The stack capacity is 150 (data[150]), but the condition checks for 100, which is incorrect. It should check if st.top == 150 to detect a full stack.
                printf("error");
            else
            {
                st.data[st.top] = m;
                st.top++;
            }
        }
        else if (n == 0)
        {
            if (st.top == 0) // @@ Error: This condition is correct for detecting an empty stack, but the output format requires a space after "error" (i.e., "error "), not just "error". The reference program prints "error " with a space.
                printf("error");
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