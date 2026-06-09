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
            printf("%d ",b[flag+1]); @@ [When popping, the element should be taken from index 'flag' (after decrement), but here it uses 'flag+1', which points to an incorrect/uninitialized location. Also, 'flag' is being used as both size and index inconsistently.]
            j=flag+1; @@ [This assignment to 'j' is incorrect; 'j' should represent the next available index in 'b' for push, but it's being overwritten with 'flag+1', breaking future pushes.]
        }
    }
   }
    return 0;
}