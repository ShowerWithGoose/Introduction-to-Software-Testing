#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>


int xs[2][200],xm[200],ys[200],ym[200];





int main(){
    int n,o=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d%d%d",&xs[0][i],&ys[i],&xm[i],&ym[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(xs[0][i]==xm[j]&&ys[i]==ym[j]){
                o=1;
            }
        }
        if(o==0){
            xs[1][i]=1; // @@ [This initializes the chain length to 1 only for segments that are not endpoints of any other segment, but it fails to consider that a segment might be extendable forward even if it is someone's endpoint. Also, xs[1][i] is never initialized for segments where o != 0, leading to undefined behavior when used later.]
        }
        o=0;
    }
    int i=0,p=0;
    while(i<n){
        if(xs[1][i]>0){ // @@ [If xs[1][i] was never initialized (when o != 0 in previous loop), this condition may evaluate unpredictably due to garbage values.]
            for(int j=0;j<n;j++){
                if(xs[0][j]==xm[i]&&ys[j]==ym[i]){
                    xm[i]=xm[j];
                    ym[i]=ym[j];
                    xs[1][i]++; // @@ [This modifies the endpoint of segment i to extend the chain, but it overwrites xm[i] and ym[i], which may break future connections or cause incorrect comparisons in subsequent iterations. Also, it doesn't mark segment j as used, possibly allowing reuse of the same segment multiple times.]
                    p=1;
                }
            }
            if(p==0){
                i++;
            }
            else{
                p=0;
            }
        }
        else{
            i++;
        }
    }
    for(int j=0;j<n;j++){
        printf("%d %d\n",xs[1][j],xs[0][j]); // @@ [This debug print is not part of the required output format and will cause the program to fail automated judging systems expecting only one line of output.]
    }
    int max=0,imax=0;
    for(int j=0;j<n;j++){
        if(max<xs[1][j]){
            imax=j;
            max=xs[1][j];
        }            
    }
    printf("%d %d %d",max,xs[0][imax],ys[imax]); // @@ [The value of 'max' represents the count of segments in the chain, but due to incorrect initialization and extension logic, it may not reflect the true maximum chain length. Additionally, if no segment was ever initialized in xs[1][*], max remains 0, leading to wrong output.]
    return 0;
}