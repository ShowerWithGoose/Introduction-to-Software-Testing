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
            if (st.top == 100)
                printf("error"); // @@ [Missing space after "error" as required by output format]
            else
            {
                st.data[st.top] = m;
                st.top++;
            }
        }
        else if (n == 0)
        {
            if (st.top == 0)
                printf("error"); // @@ [Missing space after "error" as required by output format]
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