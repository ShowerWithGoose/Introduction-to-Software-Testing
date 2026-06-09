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
   for(i=0;i<=n1;i++){
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
            printf("%d ",b[flag+1]); @@ [When popping, it should print b[flag] (after decrementing flag) or b[j-1], but here it prints b[flag+1] which is incorrect indexing. Also, 'j' is not properly synchronized with 'flag'.]
            j=flag+1; @@ [This assignment corrupts the stack pointer 'j'; 'j' should represent the next available index in the stack, but it's being overwritten based on 'flag', leading to inconsistent state.]
        }
    }
   }
    return 0;
}