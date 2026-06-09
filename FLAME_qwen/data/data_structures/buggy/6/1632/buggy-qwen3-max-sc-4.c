#include<stdio.h>
#define max 100
int top=-1;


void push(int stack[],int top,int number){
    if(top==max-1){
        printf("error ");
        
    }else{
    
        stack[top]=number; // @@ [The 'top' parameter is passed by value, so incrementing it in main doesn't reflect inside push. Also, the assignment should be to stack[top] after incrementing, but here top is already incremented in main, yet the logic fails because the updated top isn't used correctly due to pass-by-value. Moreover, the stack index should be the new top, but since top was incremented before calling push, this line uses the correct index. However, the real issue is that the function doesn't actually update the global 'top' or use it properly because it's shadowed by the parameter. But more critically, the push operation does not increment the local top (which is a copy), but the main increments top before calling push, which leads to writing at an index that may be beyond the current logical top. However, the major error causing incorrect behavior is that the 'top' variable in main is modified before the push/pop functions are called, and the functions receive a copy, so they can't validate based on the actual state. Additionally, in pop, after printing, the top is decremented in main, but if the stack is empty (top==-1), it still decrements to -2, causing further errors. But the immediate errors per line are:]

    }
        
}
void pop(int stack[],int top){
    if(top==-1){
        printf("error ");
    }else{
    printf("%d ",stack[top]); // @@ [Similar to push, 'top' is passed by value. The function checks and prints based on the passed top, but the actual stack state is managed via the global 'top' variable which is being manipulated in main. However, the bigger issue is that when popping, main decrements 'top' after the call, even if the pop printed "error", leading to invalid top values. Also, this line accesses stack[top] when top might be -1 if not handled, but the condition prevents that. However, the design flaw is using a global 'top' but passing it as a parameter, causing inconsistency.]

    
    
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
            top++; // @@ [Incrementing 'top' before validating if the stack is full leads to potential overflow. If the stack is already full (top == max-1), this makes top == max, and then push is called with top = max, which triggers the error condition, but the stack[top] assignment in push would be out of bounds if the error check were bypassed. However, in this code, the error check uses the passed top (which is now max), so it correctly prints "error", but the global 'top' remains incremented to max, corrupting the stack state for future operations.]
            push(stack,top,number);
        } else if(number==0){
            pop(stack,top);
            top--; // @@ [Decrementing 'top' after pop even when the stack is empty (i.e., when pop printed "error") causes 'top' to go below -1, leading to invalid state. For example, if top is -1 (empty), pop prints "error", then top becomes -2, and subsequent operations will behave incorrectly.]
        }
    }
    return 0;
}