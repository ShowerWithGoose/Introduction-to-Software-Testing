#include <stdio.h>
#include <stdlib.h>
int a[99];


int main(){
    int n,k;
    while(1){
        scanf("%d",&n);
        int i=0,j=0; @@ // The variables i and j are reinitialized to 0 in every iteration, so stack state is lost between operations.
        if(n==1){
            if(i<=99){ @@ // i is always 0 here due to reinitialization, so this condition is always true but doesn't reflect actual stack size.
                scanf("%d",&k); 
                a[i]=k;i++;} @@ // Pushing always happens at index 0, overwriting previous values instead of appending.
        }
        else if(n==0){
            if(i>=0&&i<=99){ @@ // i is always 0 or negative after decrement, leading to incorrect pop behavior.
                printf("%d ",a[i]); @@ // Accessing a[i] when i is 0 after decrement leads to undefined behavior; should access a[i-1].
                i--;
            }
            else printf("error ");
        }
        else if(n==-1)
            break;
    }
}