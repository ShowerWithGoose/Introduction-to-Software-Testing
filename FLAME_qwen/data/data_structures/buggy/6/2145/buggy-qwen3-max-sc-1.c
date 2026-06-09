#include <stdio.h>
#include <stdlib.h>
int a[99]; // @@ [The stack capacity should be 100, but array size is 99, causing potential out-of-bounds access when pushing 100 elements]


int main(){
    int n,k;
    while(1){
        scanf("%d",&n);
        int i=0,j=0; // @@ [The stack pointer 'i' is reinitialized to 0 in every loop iteration, so the stack state is not preserved across operations]
        if(n==1){
            if(i<=99){ // @@ [This condition allows i=99, but since array size is 99 (indices 0-98), writing to a[99] is out-of-bounds. Also, 'i' is always 0 here due to reinitialization]
                scanf("%d",&k); 
                a[i]=k;i++;}
        }
        else if(n==0){
            if(i>=0&&i<=99){ // @@ ['i' is always 0 here due to reinitialization, so pop operation will try to access a[0] even when stack is logically empty. Also, after popping, it prints a[i] before decrementing, which is wrong indexing]
                printf("%d ",a[i]); // @@ [Should print a[i-1] because 'i' represents the next available index, not the top element's index]
                i--;
            }
            else printf("error ");
        }
        else if(n==-1)
            break;
    }
}