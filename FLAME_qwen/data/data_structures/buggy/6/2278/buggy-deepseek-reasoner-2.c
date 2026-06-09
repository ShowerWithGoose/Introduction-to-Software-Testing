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
                printf("%d",s.data[s.top]); // @@ [Pop output missing trailing space; should be "%d " to match required format.]
                s.top=s.top-1;
            }
        }
        else if(a==1)
        {
            if(s.top==100)
            {
                printf("error "); // @@ [When stack is full, the program does not read the integer that follows the operation, leading to input desynchronization.]
            }
            else
            {
                s.top=s.top+1;
                scanf("%d",&s.data[s.top]);
            }
        }
    }
    return 0;
}