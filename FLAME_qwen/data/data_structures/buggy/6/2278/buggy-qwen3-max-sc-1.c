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
                printf("%d",s.data[s.top]); // @@ [Accessing s.data[s.top] is out of bounds; the top element is at index s.top - 1, not s.top. This causes undefined behavior and incorrect output.]
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
                s.top=s.top+1; // @@ [Incrementing top before storing the value leads to storing at index s.top (which is now 1-based), causing off-by-one error. Should store first, then increment. Also, this makes the next pop access s.data[s.top] which is one past the actual top.]
                scanf("%d",&s.data[s.top]);
            }
        }
    }
    return 0;
}