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
            printf("error "); @@ // This condition prints "error " for invalid push (stack full) or pop (stack empty), but it executes even after a valid operation was already handled, leading to duplicate or incorrect "error" messages. For example, if op==1 and top==99, it correctly prints error, but if op==0 and top==-1, it prints error — however, the subsequent 'if(op==0)' block will also execute and try to pop from an empty stack, causing undefined behavior or wrong output.
        }
        if(op==0){
            printf("%d ",stack[top]); @@ // When the stack is empty (top == -1), this line accesses stack[-1], which is undefined behavior. Although the previous condition checks for top==-1 and prints "error ", both this block and the error block execute for op==0 and top==-1, leading to both "error " and garbage/invalid output.
            stack[top]=0;
            top--;
        }
        if(op==-1){
            break;
        }
    }

}