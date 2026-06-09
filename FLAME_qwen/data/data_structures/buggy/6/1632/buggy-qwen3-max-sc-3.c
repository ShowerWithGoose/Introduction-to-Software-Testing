#include<stdio.h>
#define max 100
int top=-1;


void push(int stack[],int top,int number){
    if(top==max-1){
        printf("error ");
        
    }else{
    
        stack[top]=number; // @@ [The function parameter 'top' is passed by value, so incrementing 'top' in main does not affect the local 'top' here. Also, after pushing, 'top' should be incremented before assignment, but here it's used as the current index without being updated correctly. The correct logic should assign to stack[++top] or pass top by reference.]
        
    }
        
}
void pop(int stack[],int top){
    if(top==-1){
        printf("error ");
    }else{
    printf("%d ",stack[top]); // @@ [Similar issue: 'top' is passed by value, so decrementing 'top' in main after this call doesn't reflect the popped state inside this function. Moreover, after printing, the top should be decremented, but that's attempted in main after the call, which leads to using an outdated 'top' value during pop (e.g., popping from index -1 after underflow).]
    
    
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
            top++; // @@ [Incrementing 'top' before calling push assumes the stack is not full, but the push function checks 'top == max-1' using its own copy. If the stack is already full (top == max-1), this increments top to max, causing out-of-bounds access in push. Also, if push fails due to full stack, top should not have been incremented.]
            push(stack,top,number);
        } else if(number==0){
            pop(stack,top); // @@ [Passing current 'top' to pop, but if stack is empty (top == -1), this prints "error ", yet main still decrements top afterward, making it -2, which breaks future operations. Also, pop should handle the decrement internally or via reference, not in main after the call.]
            top--; // @@ [Decrementing 'top' even when pop failed (i.e., stack was empty) leads to invalid negative indices. This should only happen if pop was successful.]
        }
    }
    return 0;
}