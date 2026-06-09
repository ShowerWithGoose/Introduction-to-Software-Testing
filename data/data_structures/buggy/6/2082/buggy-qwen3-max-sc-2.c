#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    int a[100],b[100],i=0,j=0,n,m,n1,flag=0;
   while(scanf("%d",&n)!=-1){ // @@ [The loop condition is incorrect. scanf returns the number of successfully read items, not the value read. It should check for EOF (which is -1), but the condition `!= -1` will always be true because scanf returns 1 on success and EOF (typically -1) on failure. However, the bigger issue is that the input ends with -1 as a sentinel value, not EOF. So this loop never stops at -1 as intended.]
       a[i]=n;
       i++;
       n1=i;
   }
   for(i=0;i<=n1;i++){ // @@ [Loop goes one past the last valid index. Since n1 = i after reading all inputs, and i was incremented after storing the last value, the valid indices are 0 to n1-1. This loop runs up to i == n1, which accesses a[n1], an uninitialized element. Also, if the input ends with -1, it's stored in the array and processed, but shouldn't be.]
       if(a[i]==1){
           b[j]=a[i+1]; // @@ [Accesses a[i+1] without checking if i+1 is within bounds. If the last element is 1, this reads beyond the array. Also, j is used as stack top but not managed correctly.]
           j++;
           flag++;
       }
    if(a[i]==0){
        flag--; // @@ [flag is decremented before checking if stack is empty. This causes underflow logic to be off by one.]
        if(flag<0){
            printf("error ");
        }
        else{
            printf("%d ",b[flag+1]); // @@ [After decrementing flag, the top element should be at index flag (not flag+1). This prints the wrong element. Also, j is not updated consistently with flag, leading to confusion between j and flag as stack pointers.]
            j=flag+1; // @@ [This assignment is unnecessary and inconsistent. j should represent the next available slot or current top, but it's being overwritten arbitrarily.]
        }
    }
   }
    return 0;
}