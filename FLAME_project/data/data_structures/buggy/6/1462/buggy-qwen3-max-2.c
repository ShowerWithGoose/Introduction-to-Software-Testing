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
            if(s.op==100) @@ // The struct 'stack' does not have a member named 'op'; this should be 's.top' to check stack full condition.
                printf("error ");
            else
                scanf("%d",&s.data[s.top++]);
        }else if(op==0){
            if(s.top==0)
                printf("error ");
            else
                printf("%d",s.data[--s.top]); @@ // Missing space after the printed number as required by the output format.
        }
    }
    return 0;
}