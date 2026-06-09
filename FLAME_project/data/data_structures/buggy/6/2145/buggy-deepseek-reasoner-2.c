#include <stdio.h>
#include <stdlib.h>
int a[99];


int main(){
    int n,k;
    while(1){
        scanf("%d",&n);
        int i=0,j=0; @@ // [Error: i is reinitialized to 0 each loop iteration, so the stack index is not persistent. This causes all pushes to overwrite a[0] and all pops to read a[0], producing repeated last pushed value.]
        if(n==1){
            if(i<=99){ @@ // [Error: Condition should check i < 99 (or i < 100 with bigger array) to avoid overflow, but since i resets, this check is moot. However, even with persistent i, this condition incorrectly allows push when i is 99 (array index out of bounds).]
                scanf("%d",&k); 
                a[i]=k;i++;}
        }
        else if(n==0){
            if(i>=0&&i<=99){ @@ // [Error: Condition should check i > 0 (stack non-empty) to pop valid element. Printing a[i] when i is the next empty index yields uninitialized or wrong value. Also i is reset so this logic fails entirely.]
                printf("%d ",a[i]);
                i--;
            }
            else printf("error ");
        }
        else if(n==-1)
            break;
    }
}