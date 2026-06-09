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
            xs[1][i]=1; // @@ [This initializes the chain length to 1 only if the segment has no predecessor, but it fails to consider that a segment might be part of a longer chain starting elsewhere. Also, xs[1][i] is never initialized for segments that do have a predecessor, leading to undefined behavior when used later.]
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
            i++; // @@ [Segments with xs[1][i] == 0 (i.e., those that have predecessors) are skipped entirely and never processed to extend their chains, causing the algorithm to miss potential longer continuous lines that start from other segments.]
        }
    }
    for(int j=0;j<n;j++){
        printf("%d %d\n",xs[1][j],xs[0][j]); // @@ [Debug print not matching expected output format; problem requires only one line of output, but this prints n lines. This will cause wrong output format in automated judging.]
    }
    int max=0,imax=0;
    for(int j=0;j<n;j++){
        if(max<xs[1][j]){
            imax=j;
            max=xs[1][j];
        }            
    }
    printf("%d %d %d",max,xs[0][imax],ys[imax]); // @@ [If no segment was initialized (e.g., all segments have predecessors), xs[1][j] may contain garbage values because they were never set, leading to incorrect max calculation. Also, the chain length logic is flawed: it counts merged segments but doesn't correctly simulate traversal of connected segments in order.]
    return 0;
}