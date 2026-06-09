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
                printf("%d",s.data[s.top]); // @@ [Error: When popping, the top element is at index s.top-1, not s.top. Since top is incremented after push, the current top points to the next empty slot. Should use s.data[s.top-1].]
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
                s.top=s.top+1; // @@ [Error: The top should be incremented after storing the value, not before. This causes the first element to be stored at index 1 instead of 0, and the stack to be misaligned. Should store first, then increment.]
                scanf("%d",&s.data[s.top]);
            }
        }
    }
    return 0;
}