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
                printf("%d",s.data[s.top]); // @@ [Incorrect index: should be s.data[s.top-1] because top points to the next empty slot, so the top element is at index s.top-1]
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
                s.top=s.top+1; // @@ [Incrementing before storing causes out-of-bounds write and skips index 0; should store first then increment, or use s.data[s.top] then s.top++]
                scanf("%d",&s.data[s.top]); // @@ [Writing to s.data[s.top] after increment leads to using index 1..100 instead of 0..99, and may exceed array bounds when top becomes 100]
            }
        }
    }
    return 0;
}