#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    int a[100],b[100],i=0,j=0,n,m,n1,flag=0;
   while(scanf("%d",&n)!=-1){ // @@ [The loop condition is incorrect. scanf returns the number of successfully read items, not the value read. It should check for EOF (which is -1), but the condition `!= -1` will always be true because scanf returns 1 on success and EOF (-1) on failure. However, the bigger issue is that this loop never terminates on input ending with -1 because it keeps reading until EOF, not until the value -1 is encountered.]
       a[i]=n;
       i++;
       n1=i;
   }
   for(i=0;i<=n1;i++){ // @@ [Loop goes one past the last valid index. Since n1 = i after the last successful read, and i was incremented after storing the last value, the valid indices are 0 to n1-1. Using <= n1 accesses a[n1], which is uninitialized or beyond the stored data. Also, if the input ends with -1, it's stored in the array and processed, but shouldn't be.]
       if(a[i]==1){
           b[j]=a[i+1]; // @@ [This accesses a[i+1] without checking if i+1 is within bounds. If the last element is 1, then a[i+1] is out of bounds. Also, the next element might be -1 (end marker), which should not be pushed.]
           j++;
           flag++;
       }
    if(a[i]==0){
        flag--; // @@ [flag is decremented before checking if stack is empty. This causes incorrect indexing and logic. Also, 'flag' is being used as both stack size and index, leading to confusion.]
        if(flag<0){
            printf("error ");
        }
        else{
            printf("%d ",b[flag+1]); // @@ [Incorrect index: after decrementing flag, the top element should be at index 'flag' (if flag was the count before pop), but here it uses flag+1 which points to an already popped or invalid location.]
            j=flag+1; // @@ [Unnecessary and incorrect update of j, which breaks the stack pointer management.]
        }
    }
   }
    return 0;
}