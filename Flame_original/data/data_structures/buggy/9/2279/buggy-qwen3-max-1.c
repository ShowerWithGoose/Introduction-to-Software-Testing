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
            xs[1][i]=1; // @@ [This initializes the chain length to 1 only for segments that are not connected as a continuation of another segment, but it fails to consider that a segment might be the start of a longer chain even if it appears later in input. Also, xs[1][i] is never initialized for cases where o != 0, leading to undefined behavior when accessing uninitialized values later.]
        }
        o=0;
    }
    int i=0,p=0;
    while(i<n){
        if(xs[1][i]>0){
            for(int j=0;j<n;j++){
                if(xs[0][j]==xm[i]&&ys[j]==ym[i]){
                    xm[i]=xm[j];
                    ym[i]=ym[j];
                    xs[1][i]++;
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
            i++; // @@ [The logic for traversing and extending chains is flawed: it only extends one step at a time and may miss longer chains because it doesn't reset or reprocess updated endpoints properly. Also, since xs[1][i] may be uninitialized (see earlier), comparisons like xs[1][i] > 0 can yield unpredictable results.]
        }
    }
    for(int j=0;j<n;j++){
        printf("%d %d\n",xs[1][j],xs[0][j]); // @@ [This debug print is not part of the required output format and will cause the program to fail test cases expecting only the final answer line.]
    }
    int max=0,imax=0;
    for(int j=0;j<n;j++){
        if(max<xs[1][j]){
            imax=j;
            max=xs[1][j];
        }            
    }
    printf("%d %d %d",max,xs[0][imax],ys[imax]); // @@ [If xs[1][j] was never initialized for some j (when o != 0 in earlier loop), then max could be based on garbage values, leading to incorrect output. Additionally, the problem requires the number of segments in the continuous line, but the initialization and update logic for xs[1][i] does not correctly count all segments in the chain.]
    return 0;
}