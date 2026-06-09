#include<stdio.h>
#define max 100
int top=-1;


void push(int stack[],int top,int number){ // @@ top is passed by value, shadowing the global variable; the caller increments top before calling, making the internal bounds check incorrect.
    if(top==max-1){ // @@ Incorrect bounds check because top has already been incremented by the caller. It should check if top >= max.
        printf("error ");

    }else{

        stack[top]=number; // @@ Potential out-of-bounds access if top was already max-1 before the caller's increment.

    }

}
void pop(int stack[],int top){ // @@ top is passed by value, so the function cannot update the global top. Error handling is flawed due to unconditional decrement in main.
    if(top==-1){ // @@ Only checks for -1. If an error occurs, the caller still decrements top to -2, causing this check to fail on subsequent pops.
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
            top++;
            push(stack,top,number);
        } else if(number==0){
            pop(stack,top);
            top--; // @@ Unconditionally decrements top even when pop() prints "error", corrupting the stack state (e.g., top becomes -2).
        }
    }
    return 0;
}