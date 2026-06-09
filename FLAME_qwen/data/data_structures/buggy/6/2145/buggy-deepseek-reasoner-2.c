#include <stdio.h>
#include <stdlib.h>
int a[99]; // @@ [Array size should be 100 to support maximum capacity of 100; current size 99 leads to out-of-bounds on push when stack full and cannot hold 100th element.]


int main(){
    int n,k;
    while(1){
        scanf("%d",&n);
        int i=0,j=0; // @@ [Stack index i must be declared outside the loop to persist between operations; declaring it here resets it every iteration. Also j is unused.]
        if(n==1){
            if(i<=99){ // @@ [Condition should check if stack is not full (i < 100 for array size 100); also missing "error " output when push attempted on full stack.]
                scanf("%d",&k); 
                a[i]=k;i++;
            }
        }
        else if(n==0){
            if(i>=0&&i<=99){ // @@ [Condition should check if stack is non-empty (i > 0); also pop operation should output a[--i] (decrement before print) instead of printing a[i] then decrementing.]
                printf("%d ",a[i]);
                i--;
            }
            else printf("error ");
        }
        else if(n==-1)
            break;
    }
}