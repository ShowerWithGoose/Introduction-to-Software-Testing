#include <stdio.h>
#include <stdlib.h>
int a[99];


int main(){
    int n,k;
    int i=0; // @@ The variable 'i' (stack pointer) is declared inside the while loop, causing it to reset to 0 in every iteration. It must be declared outside to maintain state.
    while(1){
        scanf("%d",&n);
        // int i=0,j=0; // @@ Removed from here as it was resetting the stack pointer.
        if(n==1){
            if(i<99){ // @@ Changed condition to i<99 to prevent overflow, assuming capacity 99 based on array size, or i<100 if capacity is 100. Original logic i<=99 with a[99] is risky if 100 elements are pushed. Also, the original code had 'i' local here which was wrong.
                scanf("%d",&k); 
                a[i]=k;i++;}
        }
        else if(n==0){
            if(i>0){ // @@ Check if stack is not empty (i > 0). Original check i>=0 is always true for unsigned-like logic or doesn't protect against underflow correctly if i is 0.
                i--; // @@ Decrement index first to point to the top element.
                printf("%d ",a[i]); // @@ Print the element at the current top index.
            }
            else printf("error ");
        }
        else if(n==-1)
            break;
    }
}