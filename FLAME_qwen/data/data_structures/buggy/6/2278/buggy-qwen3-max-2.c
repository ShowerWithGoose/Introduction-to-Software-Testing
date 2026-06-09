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
                printf("%d",s.data[s.top]); // @@ [Accessing s.data[s.top] is incorrect because the top index points to the next empty slot; the actual top element is at s.data[s.top - 1]. Also, missing space after %d in output format.]
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
                s.top=s.top+1; // @@ [Incrementing top before storing causes the new element to be placed at index s.top, but since top starts at 0 and represents count/next index, this leads to off-by-one error. Should store first then increment, or increment after using current top. Also, combined with scanf into that location, it skips index 0.]
                scanf("%d",&s.data[s.top]);
            }
        }
    }
    return 0;
}