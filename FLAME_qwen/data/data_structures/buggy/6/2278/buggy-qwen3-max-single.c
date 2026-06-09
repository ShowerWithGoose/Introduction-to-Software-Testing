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
                s.top=s.top+1; // @@ [Incorrect order: incrementing top before storing causes writing to s.data[1] on first push instead of s.data[0]; also leads to potential out-of-bounds if top reaches 100]
                scanf("%d",&s.data[s.top]); // @@ [May write beyond valid index if top was already 99; also uses incorrect index due to premature increment]
            }
        }
    }
    return 0;
}