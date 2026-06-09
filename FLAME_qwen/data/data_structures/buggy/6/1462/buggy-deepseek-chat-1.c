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
            if(s.op==100) // @@ [Error: 's.op' is not a valid member; should be 's.top' to check if stack is full. Also, the condition should be 's.top >= 100' since top is the index of the next empty slot.]
                printf("error ");
            else
                scanf("%d",&s.data[s.top++]);
        }else if(op==0){
            if(s.top==0)
                printf("error ");
            else
                printf("%d",s.data[--s.top]); // @@ [Error: Missing space after the popped element; should be printf("%d ", ...) to match output format.]
        }
    }
    return 0;
}