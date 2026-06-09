#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    int a[100],b[100],i=0,j=0,n,m,n1,flag=0;
   while(scanf("%d",&n)!=-1){ // @@ Error: This loop does not stop when -1 is read; it reads until EOF, including the -1 as a normal number. Should break when n == -1.
       a[i]=n;
       i++;
       n1=i;
   }
   for(i=0;i<=n1;i++){ // @@ Error: Loop condition i<=n1 causes out-of-bounds access when i == n1 (since valid indices are 0 to n1-1). Also, the loop should stop when encountering the -1 terminator.
       if(a[i]==1){ // @@ Error: Missing check for stack full (j==100) before push. Should print "error " and skip pushing when stack is full.
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
            printf("%d ",b[flag+1]); // @@ Error: Wrong index for popped element. After flag--, the top element is at index flag (0‑based), not flag+1. Should be b[flag].
            j=flag+1; // @@ Error: Unnecessary and incorrect assignment to j. j is not used for pops and this sets it to an incorrect value.
        }
    }
   }
    return 0;
}