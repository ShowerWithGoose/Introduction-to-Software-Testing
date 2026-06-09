#include <stdio.h>
#include <stdlib.h>
int a[99]; // @@ [The stack capacity should be 100, but array size is 99, which allows only indices 0-98 (99 elements).]


int main(){
    int n,k;
    while(1){
        scanf("%d",&n);
        int i=0,j=0; // @@ [The stack pointer 'i' is reinitialized to 0 in every loop iteration, so the stack state is not preserved across operations.]
        if(n==1){
            if(i<=99){ // @@ [Since 'i' is always 0 at this point due to reinitialization, this condition always passes even when stack is logically full. Also, array only has 99 elements, so max valid index is 98.]
                scanf("%d",&k); 
                a[i]=k;i++;}
        }
        else if(n==0){
            if(i>=0&&i<=99){ // @@ ['i' is always 0 here due to reinitialization, so pop will try to access a[0] even if nothing was pushed in this iteration. Also, after push, i becomes 1, but next iteration resets it to 0, breaking stack logic.]
                printf("%d ",a[i]); // @@ [Should print a[i-1] because 'i' points to next empty slot; also, accessing a[i] when i==0 is invalid (empty stack).]
                i--;
            }
            else printf("error ");
        }
        else if(n==-1)
            break;
    }
}