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
            printf("error "); // @@ After printing "error ", the program must still read and discard the integer operand to avoid misalignment with subsequent input. The reference program reads the integer regardless of stack capacity. Failing to do so can cause wrong interpretation of the remaining input.
            else
            scanf("%d",&s.data[s.top++]);
        }
        else if(t==0){
            if(s.top==0)
            printf("error ");
            else
            printf("%d",s.data[--s.top]); // @@ Missing space after the popped value. According to the problem, output should have a space after each element, including the last one. Change to printf("%d ", ...) to match expected output.
        }
    }
    return 0;
}