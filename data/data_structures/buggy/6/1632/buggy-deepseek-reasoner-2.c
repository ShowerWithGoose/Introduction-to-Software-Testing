#include<stdio.h>
#define max 100
int top=-1;


void push(int stack[],int top,int number){ // @@ [Parameter shadows global top. Function should use global top and increment it after checking fullness, but here it receives a copy, so changes are not reflected on global top. Also, the check for full uses the argument, but main already incremented top before calling, leading to incorrect full detection.]
    if(top==max-1){ // @@ [Uses local top, which after main's increment may be out-of-bounds. Should check global top before increment.]
        printf("error ");
        
    }else{
    
        stack[top]=number; // @@ [Assigns at the given index, but does not increment global top. Should be stack[++top] (with global top). As is, it assigns to the slot that is supposed to be the new top, but after main's increment that is correct, but if stack was full, this line still executes because full check failed due to wrong condition.]
        
    }
        
}
void pop(int stack[],int top){ // @@ [Parameter shadows global top. Function should decrement global top after printing, but here it only prints without modifying global top.]
    if(top==-1){ // @@ [Uses local top, which is a copy of global top. Check is correct for emptiness, but function does not handle decrement.]
        printf("error ");
    }else{
    printf("%d ",stack[top]); // @@ [Prints element at current top, but does not decrement global top. Should be followed by a decrement of global top, but since top is local, it cannot update global.]

    
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
            top++; // @@ [Increments global top before calling push. If the stack is full, this causes top to become max, leading to out-of-bounds access in push. Increment should be inside push after verifying stack is not full.]
            push(stack,top,number); // @@ [Passes the already-incremented top. The push function's full check (top==max-1) will never trigger because top is now max (not max-1). Additionally, push does not modify global top, so this call effectively pushes the value at index top, but if full, it writes out of bounds.]
        } else if(number==0){
            pop(stack,top); // @@ [Passes current global top. Pop function prints error if empty but does not indicate failure, so main unconditionally decrements top next line.]
            top--; // @@ [Decrements global top after pop, even if the stack was empty. This causes top to become less than -1, corrupting the stack state.]
        }
    }
    return 0;
}