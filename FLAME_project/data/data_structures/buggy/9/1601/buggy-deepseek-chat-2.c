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
            k=c[i];
        }
    }
    printf("%d %d %d",k+1,a[k][0],a[k][1]); // @@ [Error: The starting point should be a[k][0] and a[k][1] only if the segment at index k is the first segment of the longest chain. However, the code uses k (the maximum count) as an index, which is incorrect. The correct starting point should be the first segment of the chain that has the maximum length, not the segment at index k. In the test case, the longest chain starts at segment 0 (12,12), but k=1 (since c[1]=1 is the max), so it incorrectly outputs a[1] which is (13,13).]
}