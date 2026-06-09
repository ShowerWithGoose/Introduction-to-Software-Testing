#include<stdio.h>
struct stack{
    int top;
    int data[100];
};
typedef struct stack Stack;
int main()
{
    int t;
    Stack s;
    s.top=0;
    while(scanf("%d",&t)!=EOF){
        if(t==-1)
        break;
        else if(t==1){
            if(s.top==100)
            printf("error ");
            else
            scanf("%d",&s.data[s.top++]);
        }
        else if(t==0){
            if(s.top==0)
            printf("error "); // @@ [Missing space after popped value; expected output format requires a space after every popped element or "error", but this prints without trailing space]
            else
            printf("%d",s.data[--s.top]); // @@ [Missing space after printed value; should print "%d " to match required output format]
        }
    }
    return 0;
}