#include <stdio.h>
#include <stdlib.h>
int a[99];


int main(){
    int n,k;
    while(1){
        scanf("%d",&n);
        int i=0,j=0; // @@ [Error: The variable i is reinitialized to 0 on every iteration of the while loop, so it never tracks the actual stack top across multiple operations. It should be declared outside the loop.]
        if(n==1){
            if(i<=99){ // @@ [Error: The condition should check if the stack is not full (i < 99) before pushing, but i is always 0 due to reinitialization, so this check is ineffective.]
                scanf("%d",&k); 
                a[i]=k;i++;} // @@ [Error: The push should use the current stack top index, but due to i being reset, it always writes to a[0] and increments to 1, losing previous data.]
        }
        else if(n==0){
            if(i>=0&&i<=99){ // @@ [Error: The pop condition should check if the stack is not empty (i > 0), but i is always 0 or 1, so it incorrectly pops from index 0 or 1, and the index i is decremented before the pop, causing wrong output.]
                printf("%d ",a[i]); // @@ [Error: Should print a[i-1] after decrementing i, but here it prints a[i] before decrement, leading to out-of-bounds or wrong element access.]
                i--;
            }
            else printf("error ");
        }
        else if(n==-1)
            break;
    }
}