#include <stdio.h>
#include <stdlib.h>
int a[99]; // @@ The array size should be 100 to match the maximum capacity of 100, not 99.

int main(){
    int n,k;
    while(1){
        scanf("%d",&n);
        int i=0,j=0; // @@ The variable i should be declared outside the loop to maintain its value across iterations; here it is reset to 0 each time.
        if(n==1){
            if(i<=99){ // @@ This condition should check if the stack is full (i == 100) and print "error" if so; also the array index should be i, not i-1.
                scanf("%d",&k); 
                a[i]=k;i++;}
        }
        else if(n==0){
            if(i>=0&&i<=99){ // @@ This condition should check if the stack is empty (i == 0) and print "error" if so; also the pop should print a[--i] not a[i] and then decrement.
                printf("%d ",a[i]); // @@ Should print a[--i] to get the top element and decrement i.
                i--;
            }
            else printf("error ");
        }
        else if(n==-1)
            break;
    }
}