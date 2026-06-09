#include<stdio.h>
#define max 100
int top=-1;


void push(int stack[],int top,int number){
    if(top==max-1){
        printf("error ");
        
    }else{
    
        stack[top]=number; // @@ [The 'top' parameter is passed by value, so incrementing it in main doesn't affect the local 'top' here. Also, after pushing, 'top' should be incremented before assigning, but here assignment uses current 'top' which is already incremented in main, leading to off-by-one overwrite or skip. Moreover, the function should modify the global 'top' or pass by reference, but it doesn't.]
        
    }
        
}
void pop(int stack[],int top){
    if(top==-1){
        printf("error ");
    }else{
    printf("%d ",stack[top]); // @@ [The 'top' parameter is passed by value, so decrementing 'top' in main after this call leads to incorrect indexing. Also, after printing, the stack pointer should be decremented, but that's done in main *after* the pop, which is okay only if the value printed is correct. However, since 'top' is not updated inside pop and the value used here is the pre-decrement value from main, it may print the wrong element or cause underflow. Additionally, if stack is empty (top == -1), it prints "error ", but then main still decrements top, making it -2, causing further errors.]
    
    
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
            top++; // @@ [Incrementing 'top' before calling push assumes the stack is not full, but if the stack is already full (top == max-1), this makes top == max, leading to out-of-bound access in push. Also, push checks 'top == max-1', but since top was already incremented, the check becomes ineffective.]
            push(stack,top,number);
        } else if(number==0){
            pop(stack,top);
            top--; // @@ [Decrementing 'top' after pop even when the stack was empty (i.e., pop printed "error "). This causes 'top' to go below -1, leading to future incorrect behavior. Also, if pop succeeded, this double-decrements effectively (once in logic via using current top, then decrement here), but actually the pop function doesn't manage top, so this is the only decrement—but it happens even on error.]
        }
    }
    return 0;
}