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
    s.top=0; // @@ [Error: The stack's top should be initialized to -1 to indicate an empty stack, not 0. With top=0, the first push will store data at index 0 and then increment top to 1, but the pop operation uses --s.top which will incorrectly decrement before accessing, causing off-by-one errors.]
    while(scanf("%d",&x)!=EOF)
    {
        if(x==-1) break;
        if(x==1)
        {
            if(s.top==100) printf("error ");
            else
            {
                scanf("%d",&s.data[s.top++]); // @@ [Error: This correctly pushes the value, but due to the wrong initial top value, the first element is stored at index 0, which is fine, but the pop logic is inconsistent.]
            }
        }
        else if(x==0)
        {
            if(s.top==0) printf("error "); // @@ [Error: The empty check should be s.top == -1, not s.top == 0. With top initialized to 0, this condition will incorrectly treat an empty stack as having one element.]
            else
            {    
                scanf("%d",&s.data[--s.top]); // @@ [Error: This line incorrectly uses scanf to read input during a pop operation, but pop should only output the top element, not read new input. Additionally, --s.top decrements before accessing, which is wrong; it should access s.data[--s.top] but the correct logic for a stack with top pointing to the next empty slot is s.data[--s.top]. However, due to the initial top=0, this will cause the first pop to access index -1 (undefined behavior) or index 0 incorrectly.]
            }
        }
    }
    return 0;
}