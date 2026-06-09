#include<stdio.h>
#define max 100
int top=-1;


void push(int stack[],int top,int number){
    if(top==max-1){
        printf("error ");
        
    }else{
    
        stack[top]=number; // @@ [The 'top' parameter is passed by value, so incrementing it in main does not affect the local 'top' inside push. Also, the assignment should be to stack[top] after incrementing, but here the index used is already incremented in main, yet the function doesn't use the updated top correctly due to pass-by-value. Moreover, the actual top of the stack should be managed globally or via pointer, not as a copied parameter.]
        
    }
        
}
void pop(int stack[],int top){
    if(top==-1){
        printf("error ");
    }else{
    printf("%d ",stack[top]); // @@ [Similar issue: 'top' is passed by value. The decrement in main happens after the call, but during pop, the current top element should be at 'top', which is correct only if 'top' reflects the actual top index. However, because 'top' is modified in main before/after calls and passed by value, the logic becomes inconsistent. Also, after printing, the top should be decremented, but that's done in main — however, if an error occurs (empty stack), main still decrements 'top', leading to incorrect state.]
    
    
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
            top++; // @@ [Incrementing 'top' before checking if the stack is full leads to potential out-of-bound access. Also, if the stack is already full (top == max-1), this makes top == max, causing push to check top==max-1 incorrectly (it will be false), and then assign to stack[max], which is out of bounds.]
            push(stack,top,number);
        } else if(number==0){
            pop(stack,top);
            top--; // @@ [Decrementing 'top' even when the stack is empty (i.e., pop printed "error ") causes 'top' to go below -1, corrupting the stack state. The decrement should only happen if the pop was successful.]
        }
    }
    return 0;
}