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
        if(op==0){
            printf("%d ",stack[top]); // @@ [When op==0 and top==-1 (empty stack), this line executes after the error print, accessing stack[-1] which is out-of-bounds and prints an incorrect value. The pop should only happen if the stack is not empty.]
            stack[top]=0;
            top--;
        }
        if(op==-1){
            break;
        }
    }

}