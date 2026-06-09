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
    s.top=0; // @@ [The initial top should be -1 for an empty stack if using 0-based indexing where top points to the last valid element. However, in this implementation, top is being used as a count (1-based), which causes misalignment in push/pop indexing.]
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
                printf("%d",s.data[s.top]); // @@ [When popping, it should print s.data[s.top - 1] because top represents the count of elements, not the index of the top element. As implemented, s.data[s.top] accesses one past the last valid element.]
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
                scanf("%d",&s.data[s.top]); // @@ [This stores the new element at index s.top, which is correct only if top starts at 0 and is incremented before storing. But then during pop, it should access s.data[s.top], which contradicts typical stack behavior. The real issue is inconsistent indexing: top is treated as count (1-based) but accessed as index (0-based).]
            }
        }
    }
    return 0;
}