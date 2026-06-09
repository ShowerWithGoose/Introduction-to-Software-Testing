#include <stdio.h>
#include <stdlib.h>
int a[99]; // @@ [Error: Array size should be 100 to match maximum capacity. Also indices 0-98, so condition i<=99 leads to out-of-bounds.]

int main(){
    int n,k;
    while(1){
        scanf("%d",&n);
        int i=0,j=0; // @@ [Error: i and j are reinitialized each loop iteration, so the stack pointer does not persist. Must declare i outside the loop.]
        if(n==1){
            if(i<=99){ // @@ [Error: i is always 0 due to reinitialization, and i<=99 includes i=99 which is out of bounds (array size 99). Should be i<99 or use capacity 100.]
                scanf("%d",&k); 
                a[i]=k;i++;
            }
        }
        else if(n==0){
            if(i>=0&&i<=99){ // @@ [Error: i is always 0 due to reinitialization, so condition always true even when stack is empty. Also pop should check i>0, and printing a[i] is incorrect; should print a[--i].]
                printf("%d ",a[i]);
                i--;
            }
            else printf("error ");
        }
        else if(n==-1)
            break;
    }
}