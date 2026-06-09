#include<stdio.h>
#define max 100
int top=-1;


void push(int stack[],int top,int number){
    if(top==max-1){
        printf("error ");
        
    }else{
    
        stack[top]=number; // @@ [The push operation should assign to stack[top] after incrementing, but top is passed by value so the global top isn't updated correctly in the function. Also, the assignment should be to stack[++top] in main logic, but here it uses the already incremented top from main, yet doesn't actually store at the correct index because the increment happened before the call and the function doesn't adjust it. However, the real issue is that the function does not increment top itself, and the main increments top before calling push, which leads to writing at an unallocated position when stack is empty (e.g., first push writes to stack[0] only if top was -1 then incremented to 0 before call). But the bigger problem is that the pop function also doesn't update top correctly.]
        
    }
        
}
void pop(int stack[],int top){
    if(top==-1){
        printf("error ");
    }else{
    printf("%d ",stack[top]); // @@ [After printing the top element, the stack pointer 'top' should be decremented, but this function doesn't do it. Moreover, since 'top' is passed by value, decrementing it inside the function won't affect the global 'top'. The main function decrements 'top' after the call, but if the stack is empty (top == -1), it still decrements, leading to top = -2, causing future operations to behave incorrectly. Also, for a valid pop, the main decrements top after the call, but the function prints stack[top] with the current top, which is correct only if the main hasn't decremented yet — however, the logic is split inconsistently between main and functions.]
    
    
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
            top++; // @@ [Incrementing top before checking if the stack is full can cause accessing stack[max] when top was already max-1, leading to buffer overflow. Also, the push function checks 'if(top==max-1)' but top has already been incremented, so the check happens too late. The correct approach is to check before incrementing.]
            push(stack,top,number);
        } else if(number==0){
            pop(stack,top);
            top--; // @@ [Decrementing top even when pop fails (i.e., when stack is empty) causes top to go below -1, leading to incorrect state. The decrement should only happen if the pop was successful.]
        }
    }
    return 0;
}