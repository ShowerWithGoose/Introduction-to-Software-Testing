#include <stdio.h>
#include <stdlib.h>
int a[99];


int main(){
    int n,k;
    int i=0; // @@ The variable 'i' (stack pointer) is declared inside the while loop, causing it to reset to 0 in every iteration. It must be declared outside to maintain state.
    while(1){
        scanf("%d",&n);
        // int i=0,j=0; // @@ Removed from here as it was resetting the stack pointer and 'j' is unused.
        if(n==1){
            if(i<99){ // @@ Changed condition to i<99 because array size is 99 (indices 0-98). Also, original logic 'i<=99' would allow out-of-bounds access if i was persistent.
                scanf("%d",&k); 
                a[i]=k;i++;}
        }
        else if(n==0){
            if(i>0){ // @@ Changed condition to i>0. If i==0, the stack is empty. Original 'i>=0' allows popping when empty, and accessing a[i] where i is the next free slot is incorrect for pop (should be a[i-1]).
                printf("%d ",a[i-1]); // @@ Should print a[i-1] because 'i' points to the next empty slot. The top element is at i-1.
                i--;
            }
            else printf("error ");
        }
        else if(n==-1)
            break;
    }
}