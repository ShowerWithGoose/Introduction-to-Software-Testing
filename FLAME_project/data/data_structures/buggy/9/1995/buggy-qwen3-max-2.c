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
            }else break; // @@ [This 'break' prematurely exits the inner loop when a non-matching segment is found, but there might be later segments that continue the chain. The algorithm assumes segments are contiguous in the sorted array, which is not guaranteed even after sorting by starting x-coordinate because multiple chains can interleave.]
        }
        if(l>max){
            max=l;
            c=x[i].a[0];
            d=x[i].a[1];
        }
        i=j-1; // @@ [This line skips segments incorrectly. After the inner loop ends (either by break or normal termination), 'j' may be beyond the current chain, but setting 'i = j - 1' causes the outer loop to skip over segments that could be the start of a longer chain. This logic only works if all segments of a chain are consecutive in the array, which is not ensured by the prior sort.]
    }
printf("%d %d %d",max,c,d);
return 0;
}