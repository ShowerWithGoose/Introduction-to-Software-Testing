#include<stdio.h>
#define max 100
int top=-1;


void push(int stack[],int top,int number){
    if(top==max-1){
        printf("error ");
        
    }else{
    
        stack[top]=number; // @@ [Error: The push function receives `top` by value, so modifying `stack[top]` does not update the global `top` variable. Additionally, `top` is incremented before calling push in main, so the element is placed at the wrong index. The global `top` should be passed by reference or the function should use the global variable directly.]
        
    }
        
}
void pop(int stack[],int top){
    if(top==-1){
        printf("error ");
    }else{
    printf("%d ",stack[top]); // @@ [Error: The pop function receives `top` by value, so it uses the current value of `top` before decrementing in main. This causes it to print the element at the wrong index (the one just pushed, not the one to be popped). The global `top` should be passed by reference or the function should use the global variable directly.]
    
    
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
            top++; // @@ [Error: `top` is incremented before calling push, but push uses the new `top` value as an index, causing the element to be placed at the wrong position. The increment should happen inside push after storing the element, or the index should be `top-1` in push.]
            push(stack,top,number);
        } else if(number==0){
            pop(stack,top);
            top--; // @@ [Error: `top` is decremented after calling pop, but pop uses the current `top` value (which is the index of the last pushed element). This causes the pop to print the wrong element (the one just pushed) instead of the top element. The decrement should happen before or inside pop.]
        }
    }
    return 0;
}