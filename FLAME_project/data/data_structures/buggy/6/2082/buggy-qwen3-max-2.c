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
   for(i=0;i<=n1;i++){ @@ // Loop runs one iteration too far (i <= n1 instead of i < n1), accessing uninitialized memory beyond the last valid input.
       if(a[i]==1){
           b[j]=a[i+1]; @@ // When i == n1 - 1, a[i+1] is out of bounds; also, this assumes next element exists without checking.
           j++;
           flag++;
       }
    if(a[i]==0){
        flag--; @@ // flag is used as stack pointer but decremented before use, leading to off-by-one errors.
        if(flag<0){
            printf("error ");
        }
        else{
            printf("%d ",b[flag+1]); @@ // Should print b[flag] after decrementing, not b[flag+1]; current logic prints wrong index.
            j=flag+1; @@ // Unnecessary and incorrect update of j; j should represent top of stack, but is being overwritten incorrectly.
        }
    }
   }
    return 0;
}