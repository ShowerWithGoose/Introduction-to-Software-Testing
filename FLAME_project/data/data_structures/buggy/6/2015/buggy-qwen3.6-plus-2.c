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
        if((op==1&&top==99)||(op==0&&top==-1)){ // @@ The condition for stack full error is checked after the push logic has potentially executed or failed to execute correctly, and more importantly, the logic flow allows multiple if blocks to execute. Specifically, if op==1 and stack is full, it skips the first if, enters this if printing error. But if op==0 and stack is empty, it prints error. However, the next if block for op==0 will also execute if op==0, leading to accessing invalid memory or incorrect behavior when error occurs. The main issue is that the `if` statements are not mutually exclusive using `else if`. When `op==0` and `top==-1`, it prints "error ", but then falls through to the next `if(op==0)` block which tries to print `stack[top]` (invalid access) and decrement `top`.
            printf("error ");
        }
        if(op==0){ // @@ This block executes even if the previous block printed "error" for an empty stack pop. It should be an else-if or guarded by a check that the pop was valid.
            printf("%d ",stack[top]);
            stack[top]=0;
            top--;
        }
        if(op==-1){
            break;
        }
    }

}