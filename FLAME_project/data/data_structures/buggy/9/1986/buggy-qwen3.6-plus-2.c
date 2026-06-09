#include <stdio.h>
#include <stdlib.h>
struct Line{
    int x1;
    int y1;
    int x2;
    int y2;
    struct Line *link;
}line[101];
int cmp(const void* a, const void* b){
    return (*(struct Line*)a).x1-(*(struct Line*)b).x1;
}
int main(){
    int n=0,cnt=0,i=0,j=0,k=0,t[2][3]={0}; // @@ [The array t is initialized to 0. If the maximum chain length found is 1 (or if no chain > 1 is found and logic fails to update t[0]), t[0][2] remains 0. However, the main logical error is below.]
    
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d %d %d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
    }
    
    qsort(line,n,sizeof(struct Line),cmp);
    
    
    for(i=0;i<n;i++){
        t[1][0]=line[i].x1;
        t[1][1]=line[i].y1;
        t[1][2]=1;
        k=i;
        for(j=i+1;j<n;j++){
            if(line[k].x2==line[j].x1&&line[k].y2==line[j].y1){
                k=j;
                t[1][2]++;
                if(t[1][2]>t[0][2]){
                t[0][0]=t[1][0];
                t[0][1]=t[1][1];
                t[0][2]=t[1][2];
                printf("%d %d\n",i,t[0][2]);            
                }
            }else if(line[k].x2<line[j].x1){
                break;
            }
        }
        // @@ [Missing logic: After the inner loop finishes for a given i, we must check if the chain starting at i (stored in t[1]) is longer than the current best (t[0]). The current code only updates t[0] inside the inner loop when a link is found. If the longest chain ends such that no further extension is possible but wasn't the one that triggered the update inside, or more critically, if the chain length is 1, t[0] is never updated from its initial 0 state properly relative to other chains of length 1. Specifically, if the max chain is length 2, it gets updated inside. But if there are multiple chains, we need to ensure t[0] holds the global max. The critical bug is that if the best chain is found, it works. BUT, look at the initialization. t[0][2] starts at 0. If n=1, the loops run, t[1][2]=1. The inner loop doesn't run. The check if(t[1][2]>t[0][2]) is NEVER executed because it's outside the inner loop? No, it's inside the inner loop in the buggy code. Wait, the update `if(t[1][2]>t[0][2])` is INSIDE the `if(line[k].x2==line[j].x1...)` block. This means t[0] is ONLY updated when a connection is made. If the maximum chain length is 1 (no connections), t[0][2] remains 0. The final print will output 0. It should output 1. Also, if a chain of length 2 is found, it updates. But what if a chain of length 3 is found later? It updates. The logic seems to track the max so far INSIDE the connection event. However, the standard pattern is to check after the inner loop completes for each start node i. By placing it inside, it misses updating if the logic was slightly different, but here it updates every time cnt increases. The real issue is likely that `t[0]` is not initialized or updated correctly for the case where the best chain might just be the single segment itself if no connections exist, OR if the `break` condition stops checking too early? No, `break` is correct for sorted x1. 
        // Actually, the biggest issue is usually that `t[0]` isn't updated if the chain length doesn't exceed the previous max DURING the linking. But wait, if I have chain A (len 2) and chain B (len 2). Chain A updates t[0] to 2. Chain B updates t[0] to 2. That's fine.
        // Let's look at the "Wrong Answer" output: `0 2`. The expected is `2 12 12`. The buggy output format is `%d %d %d`, printing `t[0][2], t[0][0], t[0][1]`.
        // In the test case: 2 segments. Connected.
        // i=0: t[1] = {12, 12, 1}. k=0. j=1. Match! k=1, t[1][2]=2. 2 > 0. t[0] becomes {12, 12, 2}. Prints "0 2".
        // i=1: t[1] = {13, 13, 1}. k=1. j=2 (loop ends).
        // Final print: "2 12 12".
        // So the output would be:
        // 0 2
        // 2 12 12
        // The expected output is JUST "2 12 12".
        // The extra printf inside the loop is causing Wrong Answer due to extra output.
    }
    printf("%d %d %d",t[0][2],t[0][0],t[0][1]);

    return 0;
}