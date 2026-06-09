#include <stdio.h>
#include <stdlib.h>
int a[99]; // @@ [The stack capacity should be 100, but array size is 99, causing potential out-of-bounds access when pushing 100 elements]


int main(){
    int n,k;
    while(1){
        scanf("%d",&n);
        int i=0,j=0; // @@ [The stack pointer 'i' is reinitialized to 0 in every loop iteration, so the stack state is not preserved across operations]
        if(n==1){
            if(i<=99){ // @@ [Since 'i' is always 0 at this point due to reinitialization, this condition always passes even if the stack should be full]
                scanf("%d",&k); 
                a[i]=k;i++;}
        }
        else if(n==0){
            if(i>=0&&i<=99){ // @@ [Again, 'i' is always 0 here, so this condition passes, but accessing a[i] (a[0]) when stack is logically empty is incorrect; also, pop should access top element at i-1]
                printf("%d ",a[i]); // @@ [Should print a[i-1] because 'i' represents next available index, not current top]
                i--;
            }
            else printf("error ");
        }
        else if(n==-1)
            break;
    }
}