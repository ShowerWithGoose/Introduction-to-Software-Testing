#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct line{
    int datax;
    int datay;
};
int main(){
    struct line a[100],b[100],c[100];//a为前端点，b为后端点，c为连续线段的后端点； 
    int i,n,itemx,itemy,sum[100],data,line;
    int j,k;
    scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%d%d%d%d",&a[i].datax,&a[i].datay,&b[i].datax,&b[i].datay);

for(i=0;i<n;i++){
    if(a[i].datax>=b[i].datax){
        itemx=a[i].datax;
        a[i].datax=b[i].datax;
        b[i].datax=itemx;
        itemy=a[i].datay;
        a[i].datay=b[i].datay;
        b[i].datay=itemy;
    }
}//将一组线段中横坐标小的坐标放在a组中； 
//for(i=0;i<n;i++)
//printf("%d %d %d %d\n",a[i].datax,a[i].datay,b[i].datax,b[i].datay);调整顺序后值未出现问题 
    for(j=0;j<n;j++){
        sum[j]=1;
        c[j].datax=b[j].datax;
        c[j].datay=b[j].datay;
    
        for(k=0;k<n;k++){
            if(c[j].datax==a[k].datax&&c[j].datay==a[k].datay){
                sum[j]+=1;
                c[j].datax=b[k].datax;c[j].datay=b[k].datay;//连接点变为连接线断的厚点 
                k=0; // @@ The logic resets k to 0 to restart the search from the beginning, but it does not track which segments have already been used in the current chain. This causes infinite loops or incorrect counting if segments form cycles or if a segment is reused. More critically, it fails to distinguish between valid forward connections and backward/reused connections properly without a visited array. However, the primary logical error leading to the wrong answer in this specific context is that the algorithm greedily picks the first match found from index 0, which might not be the correct next segment in the sorted order or might reuse a segment. A correct approach requires sorting or tracking visited nodes. But looking closely at the test case: Segment 2 (7,78)-(27,50) connects to Segment 5 (27,50)-(75,78) which connects to Segment 1 (75,78)-(80,67). The code starts with j=1 (Segment 2: 7,78-27,50). c[1] becomes 27,50. It scans k=0..4. It finds k=4 (27,50-75,78). sum[1]=2. c[1] becomes 75,78. k resets to 0. Scans again. Finds k=0 (75,78-80,67). sum[1]=3. c[1] becomes 80,67. k resets to 0. Scans again. No match. Loop ends. sum[1]=3. This seems correct for j=1. Let's check j=0 (Segment 1: 75,78-80,67). c[0]=80,67. No matches. sum[0]=1. j=2 (Segment 3: 1,2-7,8). c[2]=7,8. Matches k=1 (7,8-9,10). sum[2]=2. c[2]=9,10. No further matches. sum[2]=2. j=3 (Segment 4: 7,78-27,50 is actually index 2 in 0-based? No. Input: 0:75.., 1:7.., 2:7.., 3:1.., 4:27.. Wait. Input: 5 lines. 0: 75 78 80 67. 1: 7 8 9 10. 2: 7 78 27 50. 3: 1 2 7 8. 4: 27 50 75 78. 
                // Let's re-trace j=2 (Index 2: 7,78 -> 27,50). c[2] init to 27,50. 
                // k=0: 75,78 != 27,50.
                // k=1: 7,8 != 27,50.
                // k=2: 7,78 != 27,50.
                // k=3: 1,2 != 27,50.
                // k=4: 27,50 == 27,50. Match. sum[2] becomes 2. c[2] becomes b[4] which is 75,78. k=0.
                // Restart loop k=0..4.
                // k=0: 75,78 == 75,78 (a[0] is 75,78). Match. sum[2] becomes 3. c[2] becomes b[0] which is 80,67. k=0.
                // Restart loop k=0..4.
                // k=0: 80,67 != 75,78.
                // ... no match.
                // So sum[2] = 3. Start point a[2] is 7,78.
                // Now let's look at the selection of the maximum.
                // data=sum[0]=1. line=0.
                // i=1: sum[1]=1. data=1.
                // i=2: sum[2]=3. data=3. line=2.
                // i=3: sum[3]=2.
                // i=4: sum[4]=? j=4 (27,50->75,78). c[4]=75,78. k=0 matches. sum[4]=2. c[4]=80,67. No more.
                // So max is 3 at line=2. Output: 3 7 78.
                // Why did the user get Wrong Answer? 
                // Let's look at the "Visited" issue. If segments share endpoints, can they be reused? "No three or more segments share a single endpoint." "No two line segments intersect in the middle."
                // The problem implies simple chains.
                // Is there a case where resetting k=0 causes a problem? Yes, if A->B and B->A exists (cycle) or A->B and C->B (branching backwards). But constraints say x1 < x2. So edges are directed by X. Cycles are impossible because X must strictly increase. So A(x1)->B(x2) means x1 < x2. Next must start at x2. So X increases. Can't go back. So re-scanning from 0 is safe regarding cycles, but inefficient.
                // However, there is a subtle bug. If multiple segments start at the same point? "No three or more segments share a single endpoint." Two can. If two segments start at the same endpoint, which one do we pick? The problem says "continuous line segment". Usually implies a unique path. If there's a branch, it's not a single continuous line? Or do we pick the longest path? The problem asks for "the continuous line segment containing the maximum number of segments". This implies finding the longest path in a DAG.
                // The greedy approach `k=0` picks the *first* segment in the input array that matches. This might not lead to the longest chain if there's a branch.
                // Example: S1: (0,0)-(1,0). S2: (1,0)-(2,0). S3: (1,0)-(3,0). S4: (3,0)-(4,0).
                // Chain 1: S1->S2 (Len 2). Chain 2: S1->S3->S4 (Len 3).
                // If S2 appears before S3 in input:
                // Start S1. End (1,0). Scan k. Find S2 first. Update end to (2,0). Scan. No match. Len 2.
                // It missed the longer chain because it greedily took the first match.
                // Therefore, the algorithm is incorrect for branching paths. It needs to explore all possibilities (DFS/BFS) or sort and use DP.
                // Given the constraints and typical student errors, this greedy failure is the likely cause.
            }//在找到下一个可连接点后，将数据清空，再次从第一位数开始判断,如果已经用过的那么不会再连接，但是防备前者有可以链接的线段 
        }
    }
    data=sum[0];
    for(i=0;i<n;i++){
        if(sum[i]>=data){
            data=sum[i];
            line=i;
        }
    }
    printf("%d %d %d",data,a[line].datax,a[line].datay);
    return 0;
}