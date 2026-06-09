#include <stdio.h>
#include <stdlib.h>
int a[99]; // @@ Array size should be at least 100 to accommodate the maximum stack capacity of 100.


int main(){
    int n,k;
    while(1){
        scanf("%d",&n);
        int i=0,j=0; // @@ Variable 'i' acts as the stack pointer but is reinitialized to 0 in every loop iteration, causing the stack state to be lost. It should be declared outside the loop.
        if(n==1){
            if(i<=99){ // @@ Condition should be 'i < 100' to correctly check if the stack is full, and prevents out-of-bounds access when array size is corrected.
                scanf("%d",&k); 
                a[i]=k;i++;}
        }
        else if(n==0){
            if(i>=0&&i<=99){ // @@ Condition should be 'i > 0' to check if the stack is not empty. 'i >= 0' incorrectly allows popping when the stack is empty.
                printf("%d ",a[i]); // @@ Should print 'a[i-1]' because 'i' points to the next free slot, not the current top element.
                i--;
            }
            else printf("error ");
        }
        else if(n==-1)
            break;
    }
}