#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int stack[100];
    int top=-1;
    int op;int buf;
    while(scanf("%d",&op)!=EOF){
        if(op==1&&top!=99){
            scanf("%d",&buf);
            top++;
            stack[top]=buf;
        }
        if((op==1&&top==99)||(op==0&&top==-1)){
            printf("error "); @@ // This condition prints "error " for both full push and empty pop, but it runs BEFORE handling valid pop (next if), causing double output when popping from empty stack.
        }
        if(op==0){
            printf("%d ",stack[top]); @@ // When stack is empty (top == -1), this accesses stack[-1], which is undefined behavior. Also, error case already printed above, but this still executes.
            stack[top]=0;
            top--;
        }
        if(op==-1){
            break;
        }
    }

}