#include<stdio.h>

typedef struct stack{
    int top;
    int data[100];
}stack;

int main(){
    stack s;
    s.top = 0;
    int op;
    while(scanf("%d",&op)!=EOF){
        if(op==-1) break;
        if(1==op){
            if(s.op==100) // @@ [Error: 's.op' is not a valid member; should be 's.top'. Also, the condition should check if top equals 100 (full stack), but since top is the next index to push, the correct check is s.top == 100]
                printf("error ");
            else
                scanf("%d",&s.data[s.top++]); // @@ [Error: Missing space after the popped element in the output format; also, the push operation should check for full stack before incrementing top]
        }else if(op==0){
            if(s.top==0)
                printf("error ");
            else
                printf("%d",s.data[--s.top]); // @@ [Error: Missing space after the popped element; expected output format requires a space after each element]
        }
    }
    return 0;
}