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
            printf("error "); @@ [This condition prints "error " for both full push and empty pop, but it runs BEFORE the actual pop operation logic. However, the bigger issue is that when op==0 and top==-1, this prints "error ", but then the next 'if(op==0)' block still executes, causing undefined behavior by accessing stack[top] when top==-1.]
        }
        if(op==0){
            printf("%d ",stack[top]); @@ [When the stack is empty (top == -1), this line accesses stack[-1], which is invalid memory access. This happens because the previous error-checking block prints "error " but does NOT prevent this block from executing. The logic should use else-if or early continue to avoid this.]
            stack[top]=0;
            top--;
        }
        if(op==-1){
            break;
        }
    }

}