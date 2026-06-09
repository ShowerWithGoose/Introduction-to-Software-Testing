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
            stack[top]=buf; // @@ need to check that buf is not 1,0,-1; problem requires push only for values not equal to 1,0,-1
        }
        if((op==1&&top==99)||(op==0&&top==-1)){
            printf("error ");
        }
        if(op==0){
            printf("%d ",stack[top]); // @@ this executes even when top==-1 (empty stack), causing out-of-bounds access; should be guarded by a check for empty stack
            stack[top]=0;
            top--;
        }
        if(op==-1){
            break;
        }
    }

}