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
    s.top=0; // @@ [The initial value of top should be -1 to indicate an empty stack, not 0. Using 0 causes the first element to be placed at index 0 but also makes it impossible to distinguish between an empty stack and a stack with one element when checking for underflow.]
    int op;
    while (scanf("%d",&op)!=EOF)
    {
        if(-1==op)
        break;
        else if(1==op)
        {
            if(s.top==100) // @@ [This check is incorrect because top starts at 0 and increments before storing. When top == 100, the stack already has 100 elements (indices 0-99), so this condition triggers only after overflow has occurred. It should be s.top >= 100 or better yet, use top starting at -1 and check against MAX-1 as in reference.]
            printf("error ");
            else
            scanf("%d",&s.data[s.top++]); // @@ [Because top starts at 0, this writes to data[0] on first push, which is okay, but combined with incorrect empty/full checks leads to logical errors. Also, no space after printed numbers during pop.]
        }
        else if(0==op)
        {
            if(s.top==0) // @@ [This check assumes stack is empty when top == 0, but since top starts at 0 and increments on push, top == 0 actually means there's one element (at index 0). So popping when top == 0 incorrectly prints "error" even though the stack isn't empty. Should be top <= 0 if top starts at 0, but better practice is to start top at -1.]
            printf("error ");
            else
            printf("%d",s.data[--s.top]); // @@ [Missing space after each popped number. Expected output requires a space after every element, including the last one. This outputs digits without spaces, causing concatenated numbers like "655901...".]
        }
    }
    return 0;
}