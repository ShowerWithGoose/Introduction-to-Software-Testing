#include<stdio.h>
#define max 100
int top=-1;


void push(int stack[],int top,int number){
    if(top==max-1){
        printf("error ");
        
    }else{
    
        stack[top]=number; // @@ The parameter 'top' is passed by value, so modifying it inside the function does not affect the global 'top'. Also, the push should assign to stack[top] after incrementing, but here it assigns before incrementing, causing the wrong index.
        
    }
        
}
void pop(int stack[],int top){
    if(top==-1){
        printf("error ");
    }else{
    printf("%d ",stack[top]); // @@ The parameter 'top' is passed by value, so it uses the current top value before decrementing in main. This prints the element at the current top, but the pop should print the element at the top and then decrement. Since top is passed by value, the decrement in main happens after, but the index used here is one too high because top was already incremented in push before storing.
    
    
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
            push(stack,top,number); // @@ 'top' is passed by value, so the push function cannot update the global top. Additionally, top is incremented before calling push, but push uses the incremented top as the index, which is correct for storing, but the function does not actually use the global top.
        } else if(number==0){
            pop(stack,top); // @@ 'top' is passed by value, so pop uses the current top value, but then main decrements top after the call. This means pop prints the element at the current top (which is the last pushed element), but the global top is decremented afterwards, causing the next pop to print the same element again or an incorrect element.
            top--;
        }
    }
    return 0;
}