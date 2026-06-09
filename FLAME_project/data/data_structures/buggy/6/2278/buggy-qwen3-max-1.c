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
    s.top=0; // @@ [The stack's top should be initialized to -1 for an empty stack if using 0-based indexing where top points to the last valid element. However, in this implementation, top is being used as a count (1-based), which causes off-by-one errors in access.]
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
                printf("%d",s.data[s.top]); // @@ [When top is used as a count (starting at 0 for empty), the last element is at index top-1, not top. This accesses one past the actual top element, leading to incorrect output or undefined behavior.]
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
                scanf("%d",&s.data[s.top]); // @@ [Because top is incremented before storing, the first element is stored at index 1, leaving index 0 unused. This mismatches with the pop operation which reads from s.data[s.top] after decrementing, causing inconsistent indexing and wrong values printed.]
            }
        }
    }
    return 0;
}