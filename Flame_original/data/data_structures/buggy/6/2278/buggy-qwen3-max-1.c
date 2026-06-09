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
                printf("%d",s.data[s.top]); // @@ [Off-by-one error: should access s.data[s.top - 1] because top points to the next empty slot, not the current top element]
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
                s.top=s.top+1; // @@ [Incorrect order: incrementing top before storing causes writing beyond current top; should store first then increment, or use s.data[s.top] then s.top++]
                scanf("%d",&s.data[s.top]); // @@ [Due to prior increment, this writes to s.data[s.top] where s.top is already incremented, potentially causing out-of-bound write when s.top was 99 (now 100, which is valid index but logic inconsistent); also misses space in output formatting like reference]
            }
        }
    }
    return 0;
}