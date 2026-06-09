#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[100][2],b[100][2],i,j,c[100]={0};
    for(i=0;i<n;i++){
        scanf("%d%d",&a[i][0],&a[i][1]);
        scanf("%d%d",&b[i][0],&b[i][1]);
    }
    for(i=0;i<n;i++){
        int t=i;
        for(j=0;j<n;j++){
            if(j==i){
                j+=1;
                if(j>=n)    break;
            }
            if(b[t][0]==a[j][0]&&b[t][1]==a[j][1]){
                t=j;
                c[i]+=1;
                j=-1;
            }
        }
    }
    int k=0;
    for(i=0;i<n;i++){
        if(c[i]>k){
            k=c[i]; // @@ Error: Only updates the maximum count, not the index of the starting segment. Should also store the index `mem = i` to later output the correct starting point.
        }
    }
    printf("%d %d %d",k+1,a[k][0],a[k][1]); // @@ Error: Uses `k` as an index to retrieve the starting point, but `k` is the count value (number of connections), not the index of the segment. Should use the stored index (e.g., `mem`) instead.
 }