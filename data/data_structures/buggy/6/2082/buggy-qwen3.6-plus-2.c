#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    int a[100],b[100],i=0,j=0,n,m,n1,flag=0;
   while(scanf("%d",&n)!=-1){ // @@ scanf returns the number of successfully read items, not the value. The loop should terminate when n == -1, e.g., while(scanf("%d",&n)==1 && n!=-1)
       a[i]=n;
       i++;
       n1=i;
   }
   for(i=0;i<=n1;i++){ // @@ Loop condition i<=n1 causes out-of-bounds access. Valid indices are 0 to n1-1, so it should be i<n1.
       if(a[i]==1){
           b[j]=a[i+1]; // @@ j and flag are both used as stack pointers but not synchronized correctly. Also missing check for stack full (flag >= 100). Should use b[flag] = a[i+1]; and check capacity.
           j++;
           flag++;
       }
    if(a[i]==0){
        flag--;
        if(flag<0){
            printf("error ");
        }
        else{
            printf("%d ",b[flag+1]); // @@ Incorrect index. After decrementing flag, the top element is at b[flag], not b[flag+1].
            j=flag+1; // @@ j should be updated to flag to stay synchronized, or j is redundant.
        }
    }
   }
    return 0;
}