#include<stdio.h>
#define max 100
int top=-1;


void push(int stack[],int top,int number){
    if(top==max-1){
        printf("error ");
        
    }else{
    
        stack[top]=number; // @@ [The 'top' parameter is passed by value, so incrementing it in main doesn't affect the local 'top' here. Also, the assignment should be to stack[top] after incrementing, but the increment happens in main before calling push, which leads to off-by-one error: writing to stack[top] where top is already incremented, potentially exceeding bounds or skipping index 0.]
        
    }
        
}
void pop(int stack[],int top){
    if(top==-1){
        printf("error ");
    }else{
    printf("%d ",stack[top]); // @@ [The 'top' parameter is passed by value, so decrementing 'top' in main after this call doesn't prevent accessing an invalid index here if the stack was empty. Also, after printing, the top should be decremented, but since it's passed by value, the decrement in main happens regardless of whether pop succeeded, leading to incorrect state.]
    
    
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
            top++; // @@ [Incrementing 'top' before checking if the stack is full can cause buffer overflow. Also, if the stack is already full (top == max-1), this makes top == max, leading to out-of-bounds access in push.]
            push(stack,top,number);
        } else if(number==0){
            pop(stack,top);
            top--; // @@ [Decrementing 'top' even when pop fails (e.g., on empty stack) leads to top becoming -2, causing further errors. Also, pop doesn't actually remove the element from the stack—it just prints—so the logic of managing 'top' is inconsistent.]
        }
    }
    return 0;
}