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
                printf("%d",s.data[s.top]); // @@ The top index is used before decrementing, but the stack's top should point to the last element. When top is 0, the stack is empty, but when top is 1, the element is at index 1? Actually, the initial top is 0, meaning the first push sets top to 1 and stores data at index 1. So the top always points to the last pushed element. However, the pop should first output the element at s.top, then decrement top. But the output format requires a space after each number. This line prints the number without a space, causing concatenation. It should print with a space: printf("%d ", s.data[s.top]);
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
                s.top=s.top+1;
                scanf("%d",&s.data[s.top]);
            }
        }
    }
    return 0;
}