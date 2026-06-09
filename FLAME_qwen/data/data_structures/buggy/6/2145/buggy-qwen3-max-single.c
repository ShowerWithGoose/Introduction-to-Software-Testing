#include <stdio.h>
#include <stdlib.h>
int a[99]; // @@ [The stack capacity should be 100, but array size is 99, causing potential out-of-bounds access when pushing 100 elements]


int main(){
    int n,k;
    while(1){
        scanf("%d",&n);
        int i=0,j=0; // @@ [The stack pointer 'i' is reinitialized to 0 in every loop iteration, so the stack state is not preserved across operations]
        if(n==1){
            if(i<=99){ // @@ [Condition should be i < 100 (or i < array_size) to prevent overflow; also, since i is always 0 here due to reinitialization, this check is meaningless]
                scanf("%d",&k); 
                a[i]=k;i++;}
        }
        else if(n==0){
            if(i>=0&&i<=99){ // @@ [When popping, should check if stack is empty (i == 0), not i>=0; also, accessing a[i] instead of a[i-1] leads to wrong element being printed or out-of-bounds read]
                printf("%d ",a[i]); // @@ [Should print a[i-1] because 'i' represents next available index; currently prints one past the top or uninitialized memory]
                i--;
            }
            else printf("error ");
        }
        else if(n==-1)
            break;
    }
}