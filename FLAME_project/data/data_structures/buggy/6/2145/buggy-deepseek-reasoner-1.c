#include <stdio.h>
#include <stdlib.h>
int a[99];


int main(){
    int n,k;
    while(1){
        scanf("%d",&n);
        int i=0,j=0; // @@ 'i' and 'j' are declared inside the loop, causing the stack pointer to reset each iteration. It should be declared outside the loop (e.g., before while).
        if(n==1){
            if(i<=99){
                scanf("%d",&k); 
                a[i]=k;i++;}
        }
        else if(n==0){
            if(i>=0&&i<=99){ // @@ Condition should check if stack is non-empty (i > 0). Current condition i>=0 always true due to reset, never outputs "error" when popping empty.
                printf("%d ",a[i]); // @@ Should print the top element (a[i-1]) before decrementing i, then decrement. Currently prints a[i] which is the next free slot, giving wrong value.
                i--;
            }
            else printf("error ");
        }
        else if(n==-1)
            break;
    }
}