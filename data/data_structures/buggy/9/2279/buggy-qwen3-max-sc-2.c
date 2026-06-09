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
            xs[1][i]=1; // @@ [This initializes the chain length to 1 only for segments that are not endpoints of any other segment, but it fails to consider that a segment might be extendable forward even if it is someone's endpoint. Also, xs[1][i] is uninitialized for cases where o != 0, leading to undefined behavior later.]
        }
        o=0;
    }
    int i=0,p=0;
    while(i<n){
        if(xs[1][i]>0){ // @@ [Accessing xs[1][i] when it was never initialized for segments that had o != 0 (i.e., those that are endpoints of others). This leads to reading garbage values, causing incorrect chain lengths or infinite loops.]
            for(int j=0;j<n;j++){
                if(xs[0][j]==xm[i]&&ys[j]==ym[i]){
                    xm[i]=xm[j];
                    ym[i]=ym[j];
                    xs[1][i]++; // @@ [Incrementing an uninitialized value if xs[1][i] was not set in the earlier loop (when o != 0), leading to undefined behavior.]
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
        printf("%d %d\n",xs[1][j],xs[0][j]); // @@ [Debug print not matching expected output format; problem requires only one line of output, but this prints n lines. However, the main issue is logical errors above causing wrong xs[1][j] values.]
    }
    int max=0,imax=0;
    for(int j=0;j<n;j++){
        if(max<xs[1][j]){
            imax=j;
            max=xs[1][j];
        }            
    }
    printf("%d %d %d",max,xs[0][imax],ys[imax]); // @@ [If xs[1][j] contains garbage due to uninitialized values, max and imax will be wrong, leading to incorrect output. Also, note that the chain length should count segments, but initialization and extension logic is flawed.]
    return 0;
}