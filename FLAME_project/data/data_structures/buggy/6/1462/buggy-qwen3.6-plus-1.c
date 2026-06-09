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
            if(s.op==100) // @@ [Error: 'stack' struct has no member named 'op'. It should be 's.top' to check if the stack is full. Also, since top is initialized to 0 and incremented after push, checking against 100 is correct for capacity, but the member access is wrong.]
                printf("error ");
            else
                scanf("%d",&s.data[s.top++]);
        }else if(op==0){
            if(s.top==0)
                printf("error ");
            else
                printf("%d",s.data[--s.top]);
        }
    }
    return 0;
}