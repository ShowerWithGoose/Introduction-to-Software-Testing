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
            if(s.op==100) // @@ [Typo: 's.op' should be 's.top'; 'op' is not a member of struct stack, causing a compilation error]
                printf("error ");
            else
                scanf("%d",&s.data[s.top++]);
        }else if(op==0){
            if(s.top==0)
                printf("error ");
            else
                printf("%d",s.data[--s.top]); // @@ [Missing space after printed number; output format requires a space after each popped element including the last one]
        }
    }
    return 0;
}