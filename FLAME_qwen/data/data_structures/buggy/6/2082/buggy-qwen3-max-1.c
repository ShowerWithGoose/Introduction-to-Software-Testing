#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    int a[100],b[100],i=0,j=0,n,m,n1,flag=0;
   while(scanf("%d",&n)!=-1){ // @@ [The loop condition is incorrect; it should check for input equal to -1 to terminate, not for scanf return value being -1. Also, this causes infinite loop or undefined behavior because scanf returns number of items read, not the value itself.]
       a[i]=n;
       i++;
       n1=i;
   }
   for(i=0;i<=n1;i++){ // @@ [Loop runs one extra iteration (i <= n1 instead of i < n1), accessing uninitialized memory beyond the last valid input.]
       if(a[i]==1){
           b[j]=a[i+1]; // @@ [When a[i] == 1, the next element a[i+1] is used as the value to push, but the loop may go out of bounds if the last operation is 1 without a following number. Also, i+1 may exceed array bounds.]
           j++;
           flag++;
       }
    if(a[i]==0){
        flag--; // @@ [flag is decremented before checking if stack is empty, leading to incorrect underflow detection and wrong index calculation.]
        if(flag<0){
            printf("error ");
        }
        else{
            printf("%d ",b[flag+1]); // @@ [After decrementing flag, b[flag+1] refers to the element that was just popped, but due to premature decrement and incorrect indexing, this may access wrong or invalid data. Also, 'j' is reassigned unnecessarily.]
            j=flag+1; // @@ [This line incorrectly modifies j, which breaks the stack pointer logic; j should represent top of stack but is being overwritten.]
        }
    }
   }
    return 0;
}