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
    s.top=0;
    int op;
    while (scanf("%d",&op)!=EOF)
    {
        if(-1==op)
        break;
        else if(1==op)
        {
            if(s.top==100) // @@ Error: The stack capacity is 100, so the maximum index is 99. When top is 100, it means the stack is full (indices 0-99 are used). However, the condition should check if top == 100 before pushing, but the array size is 100, so top can only go up to 99. The correct check should be if (s.top == 100) which is correct for detecting full stack, but the array index s.data[s.top++] will access s.data[100] when top is 100, which is out of bounds. The condition should be if (s.top >= 100) or if (s.top == 100) and then not increment. Actually, the logic here is: if top is 100, it's full, so we should not push. But the code still does s.data[s.top++] when top is 100, causing out-of-bounds access. The error is that the push operation should only execute if the stack is not full, but the scanf and assignment happen after the if check without an else block. The correct structure should have the push inside an else block.
            printf("error ");
            else
            scanf("%d",&s.data[s.top++]); // @@ Error: This line is executed even when the stack is full because there is no else block. The if statement only controls the printf, but the scanf and assignment always execute. This causes out-of-bounds access when top is 100. The push operation should be inside an else block.
        }
        else if(0==op)
        {
            if(s.top==0)
            printf("error ");
            else
            printf("%d",s.data[--s.top]); // @@ Error: The output format requires a space after each popped element, but this printf does not include a space. It should be printf("%d ", ...) to match the expected output format.
        }
    }
    return 0;
}