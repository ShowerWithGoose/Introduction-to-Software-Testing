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
            printf("error ");
        }
        if(op==0){ // @@ [This block executes unconditionally when op==0, even if the stack is empty (top==-1). It prints stack[top] (out-of-bounds access) and decrements top further, causing undefined behavior and outputting an extra "-1" in the test case.]
            printf("%d ",stack[top]);
            stack[top]=0;
            top--;
        }
        if(op==-1){
            break;
        }
    }

}