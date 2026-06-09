#include<stdio.h>
#define max 100
int top=-1;


void push(int stack[],int top,int number){ // @@ parameter 'top' shadows global, but design error: increment should be inside function after check
    if(top==max-1){ // @@ condition incorrect: top already incremented, should check before increment
        printf("error ");
        
    }else{
    
        stack[top]=number; // @@ may write out of bounds if top==max (when stack full)
        
    }
        
}
void pop(int stack[],int top){ // @@ parameter 'top' shadows global, but main handles decrement incorrectly
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
            top++; // @@ increment before push: should check full first; leads to out-of-bounds on full stack
            push(stack,top,number);
        } else if(number==0){
            pop(stack,top);
            top--; // @@ decrement unconditionally: should only decrement if pop succeeded; causes top to become -2 on empty stack
        }
    }
    return 0;
}