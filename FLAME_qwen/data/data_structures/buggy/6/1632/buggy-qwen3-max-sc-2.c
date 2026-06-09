#include<stdio.h>
#define max 100
int top=-1;


void push(int stack[],int top,int number){
    if(top==max-1){
        printf("error ");
        
    }else{
    
        stack[top]=number; // @@ [The function parameter 'top' is passed by value, so incrementing 'top' in main does not affect the local 'top' here. Also, after pushing, 'top' should be incremented, but this code uses the already incremented 'top' from main and assigns to that index without adjusting for zero-based indexing correctly. However, the main issue is that the local 'top' shadows the global one, and the assignment should be to 'stack[top]' only after ensuring it's the correct index. But more critically, the push logic doesn't actually update the stack correctly because the global 'top' is managed in main, yet the function uses a copy. This leads to incorrect stack behavior.]
        
    }
        
}
void pop(int stack[],int top){
    if(top==-1){
        printf("error ");
    }else{
    printf("%d ",stack[top]); // @@ [Similar to push, the 'top' here is a copy. The pop operation prints the correct value but then in main, 'top' is decremented. However, if the stack is empty (top == -1), it prints "error ", which is correct. But the bigger issue is that the function design passes 'top' by value, making it impossible to maintain consistent state. However, the immediate error causing wrong output is that after popping, the element is printed but the stack pointer is decremented in main regardless of whether the pop was valid or not. Specifically, even when an "error" is printed due to empty stack, main still executes 'top--', which makes 'top' go below -1, leading to further errors.]
    
    
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
            top++; // @@ [This increments 'top' before checking if the stack is full. If the stack is already full (top == max-1), this will make top == max, leading to out-of-bound access in push. Also, if the stack is full, push prints "error ", but 'top' has already been incremented incorrectly.]
            push(stack,top,number);
        } else if(number==0){
            pop(stack,top);
            top--; // @@ [This decrements 'top' even when the pop operation fails (i.e., when the stack is empty). In that case, pop prints "error ", but then 'top' becomes -2, -3, etc., which breaks future operations. The decrement should only happen if the pop was successful.]
        }
    }
    return 0;
}