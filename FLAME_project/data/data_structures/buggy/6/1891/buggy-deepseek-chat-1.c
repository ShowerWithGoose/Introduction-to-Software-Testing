# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>

typedef struct Stack
{
    int top;
    int data[100];
}stack;
int main()
{
    int x;
    stack s;
    s.top=0; // @@ [Error: The stack top should be initialized to -1 to indicate an empty stack, not 0. With top=0, the first push will store data at index 0, but the condition s.top==0 for empty check will incorrectly treat a non-empty stack as empty.]
    while(scanf("%d",&x)!=EOF)
    {
        if(x==-1) break;
        if(x==1)
        {
            if(s.top==100) printf("error ");
            else
            {
                scanf("%d",&s.data[s.top++]); // @@ [Error: This correctly pushes the value, but due to the wrong initialization, the stack behavior is incorrect.]
            }
        }
        else if(x==0)
        {
            if(s.top==0) printf("error ");
            else
            {    
                scanf("%d",&s.data[--s.top]); // @@ [Error: This line incorrectly reads input instead of popping and printing the top element. It should print s.data[--s.top] or s.data[s.top-1] and then decrement top, not read new input.]
            }
        }
    }
    return 0;
}