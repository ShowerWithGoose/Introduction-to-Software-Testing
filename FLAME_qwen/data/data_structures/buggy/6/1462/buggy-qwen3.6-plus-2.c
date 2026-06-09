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
            if(s.op==100) // @@ [Error: 's.op' is not a member of the struct 'stack'. It should be 's.top' to check if the stack is full.]
                printf("error ");
            else
                scanf("%d",&s.data[s.top++]);
        }else if(op==0){
            if(s.top==0)
                printf("error ");
            else
                printf("%d",s.data[--s.top]); // @@ [Error: Missing a space after the printed number. The problem requires a space after each popped element, including the last one.]
        }
    }
    return 0;
}