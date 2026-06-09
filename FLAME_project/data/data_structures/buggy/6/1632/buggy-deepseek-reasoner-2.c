#include<stdio.h>
#define max 100
int top=-1;


void push(int stack[],int top,int number){
    if(top==max-1){ // @@ Condition is wrong. Should be `if(top>=max)` or `if(top==max)` to detect full stack after increment. This condition fails when top becomes 100 (overflow).
        printf("error ");
        
    }else{
    
        stack[top]=number;
        
    }
        
}
void pop(int stack[],int top){
    if(top==-1){
        printf("error ");
    }else{
    printf("%d ",stack[top]);
    
    
    }
    
}
int main(){
    int number;int stack[max]={0};
    while(scanf("%d",&number)){
        if(number==-1){
        break;
        }
        else if(number==1){
            scanf("%d",&number);
            top++; // @@ Incrementing `top` before calling `push` is incorrect. If push detects a full stack, `top` has already been incremented to an out-of-bounds index, causing state corruption.
            push(stack,top,number);
        } else if(number==0){
            pop(stack,top);
            top--; // @@ Decrementing `top` unconditionally after pop. If pop detected empty stack, `top` becomes -2, leading to an invalid state.
        }
    }
    return 0;
}