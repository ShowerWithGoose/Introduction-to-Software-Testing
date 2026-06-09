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
   for(i=0;i<=n1;i++){ // @@ The loop condition should be i < n1, not i <= n1, because n1 is the count of elements, so the last valid index is n1-1. Using <= causes an out-of-bounds access when i equals n1.
       if(a[i]==1){
           b[j]=a[i+1]; // @@ This assumes the next element after 1 is the value to push, but the input format uses 1 followed by the value as separate integers. However, the loop increments i by 1 each time, so when a[i]==1, a[i+1] is the next integer in the array, which is correct. But the problem is that the loop also processes the value as a separate operation later, causing double processing. Additionally, there is no check for stack overflow (j >= 100).
           j++;
           flag++;
       }
    if(a[i]==0){
        flag--;
        if(flag<0){
            printf("error ");
        }
        else{
            printf("%d ",b[flag+1]); // @@ The index should be flag (since b[0] is the first pushed element, and after decrementing flag, flag points to the last pushed element). Using flag+1 accesses the wrong element. Also, j is set to flag+1 but j is not used correctly elsewhere.
            j=flag+1;
        }
    }
   }
    return 0;
}