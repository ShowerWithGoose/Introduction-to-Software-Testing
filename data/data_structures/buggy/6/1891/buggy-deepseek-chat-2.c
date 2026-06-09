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
    s.top=0;
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
                scanf("%d",&s.data[--s.top]); // @@ [Error: This line incorrectly uses scanf to read input instead of printing the popped element. The pop operation should output the value at the top of the stack, not read new input.]
            }
        }
    }
    return 0;
}