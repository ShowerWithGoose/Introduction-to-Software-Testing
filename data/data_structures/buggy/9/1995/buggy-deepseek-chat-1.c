#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define arrLen(x) (sizeof(x)/sizeof(x[0]))
struct x{
    int a[2];
    int b[2];
}x[101],temp;
int main(){
    int n,flag=0,l=1,max=0,c,d,k,i=0,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d%d%d",&x[i].a[0],&x[i].a[1],&x[i].b[0],&x[i].b[1]);
    }        
    for(i=0;i<n;i++){        
    flag=0;
    for(j=i+1;j<n;j++){
        if(x[j].a[0]<x[i].a[0]){
            temp=x[j];
            x[j]=x[i];
            x[i]=temp;
            flag=1;
            }        
        }
        if(flag==0)break; // @@ This break exits the outer loop prematurely when no swap occurs for a given i, but the sorting may not be complete. The bubble sort logic is incorrect; it should continue until the array is fully sorted.
    }
    for(i=0;i<n;i++){
        l=1;
        k=i;
        for(j=i+1;j<n;j++){
            if(x[j].a[0]==x[k].b[0]&&x[j].a[1]==x[k].b[1]){
                l++;
                k=j;
            }else break; // @@ This break stops the inner loop at the first non-matching segment, but segments may be out of order after sorting, causing valid connections to be missed. The loop should continue to check all remaining segments.
        }
        if(l>max){
            max=l;
            c=x[i].a[0];
            d=x[i].a[1];
        }
        i=j-1; // @@ This modifies the loop variable i, which can cause incorrect iteration and skip segments. The outer loop should not be manually adjusted in this way.
    }
printf("%d %d %d",max,c,d);
return 0;
}