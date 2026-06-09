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
            printf("error "); @@ // This condition prints "error " for invalid push (stack full) or pop (stack empty), but it does so BEFORE handling valid pop operations, and also prints "error " even when a valid push was just done in the previous if-block. Moreover, it will print "error " for op==1 when top==99, but the earlier if(op==1&&top!=99) already skipped pushing, so this is correct for push-full case. However, for pop-empty case, this prints "error ", but then the next if(op==0) block still executes and tries to pop from empty stack, causing undefined behavior.
        }
        if(op==0){
            printf("%d ",stack[top]); @@ // This block executes even when the stack is empty (top == -1), because the prior "error" check doesn't prevent this block from running. This leads to accessing stack[-1], which is out-of-bounds and undefined behavior.
            stack[top]=0;
            top--;
        }
        if(op==-1){
            break;
        }
    }

}