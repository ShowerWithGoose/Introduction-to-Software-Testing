#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stack
{
    int top;
    int data[100];
}stack;
int main()
{
    stack s;
    s.top=0; // @@ [The initial value of top should be -1 to indicate an empty stack, not 0. Using 0 causes the first element to be placed at index 0 but makes it impossible to distinguish between empty and one-element states correctly in pop checks.]
    int op;
    while (scanf("%d",&op)!=EOF)
    {
        if(-1==op)
        break;
        else if(1==op)
        {
            if(s.top==100) // @@ [Since top starts at 0 and is incremented before storing, when top == 100, the stack already has 100 elements (indices 0-99), so this check is correct for capacity. However, due to incorrect initialization (top=0 instead of -1), the logic is off by one. The real issue is that with top=0 initially, after pushing 100 items, top becomes 100, which correctly triggers "error", but the indexing during push is wrong because the first push writes to data[0] and increments top to 1, meaning top represents count, not last index. This leads to inconsistency with pop logic.]
            printf("error ");
            else
            scanf("%d",&s.data[s.top++]); // @@ [Because top starts at 0, this stores the first element at index 0 and then increments top to 1. So top represents the number of elements, not the index of the top element. But in pop, --s.top accesses data[top-1], which is correct only if top is count. However, the error condition in pop checks s.top==0, which is correct for count-based top. BUT: the main bug is missing space after printed numbers and error messages as per output format.]
        }
        else if(0==op)
        {
            if(s.top==0)
            printf("error "); // @@ [This prints "error " with a space, which is correct per output format.]
            else
            printf("%d",s.data[--s.top]); // @@ [This prints the popped number without a trailing space. According to the problem's output format, each popped element must be followed by a space, including the last one. This causes the output to be concatenated like "655901..." instead of "655 901 ... ".]
        }
    }
    return 0;
}