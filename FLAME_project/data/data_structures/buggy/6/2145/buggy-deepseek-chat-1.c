#include <stdio.h>
#include <stdlib.h>
int a[99];


int main(){
    int n,k;
    while(1){
        scanf("%d",&n);
        int i=0,j=0; // @@ [The variable i is reinitialized to 0 on every iteration of the while loop, so the stack pointer never advances. This causes all pushes to overwrite the same position and all pops to read from the same index, leading to incorrect output.]
        if(n==1){
            if(i<=99){
                scanf("%d",&k); 
                a[i]=k;i++;}
        }
        else if(n==0){
            if(i>=0&&i<=99){ // @@ [The condition i>=0 is always true, but after a pop, i should be decremented before accessing the array. Here, i is used as the index before decrementing, so it accesses the wrong element (the next empty slot or out-of-bounds). Also, the condition should check if i>0 to avoid underflow.]
                printf("%d ",a[i]);
                i--;
            }
            else printf("error ");
        }
        else if(n==-1)
            break;
    }
}