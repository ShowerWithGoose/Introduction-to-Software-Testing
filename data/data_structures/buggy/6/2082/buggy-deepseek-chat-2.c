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
   for(i=0;i<=n1;i++){ // @@ The loop condition should be i < n1, not i <= n1, because n1 is the count of elements read, and array indices go from 0 to n1-1. Using <= causes an out-of-bounds access when i equals n1.
       if(a[i]==1){
           b[j]=a[i+1];
           j++;
           flag++;
       }
    if(a[i]==0){
        flag--;
        if(flag<0){
            printf("error ");
        }
        else{
            printf("%d ",b[flag+1]); // @@ The index should be flag (after decrement), not flag+1. When flag is decremented, it represents the new top index (0-based), so b[flag] is the correct element to pop. Using flag+1 accesses the wrong element and can cause out-of-bounds access.
            j=flag+1; // @@ This line is unnecessary and incorrect; j is not used consistently as a stack pointer, and modifying it here does not help. The stack pointer should be managed by flag alone.
        }
    }
   }
    return 0;
}