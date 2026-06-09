#include<stdio.h>
struct stack
{
    int top;
    int data[105];
};
typedef struct stack stack;
int main()
{
    stack s;
    s.top=0;
    int a,b;
    while(scanf("%d",&a)!=EOF)
    {
        if(a==-1)
        {
            break;
        }
        else if(a==0)
        {
            if(s.top==0)
            {
                printf("error ");
            }
            else
            {
                printf("%d",s.data[s.top]); // @@ The top index is used before decrementing, but the stack's top should point to the last element. When top is initialized to 0, the first push stores data at index 1, so the top index is always one ahead of the actual top element. This causes the wrong element to be popped and printed. Additionally, there is no space printed after the popped value, causing concatenated output.
                s.top=s.top-1;
            }
        }
        else if(a==1)
        {
            if(s.top==100)
            {
                printf("error ");
            }
            else
            {
                s.top=s.top+1; // @@ The top is incremented before storing data, so the first element is stored at index 1 instead of index 0. This misalignment causes the pop operation to access the wrong element.
                scanf("%d",&s.data[s.top]);
            }
        }
    }
    return 0;
}