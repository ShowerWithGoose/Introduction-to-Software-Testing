#include<stdio.h>
#define max 100
int top=-1;


void push(int stack[],int top,int number){ @@ The parameter 'top' is passed by value, so modifying it or using it to update the global state doesn't work as intended for tracking the stack pointer across calls if the logic relies on side effects not captured here. More critically, the caller increments 'top' before calling push, but push uses the passed 'top' index directly. If the stack is full, it prints error but the caller has already incremented the global top. This leads to desynchronization.
    if(top==max-1){
        printf("error ");
        
    }else{
    
        stack[top]=number;
        
    }
        
}
void pop(int stack[],int top){ @@ Similar to push, 'top' is passed by value. The function checks the passed value, but the global 'top' is modified by the caller after this call. If the stack is empty, it prints error, but the caller decrements global top afterwards, leading to incorrect state.
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
            top++; @@ Incrementing global top before checking if it's full causes the stack pointer to advance even when an error occurs, corrupting the stack state.
            push(stack,top,number);
        } else if(number==0){
            pop(stack,top);
            top--; @@ Decrementing global top after calling pop means that even if pop printed "error" (because stack was empty), the top is still decremented, leading to negative indices or incorrect state.
        }
    }
    return 0;
}