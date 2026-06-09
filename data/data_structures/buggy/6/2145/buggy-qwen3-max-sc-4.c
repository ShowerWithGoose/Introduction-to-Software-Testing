#include <stdio.h>
#include <stdlib.h>
int a[99]; // @@ [The stack capacity should be 100, but array size is 99, causing potential out-of-bounds access when pushing 100 elements]


int main(){
    int n,k;
    while(1){
        scanf("%d",&n);
        int i=0,j=0; // @@ [The stack pointer 'i' is reinitialized to 0 in every loop iteration, so the stack state is not preserved across operations]
        if(n==1){
            if(i<=99){ // @@ [This condition allows i=99, which is valid for a 100-element stack (indices 0-99), but since array 'a' has only 99 elements (0-98), this leads to out-of-bounds write]
                scanf("%d",&k); 
                a[i]=k;i++;}
        }
        else if(n==0){
            if(i>=0&&i<=99){ // @@ [When popping, it prints a[i] before decrementing, but 'i' points to the next empty slot, so it should print a[i-1]. Also, condition i>=0 is always true here due to unsigned-like behavior, and doesn't correctly check for empty stack (i==0)]
                printf("%d ",a[i]);
                i--;
            }
            else printf("error ");
        }
        else if(n==-1)
            break;
    }
}