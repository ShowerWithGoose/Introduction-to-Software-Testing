#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    int a[100],b[100],i=0,j=0,n,m,n1,flag=0;
   while(scanf("%d",&n)!=-1){
       a[i]=n;
       i++;
       n1=i;
   }
   for(i=0;i<=n1;i++){ // @@ The loop condition should be i < n1, not i <= n1, because n1 is the count of elements, and the last valid index is n1-1. Using <= causes an out-of-bounds access when i equals n1.
       if(a[i]==1){
           b[j]=a[i+1]; // @@ This assumes the next element after 1 is the value to push, but the input format uses "1 value" as separate integers. However, the loop increments i by 1 each iteration, so when a[i]==1, a[i+1] is the next input integer, which is correct. But the loop will also process a[i+1] as a separate operation later, causing duplicate processing. The logic should skip the value after 1.
           j++;
           flag++;
       }
    if(a[i]==0){
        flag--;
        if(flag<0){
            printf("error ");
        }
        else{
            printf("%d ",b[flag+1]); // @@ The index should be flag (since flag is the current stack size after decrement), not flag+1. b[flag] is the top element. Also, j is not used correctly here; j should track the stack top index.
            j=flag+1; // @@ This assignment is incorrect; j should be set to flag (the new top index) after pop.
        }
    }
   }
    return 0;
}