#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int stack[100];
    int top=-1;
    int op;int buf;
    while(scanf("%d",&op)!=EOF){
        if(op==1&&top!=99){
// @@ When stack is full (top==99), the push value is not read from input, causing subsequent operations to misinterpret the input.
            scanf("%d",&buf);
            top++;
            stack[top]=buf;
        }
        if((op==1&&top==99)||(op==0&&top==-1)){
// @@ For push when stack is full, the code should still read the integer value to consume it from the input stream.
            printf("error ");
        }
        if(op==0){
// @@ This condition is true even when top==-1 after printing error, leading to out-of-bounds access and incorrect decrement.
            printf("%d ",stack[top]);
            stack[top]=0;
            top--;
        }
        if(op==-1){
            break;
        }
    }

}