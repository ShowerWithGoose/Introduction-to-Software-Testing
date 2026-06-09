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
                scanf("%d",&s.data[--s.top]); // @@ [Pop should not read input; it must print the popped value and decrement top without reading any additional integer.]
            }
        }
    }
    return 0;
}