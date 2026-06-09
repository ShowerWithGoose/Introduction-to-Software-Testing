#include<stdio.h>
#define max 100
int top=-1;


void push(int stack[],int top,int number){
    if(top==max-1){ // @@ top is incremented in main before calling push, so when top equals max, it's out of bounds. This condition incorrectly prevents pushing the 100th element. It should check if top >= max.
        printf("error ");
        
    }else{
    
        stack[top]=number;
        
    }
        
}
void pop(int stack[],int top){
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
            top++; // @@ top is incremented unconditionally before checking if the stack is full. If the stack is full, top will exceed the valid range, corrupting the stack state.
            push(stack,top,number);
        } else if(number==0){
            pop(stack,top);
            top--; // @@ top is decremented unconditionally after calling pop. If the stack is empty, pop prints "error " but top still decrements, causing top to become less than -1 and leading to undefined behavior.
        }
    }
    return 0;
}