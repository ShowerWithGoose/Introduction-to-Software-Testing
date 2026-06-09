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
            xs[1][i]=1; // @@ [Logic Error: This marks segments that are NOT connected to any previous segment as starting points (count=1). However, the variable name xs[1] suggests it stores the chain length. The logic here is inverted or confusing. A segment is a start of a chain if no other segment ends at its start. This part correctly identifies potential starts, but initializes count to 1.]
        }
        o=0;
    }
    int i=0,p=0;
    while(i<n){
        if(xs[1][i]>0){ // @@ [Logic Error: This loop attempts to extend chains starting from segments marked with xs[1][i]>0. However, the extension logic modifies xm[i] and ym[i] in place, which corrupts the original endpoint data for subsequent checks or other chains. Also, it only checks one step ahead per iteration of the inner loop but doesn't recursively follow the chain correctly if multiple segments need to be traversed. It finds the immediate next segment but updates the current segment's end to that next segment's end, effectively merging them. This greedy approach might work for simple chains but fails if the sorting or order isn't guaranteed to be sequential in the array. More critically, it doesn't handle the case where a chain segment is found but not yet processed as a start node properly if the array isn't sorted by connectivity.]
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
            i++;
        }
    }
    for(int j=0;j<n;j++){
        printf("%d %d\n",xs[1][j],xs[0][j]); // @@ [Debug Output: This line prints intermediate results which are not part of the required output format. It should be removed or commented out in a final solution, but strictly speaking, it causes Wrong Answer if the judge expects exact output matching. However, the problem asks to identify errors leading to WA. The primary WA cause is likely the logic below or this extra output.]
    }
    int max=0,imax=0;
    for(int j=0;j<n;j++){
        if(max<xs[1][j]){
            imax=j;
            max=xs[1][j];
        }            
    }
    printf("%d %d %d",max,xs[0][imax],ys[imax]); // @@ [Output Format Error: The expected output is "2 12 12". The buggy output shows "2 12\n0 13\n2 12 12" in the description, implying the debug print above is present. Even removing that, the logic for finding the start point relies on xs[0][imax] and ys[imax]. If the chain extension logic modified xm/ym but not xs/ys, the start point coordinates are preserved. However, the previous debug print statement violates the output format constraint.]
    return 0;
}