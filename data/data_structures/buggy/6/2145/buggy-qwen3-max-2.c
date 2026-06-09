#include <stdio.h>
#include <stdlib.h>
int a[99]; // @@ [The stack capacity should be 100, but array size is 99, causing potential out-of-bounds access when pushing 100 elements]


int main(){
    int n,k;
    while(1){
        scanf("%d",&n);
        int i=0,j=0; // @@ [The stack pointer 'i' is reinitialized to 0 in every loop iteration, so the stack state is not preserved across operations]
        if(n==1){
            if(i<=99){ // @@ [Since 'i' is always 0 at this point due to reinitialization, this condition always passes incorrectly even after many pushes]
                scanf("%d",&k); 
                a[i]=k;i++;}
        }
        else if(n==0){
            if(i>=0&&i<=99){ // @@ [Again, 'i' is always 0 here due to reinitialization, so pop tries to access a[0] even if nothing was pushed in this iteration, and decrements i to -1]
                printf("%d ",a[i]); // @@ [Should print a[i-1] or use pre-decrement; currently accesses one past the top (if stack were maintained correctly)]
                i--;
            }
            else printf("error ");
        }
        else if(n==-1)
            break;
    }
}