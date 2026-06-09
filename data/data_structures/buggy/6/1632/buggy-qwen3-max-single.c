#include<stdio.h>
#define max 100
int top=-1;


void push(int stack[],int top,int number){
    if(top==max-1){
        printf("error ");
        
    }else{
    
        stack[top]=number; // @@ [The push operation should assign to stack[top] after incrementing, but top is passed by value so the global top isn't updated correctly in the function. Also, the assignment should be to stack[top] only after incrementing top, but here top is already incremented in main before calling push, yet the logic doesn't decrement on error.]
        
    }
        
}
void pop(int stack[],int top){
    if(top==-1){
        printf("error ");
    }else{
    printf("%d ",stack[top]); // @@ [After printing the popped element, the top should be decremented, but since top is passed by value, the global top won't be updated. Moreover, the decrement happens in main after the call, which leads to double decrement or incorrect state.]
    
    
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
            top++; // @@ [Top is incremented before checking if the stack is full. If the stack is already full (top == max-1), this will make top == max, leading to out-of-bound access in push. Also, if push detects an error, top should not have been incremented.]
            push(stack,top,number);
        } else if(number==0){
            pop(stack,top);
            top--; // @@ [Top is decremented after pop even if the stack was empty and "error" was printed. This causes top to go below -1, leading to incorrect future isEmpty checks. Also, pop doesn't actually remove the element from the stack since it doesn't modify the global top.]
        }
    }
    return 0;
}