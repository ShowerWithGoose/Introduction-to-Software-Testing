#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int stack[100];
    int top=-1;
    int op;int buf;
    while(scanf("%d",&op)!=EOF){
        if(op==1&&top!=99){ @@ When the stack is full, this condition fails and skips reading the input integer, causing input stream desynchronization for subsequent operations.
            scanf("%d",&buf);
            top++;
            stack[top]=buf;
        }
        if((op==1&&top==99)||(op==0&&top==-1)){ @@ Uses independent if statements instead of else if, allowing the pop block to execute immediately after printing an error, leading to logical conflicts.
            printf("error ");
        }
        if(op==0){ @@ Executes even when top==-1 after printing error, causing out-of-bounds array access and incorrect stack pointer modification.
            printf("%d ",stack[top]); @@ Accesses stack[-1] when the stack is empty, resulting in undefined behavior.
            stack[top]=0;
            top--; @@ Decrements top below -1 when the stack is empty, corrupting the stack state.
        }
        if(op==-1){
            break;
        }
    }

}