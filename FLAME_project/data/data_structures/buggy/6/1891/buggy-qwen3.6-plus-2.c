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
    s.top=0; // @@ The initial state of the stack should be empty. If top represents the index of the next available slot, 0 is correct for an empty stack, but the pop logic below is incorrect.
    while(scanf("%d",&x)!=EOF)
    {
        if(x==-1) break;
        if(x==1)
        {
            if(s.top==100) printf("error ");
            else
            {
                scanf("%d",&s.data[s.top++]);
            }
        }
        else if(x==0)
        {
            if(s.top==0) printf("error ");
            else
            {    
                scanf("%d",&s.data[--s.top]); // @@ Error: Pop operation should output the element being popped, not read a new input value. It should be printf("%d ", s.data[--s.top]); or similar depending on top semantics.
            }
        }
    }
    return 0;
}