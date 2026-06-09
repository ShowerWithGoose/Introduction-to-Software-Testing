#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    int a[100],b[100],i=0,j=0,n,m,n1,flag=0;
   while(scanf("%d",&n)!=-1){ // @@ Loop does not stop at -1; should check n!=-1 and continue until -1 is read, not until EOF (though works if input ends after -1, but deviation from spec).
       a[i]=n;
       i++;
       n1=i;
   }
   for(i=0;i<=n1;i++){ // @@ Loop condition should be i < n1 to avoid accessing out-of-bounds index (a[n1] is not assigned).
       if(a[i]==1){
           b[j]=a[i+1]; // @@ No check for stack overflow (j>=100) and potential out-of-bounds if i+1 equals n1 (last element after 1 must exist, but loop bound may cause issue).
           j++;
           flag++;
       }
    if(a[i]==0){
        flag--;
        if(flag<0){
            printf("error ");
        }
        else{
            printf("%d ",b[flag+1]); // @@ Incorrect index; should be b[flag] because after decrement flag is the index of the popped element.
            j=flag+1; // @@ Incorrect update; should be j = flag (the new top index + 1) to maintain correct next empty slot.
        }
    }
   }
    return 0;
}