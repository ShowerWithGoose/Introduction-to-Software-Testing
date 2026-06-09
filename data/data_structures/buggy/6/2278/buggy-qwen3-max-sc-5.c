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
                s.top=s.top+1; // @@ [Incorrect order: incrementing top before storing causes writing beyond current top and skips index 0; should store first then increment]
                scanf("%d",&s.data[s.top]);
            }
        }
    }
    return 0;
}