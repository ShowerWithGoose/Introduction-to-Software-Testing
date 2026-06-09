#include <stdio.h>
#include <stdlib.h>
int a[99]; // @@ The array size should be 100 to match the maximum capacity of 100, not 99. Also, the array should be declared inside main or as a global with proper size.

int main(){
    int n,k;
    while(1){
        scanf("%d",&n);
        int i=0,j=0; // @@ The variable i should be declared outside the while loop to maintain the stack pointer across iterations. Declaring it inside resets i to 0 each time, causing incorrect behavior.
        if(n==1){
            if(i<=99){ // @@ The condition should check if i < 100 (or i <= 99) for a stack of size 100, but since i is reset, this logic is flawed. Also, the error message for stack full is missing.
                scanf("%d",&k); 
                a[i]=k;i++;}
        }
        else if(n==0){
            if(i>=0&&i<=99){ // @@ The condition should check if i > 0 to pop from a non-empty stack. Also, the pop should decrement i before accessing the element (i.e., a[--i]), not after. The current code prints a[i] and then decrements, which accesses an uninitialized or wrong element.
                printf("%d ",a[i]);
                i--;
            }
            else printf("error ");
        }
        else if(n==-1)
            break;
    }
}