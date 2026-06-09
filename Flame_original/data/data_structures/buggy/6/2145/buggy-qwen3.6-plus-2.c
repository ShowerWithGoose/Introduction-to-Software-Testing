#include <stdio.h>
#include <stdlib.h>
int a[99]; // @@ Array size is 99, but the maximum stack capacity is 100, causing out-of-bounds access when pushing the 100th element.


int main(){
    int n,k;
    while(1){
        scanf("%d",&n);
        int i=0,j=0; // @@ The stack pointer 'i' is declared inside the loop, resetting to 0 on every iteration and losing the stack state across operations.
        if(n==1){
            if(i<=99){ // @@ Incorrect condition for checking stack full. Should check if i == 100 to match the capacity, and array size should be 100.
                scanf("%d",&k);
                a[i]=k;i++;}
        }
        else if(n==0){
            if(i>=0&&i<=99){ // @@ Incorrect condition for checking stack empty. Should check if i == 0 to prevent popping from an empty stack.
                printf("%d ",a[i]); // @@ Incorrect pop logic: accesses a[i] before decrementing i, which prints an uninitialized or wrong element. Should use a[--i].
                i--;
            }
            else printf("error ");
        }
        else if(n==-1)
            break;
    }
}