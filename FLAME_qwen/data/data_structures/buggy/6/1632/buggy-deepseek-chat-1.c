#include<stdio.h>
#define max 100
int top=-1;


void push(int stack[],int top,int number){ // @@ [The 'top' parameter shadows the global variable 'top'. The function receives a copy of the global top, so modifications to the parameter do not affect the global top. The push operation should use the global top variable, not a parameter.]
    if(top==max-1){
        printf("error ");
        
    }else{
    
        stack[top]=number; // @@ [Since the parameter 'top' is a copy, this assigns to the wrong index. It should increment the global top first, then assign: stack[++top]=number, but top here is the parameter, not the global variable.]
        
    }
        
}
void pop(int stack[],int top){ // @@ [Similar issue: the 'top' parameter shadows the global variable. The function receives a copy, so decrementing the parameter does not affect the global top. The pop operation should use the global top variable.]
    if(top==-1){
        printf("error ");
    }else{
    printf("%d ",stack[top]); // @@ [This prints the element at the current top, but does not decrement the global top. It should print and then decrement the global top: printf("%d ",stack[top--]) but top here is the parameter.]
    
    
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
            push(stack,top,number); // @@ [Passing the incremented global top as an argument, but the function uses its own parameter, so the global top is not used correctly inside push.]
        } else if(number==0){
            pop(stack,top); // @@ [Passing the current global top as an argument, but the function uses its own parameter, so the global top is not decremented correctly.]
            top--; // @@ [This decrements the global top after pop, but pop already printed the element at the wrong index (the parameter top, not the global top). The global top decrement here is out of sync with the actual stack operations.]
        }
    }
    return 0;
}