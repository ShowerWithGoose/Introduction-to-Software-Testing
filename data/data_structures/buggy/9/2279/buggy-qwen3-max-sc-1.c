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
        if(xs[1][i]>0){ // @@ [Accessing xs[1][i] without ensuring it was initialized for all i. For segments where o != 0 in the previous loop, xs[1][i] remains uninitialized (garbage value), causing unpredictable behavior.]
            for(int j=0;j<n;j++){
                if(xs[0][j]==xm[i]&&ys[j]==ym[i]){
                    xm[i]=xm[j];
                    ym[i]=ym[j];
                    xs[1][i]++; // @@ [This attempts to extend the chain by overwriting xm[i] and ym[i], which corrupts the original segment data and breaks further matching. It also doesn't correctly simulate chaining because it modifies the base array instead of tracking chain length separately.]
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
        printf("%d %d\n",xs[1][j],xs[0][j]); // @@ [Debug print not part of required output; may cause wrong output format, but more critically, xs[1][j] may contain garbage for un-initialized entries.]
    }
    int max=0,imax=0;
    for(int j=0;j<n;j++){
        if(max<xs[1][j]){ // @@ [Comparing against uninitialized values in xs[1][j] for segments that were never set (when o != 0 in earlier loop), leading to incorrect max calculation.]
            imax=j;
            max=xs[1][j];
        }            
    }
    printf("%d %d %d",max,xs[0][imax],ys[imax]); // @@ [If no valid chain was found or initialization failed, max could be 0, but problem guarantees at least one segment exists. However, due to uninitialized xs[1][*], output may be wrong. Also, the logic does not correctly count number of segments in chain: it starts at 1 but increments per extension, yet the initial assignment is flawed.]
    return 0;
}