#include<stdio.h>
#define max 100
int top=-1;


void push(int stack[],int top,int number){
    if(top==max-1){
        printf("error ");
        
    }else{
    
        stack[top]=number; // @@ [The push operation should assign to stack[top], but 'top' here is a local copy; the actual 'top' in main is incremented before the call, so this writes to the correct index. However, the function does not update the global 'top' correctly because it's passed by value, but since main manages 'top', this is not the main issue. The real problem is that after printing "error ", the invalid push should not increment 'top' in main, but main increments 'top' BEFORE calling push, which is wrong.]
        
    }
        
}
void pop(int stack[],int top){
    if(top==-1){
        printf("error ");
    }else{
    printf("%d ",stack[top]); // @@ [When popping, the element at 'top' is printed, but then in main, 'top' is decremented AFTER the pop call. However, if the stack is empty (top == -1), it prints "error ", but main still decrements 'top' to -2, causing future operations to be incorrect. Also, for a valid pop, the element is printed correctly, but the order of decrement in main is okay only if the pop function doesn't manage top. However, the main issue is that main decrements 'top' even when pop fails (i.e., when stack is empty).]
    
    
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
            top++; // @@ [Incrementing 'top' before checking if the stack is full is incorrect. If the stack is already full (top == max-1), this will make top == max, and then push will check top==max-1 (which is now false) and incorrectly allow the push. Also, even if full, 'top' is incremented, leading to out-of-bound access or incorrect state. Moreover, if push fails (prints "error "), 'top' should not have been incremented.]
            push(stack,top,number);
        } else if(number==0){
            pop(stack,top);
            top--; // @@ [Decrementing 'top' after pop is incorrect when the stack is empty. If the stack is empty (top == -1), pop prints "error ", but then 'top' becomes -2. Subsequent operations will be based on this invalid 'top'. Also, for a successful pop, the decrement is correct only if the pop function uses the current top, which it does, but the error case must not decrement 'top'.]
        }
    }
    return 0;
}