#include <stdio.h>
#include <stdlib.h>
int a[99];


int main(){
    int n,k;
    while(1){
        scanf("%d",&n);
        int i=0,j=0; // @@ [The variable 'i' is reinitialized to 0 in every iteration of the loop, so it cannot maintain the current stack size or top index across operations. This causes all push/pop operations to behave as if the stack is always empty or at index 0.]
        if(n==1){
            if(i<=99){ // @@ [Since 'i' is always 0 at this point due to reinitialization, this condition always passes, but the logic fails to track actual stack state. Also, array 'a' has size 99 (indices 0-98), so max capacity should be 99, but problem says max capacity is 100. However, the main bug is resetting 'i'.]
                scanf("%d",&k); 
                a[i]=k;i++;} // @@ [This pushes to a[0] every time because 'i' starts at 0 each loop. So all pushed values overwrite a[0], and subsequent pops read from incorrect or invalid indices.]
        }
        else if(n==0){
            if(i>=0&&i<=99){ // @@ ['i' is always 0 here too, so condition passes, but then it prints a[0] (which holds only the last pushed value) instead of the top of the stack. Also, when popping, it should access a[i-1], not a[i].]
                printf("%d ",a[i]); // @@ [Should be a[i-1] because 'i' represents count/next index, not current top index. But since 'i' is always 0, this accesses a[0] which was last written by the most recent push, leading to repeated output of the same value.]
                i--; // @@ [Decrementing 'i' after printing a[i] is wrong; also, since 'i' starts at 0 each loop, this becomes -1, but next iteration resets it to 0 again.]
            }
            else printf("error ");
        }
        else if(n==-1)
            break;
    }
}