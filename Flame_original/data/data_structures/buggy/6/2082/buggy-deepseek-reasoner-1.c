#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    int a[100],b[100],i=0,j=0,n,m,n1,flag=0;
   while(scanf("%d",&n)!=-1){ // @@ Input termination condition incorrect; should break when n==-1, and not store -1.
       a[i]=n;
       i++;
       n1=i;
   }
   for(i=0;i<=n1;i++){ // @@ Loop bound should be i<n1, not i<=n1, to avoid accessing a[n1] which is out of array bounds.
       if(a[i]==1){ // @@ Incorrect processing; the array contains both operation codes and data values, but this treats data values as operations. Should process sequentially: read while not -1, and for each operation, handle push/pop immediately.
           b[j]=a[i+1]; // @@ No overflow check; also i+1 may be out of bounds.
           j++;
           flag++; // @@ Inconsistent stack top management; flag should be number of elements, but pop logic uses flag+1 incorrectly.
       }
    if(a[i]==0){
        flag--; // @@ Pop decrements flag before output, causing off-by-one error. Should output b[flag] then decrement.
        if(flag<0){
            printf("error ");
        }
        else{
            printf("%d ",b[flag+1]); // @@ Incorrect index; should be b[flag] after decrement to output the popped element.
            j=flag+1; // @@ Unnecessary and incorrect reset of push index j; should not modify j on pop.
        }
    }
   }
    return 0;
}