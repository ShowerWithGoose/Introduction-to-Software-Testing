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
        if(flag==0)break;
    }
    for(i=0;i<n;i++){
        l=1;
        k=i;
        for(j=i+1;j<n;j++){
            if(x[j].a[0]==x[k].b[0]&&x[j].a[1]==x[k].b[1]){
                l++;
                k=j;
            }else break; // @@ The logic assumes that segments forming a continuous line must be adjacent in the sorted array. However, sorting only by the starting x-coordinate does not guarantee that connected segments are contiguous in the array if there are other segments with starting x-coordinates in between. For example, if segment A ends at (7,8) and segment B starts at (7,8), but there is a segment C starting at x=5, sorting by start x might place C between A and B or disrupt the chain detection if the chain isn't strictly increasing in start x without gaps. More critically, the problem allows chains where segments connect end-to-start. The current loop breaks immediately if the next segment in the sorted list doesn't connect. This fails to find the longest chain because it doesn't explore all possible connections or handle non-contiguous indices in the sorted array that form a chain. A correct approach would likely involve graph traversal or checking all pairs, not just adjacent ones in a specific sort order.
        }
        if(l>max){
            max=l;
            c=x[i].a[0];
            d=x[i].a[1];
        }
        i=j-1; // @@ This line skips indices based on the previous inner loop's termination. Since the inner loop breaks when a non-matching segment is found, this skip assumes that no future segment can connect to the current chain start 'i' or any segment in the chain. This is incorrect because a segment later in the array might connect to the end of the current chain, extending it. By skipping, we miss potential extensions or alternative chains.
    }
printf("%d %d %d",max,c,d);
return 0;
}