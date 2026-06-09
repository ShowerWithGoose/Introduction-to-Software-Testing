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
            xs[1][i]=1; // @@ [Logic Error: This marks segments that are NOT connected to any previous segment as starting points (count 1). However, the subsequent chaining logic relies on xs[1][i] > 0 to process chains. If a segment is in the middle of a chain but its predecessor hasn't been processed or linked correctly in this specific pass, it might be marked 0. More critically, the initialization logic is flawed for finding the *start* of the longest chain. It identifies "heads" of chains, but the chaining loop below modifies the end coordinates of these heads in place.]
        }
        o=0;
    }
    int i=0,p=0;
    while(i<n){
        if(xs[1][i]>0){
            for(int j=0;j<n;j++){
                if(xs[0][j]==xm[i]&&ys[j]==ym[i]){ // @@ [Logic Error: This condition checks if segment j starts where segment i currently ends. However, it does not check if segment j has already been used/visited in this chain. Since "No three or more segments share a single endpoint", this might seem okay, but if the graph has branches (though constrained to lines here), or if the order of j causes it to pick a wrong segment, it's risky. More importantly, this loop modifies xm[i] and ym[i] in place. If segment j is also a head of another chain (xs[1][j]>0), this logic merges them incorrectly or consumes j without marking it as visited. The major issue is that it doesn't prevent re-using segment j if it appears later in the array or if the logic allows looping back, although constraints say no cycles. The critical bug is that it doesn't mark 'j' as used. If segment A connects to B, and B connects to C. When processing A, it finds B, updates A's end to B's end. Then it should find C. But if B was also initialized as a head (xs[1][B]=1 because nothing connected to its start?), wait. The initialization sets xs[1][i]=1 only if NO segment ends at i's start. So B would have xs[1][B]=0 if A connects to it. So only true heads have xs[1]>0. The loop extends the true heads. The bug is that when it finds j, it doesn't verify j hasn't been consumed by another chain or handle the case where multiple segments could potentially connect (constraint says max 2 share endpoint, so 1 in, 1 out). The real error is likely that `xs[1][i]` counts the number of segments, but `xm[i]` and `ym[i]` are updated. If segment j is found, `xm[i]` becomes `xm[j]`. This is correct for extending. However, if there are disjoint chains, this works for the heads. BUT, look at the output format. The problem asks for the starting point of the continuous line. The code prints `xs[0][imax]` and `ys[imax]`. `imax` is the index of the head segment. This is correct IF the head segment's original start is the start of the chain. The initialization `xs[1][i]=1` happens for segments that are NOT preceded by anyone. These are indeed the starts of chains. So `xs[0][imax]` is the x-start. `ys[imax]` is the y-start. This seems logically sound for finding the start. Let's look at the test case.
Input:
2
12 12 13 13
13 13 50 76

Segment 0: (12,12)-(13,13)
Segment 1: (13,13)-(50,76)

Init Loop:
i=0: Check if any segment ends at (12,12). None. o=0. xs[1][0]=1.
i=1: Check if any segment ends at (13,13). Segment 0 ends at (13,13). o=1. xs[1][1] remains 0 (uninitialized global, so 0).

Chaining Loop:
i=0: xs[1][0]=1 > 0.
  Inner loop j=0: xs[0][0]==xm[0] (12==13)? No.
  Inner loop j=1: xs[0][1]==xm[0] (13==13) AND ys[1]==ym[0] (13==13)? Yes.
    xm[0] = xm[1] = 50.
    ym[0] = ym[1] = 76.
    xs[1][0]++ -> becomes 2.
    p=1.
  p=1, so p reset to 0. i stays 0? No, `if(p==0) i++; else p=0;`. So i stays 0.
  Next iteration i=0: xs[1][0]=2 > 0.
  Inner loop j=0: 12==50? No.
  Inner loop j=1: 13==50? No.
  p remains 0. i becomes 1.
i=1: xs[1][1]=0. i becomes 2.
Loop ends.

Final Loop for Max:
j=0: xs[1][0]=2. max=2, imax=0.
j=1: xs[1][1]=0.

Output:
printf("%d %d %d", max, xs[0][imax], ys[imax]);
max=2, xs[0][0]=12, ys[0]=12.
Output: 2 12 12.

Wait, the buggy output provided in the prompt is:
2 12
0 13
2 12 12

The code has a debug print loop:
    for(int j=0;j<n;j++){
        printf("%d %d\n",xs[1][j],xs[0][j]);
    }
This prints intermediate state.
j=0: xs[1][0]=2, xs[0][0]=12. Prints "2 12".
j=1: xs[1][1]=0, xs[0][1]=13. Prints "0 13".
Then final print: "2 12 12".

The expected output is just "2 12 12".
The presence of the extra debug lines causes the Wrong Answer because the output contains extra lines.

Therefore, the error is the inclusion of the debug printing loop.
]
        }
        else{
            i++;
        }
    }
    for(int j=0;j<n;j++){ // @@ [Output Error: This loop prints intermediate debugging information (count and start x for each segment) which is not part of the required output format. This causes the judge to mark the answer as wrong due to extra output.]
        printf("%d %d\n",xs[1][j],xs[0][j]);
    }
    int max=0,imax=0;
    for(int j=0;j<n;j++){
        if(max<xs[1][j]){
            imax=j;
            max=xs[1][j];
        }            
    }
    printf("%d %d %d",max,xs[0][imax],ys[imax]);
    return 0;
}