#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    int a[100],b[100],i=0,j=0,n,m,n1,flag=0;
   while(scanf("%d",&n)!=-1){ // @@ The loop condition scanf("%d",&n)!=-1 will not terminate correctly on -1 as a data value because -1 is a valid return for EOF, but more importantly, the logic inside assumes all inputs are stored in 'a' sequentially without distinguishing operations from data properly during the read phase. Also, if input ends with -1, it gets stored in array 'a'.
       a[i]=n;
       i++;
       n1=i;
   }
   for(i=0;i<=n1;i++){ // @@ Loop bound i<=n1 accesses one element beyond the last stored index if n1 is the count. It should be i<n1. Additionally, the logic for handling push/pop is flawed.
       if(a[i]==1){
           b[j]=a[i+1]; // @@ This assumes the next integer in the flat array 'a' is the value to push. However, 'a' contains the raw sequence including 1, 0, -1. If a[i] is 1, a[i+1] is indeed the value. But 'j' is used as a stack pointer incorrectly later.
           j++;
           flag++;
       }
    if(a[i]==0){
        flag--;
        if(flag<0){
            printf("error ");
        }
        else{
            printf("%d ",b[flag+1]); // @@ The stack implementation is incorrect. 'b' is being used like a stack but indexed by 'flag+1'. Standard stack pop should retrieve the top element. If 'flag' represents the current size (decremented before use here), the top element is at index 'flag' (if 0-indexed and flag is new size) or similar. Let's trace: Push 567. flag becomes 1. j becomes 1. b[0]=567. Pop. flag becomes 0. Prints b[1]. b[1] is uninitialized or wrong. It should print b[0]. The indexing logic for the stack 'b' is wrong.
            j=flag+1;
        }
    }
   }
    return 0;
}