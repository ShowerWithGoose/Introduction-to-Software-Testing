#include<stdio.h>
#define max 100
int top=-1;


void push(int stack[],int top,int number){ // @@ The function receives top by value, so modifications to top inside push do not affect the global top variable. This causes the stack to always push to the same index (0) and never update the global top.
    if(top==max-1){
        printf("error ");
        
    }else{
    
        stack[top]=number; // @@ Since top is a local copy, this always writes to stack[0] (or whatever value was passed), and the global top is never incremented.
        
    }
        
}
void pop(int stack[],int top){ // @@ Similarly, top is passed by value, so the global top is not decremented. The function prints the element at the passed top index, but the global top remains unchanged.
    if(top==-1){
        printf("error ");
    }else{
    printf("%d ",stack[top]); // @@ This prints the element at the local top index, but since the global top is not updated correctly, the wrong element may be printed.
    
    
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
            top++;
            push(stack,top,number); // @@ The global top is incremented before calling push, but push receives the new value of top as a copy. Inside push, it uses this value to write to the stack, but the global top is already incremented, so the next push will increment top again, leaving gaps in the stack.
        } else if(number==0){
            pop(stack,top); // @@ The global top is passed to pop, but pop does not modify it. After pop, top-- is executed, which decrements the global top, but the pop function already printed the element at the old top index. This is inconsistent with the push logic.
            top--;
        }
    }
    return 0;
}