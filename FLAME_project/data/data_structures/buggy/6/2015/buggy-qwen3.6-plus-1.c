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
        if((op==1&&top==99)||(op==0&&top==-1)){ // @@ The condition for stack full error is checked after the push logic which already incremented top, but more importantly, the logic flow is flawed. If op==1 and top was 98, it pushes (top becomes 99). Then this check (top==99) is false. If op==1 and top was 99, the first if fails (top!=99 is false), so it doesn't push. Then this check (top==99) is true, prints error. This part seems okay for full stack. However, for empty stack pop: if op==0 and top==-1, it prints error. But then the next if(op==0) executes because op is 0.
            printf("error ");
        }
        if(op==0){ // @@ This block executes even if the stack was empty and "error " was just printed. It accesses stack[top] where top is -1, causing undefined behavior or incorrect output. It should be an else-if or guarded by a check that the stack is not empty.
            printf("%d ",stack[top]);
            stack[top]=0;
            top--;
        }
        if(op==-1){
            break;
        }
    }

}