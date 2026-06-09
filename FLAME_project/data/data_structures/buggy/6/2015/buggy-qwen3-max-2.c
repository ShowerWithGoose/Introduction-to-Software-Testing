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
            printf("%d ",stack[top]);
            stack[top]=0;
            top--;
        }
        if(op==-1){
            break;
        }
    }

}