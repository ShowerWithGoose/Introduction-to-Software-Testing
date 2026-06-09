#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int stack[100];
    int top=-1;
    int op;int buf;
    while(scanf("%d",&op)!=EOF){
        if(op==1&&top!=99){ // @@ Logical error: When the stack is full, the integer argument following '1' is not consumed, causing subsequent inputs to be misread as operation codes.
            scanf("%d",&buf);
            top++;
            stack[top]=buf;
        }
        if((op==1&&top==99)||(op==0&&top==-1)){ // @@ Logical error: Does not consume the push argument when full; independent if statements allow the pop block to execute even after an error is printed.
            printf("error ");
        }
        if(op==0){ // @@ Logical error: Should be 'else if(op==0)' to prevent this block from executing after an error is printed for an empty stack.
            printf("%d ",stack[top]); // @@ Semantic error: Accesses invalid memory (stack[-1]) when top==-1, resulting in undefined behavior.
            stack[top]=0;
            top--;
        }
        if(op==-1){
            break;
        }
    }

}