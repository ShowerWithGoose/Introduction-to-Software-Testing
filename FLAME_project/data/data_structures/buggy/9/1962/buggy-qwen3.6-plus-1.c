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
                k=0; // @@ The logic resets k to 0 to restart the search from the beginning, but it does not track which segments have already been used in the current chain. This causes infinite loops or incorrect counting if segments form cycles or if a segment is reused. More critically, it fails to distinguish between different chains properly because it doesn't mark visited segments. However, the primary logical error leading to the wrong answer in this specific context is that when a connection is found, the code updates the current end point (c[j]) and restarts the search. But if multiple segments start at the same point, or if the chain branches (though constraints say no 3+ share endpoint), the simple reset k=0 without a "visited" array means it might re-count segments or get stuck. Actually, the bigger issue is that `k=0` restarts the loop, but the loop increment `k++` happens after the body. So if `k` is set to 0, the next iteration will be `k=1`. It skips index 0. It should be `k=-1` so that `k++` makes it 0. Or better, use a visited array. Without a visited array, the algorithm is fundamentally flawed for general cases, but let's look at the specific failure. The test case has a chain: (7,8)-(9,10) is isolated? No. (1,2)-(7,8) connects to (7,8)-(9,10). And (7,78)-(27,50) connects to (27,50)-(75,78) connects to (75,78)-(80,67). So we have two chains of length 2 and one of length 3? Wait. (1,2)-(7,8) and (7,8)-(9,10) is length 2. (7,78)-(27,50), (27,50)-(75,78), (75,78)-(80,67) is length 3. The expected output is 3 starting at 7 78. The buggy code outputs 2 27 50. This suggests it found a chain of length 2 starting at 27 50? Or maybe it failed to count the full length 3 chain. The `k=0` reset is suspicious. If `k` becomes 0, the `for` loop does `k++` making it 1. It misses checking index 0 again. If the segment at index 0 was the one just added, it shouldn't be checked again anyway if we had a visited array. But without a visited array, it might check other segments. The critical error is likely that `k=0` should be `k=-1` to ensure the next iteration checks index 0, OR more importantly, the algorithm needs to avoid reusing segments. Since constraints say no 3 segments share an endpoint, each segment can only be part of one chain in a simple path. But without marking used segments, if the search restarts, it might pick up a segment that was already part of the chain if the coordinates match (which they shouldn't in a simple path unless it's a cycle, but x increases so no cycles). Wait, x increases strictly. So no cycles. The issue with `k=0` is that it skips `k=0` in the next pass. If the segment needed to be checked at `k=0` (e.g. if the array wasn't sorted or if the connection was earlier in the array), it would be missed. However, the main logical flaw is that it doesn't prevent using the same segment twice if the geometry allowed it (but x-increase prevents it). Let's look closer. If I have segments A->B->C. Start at A. End is B. Find B->C. Update end to C. Reset k. If k=0, next k is 1. If there was another segment starting at B? No, constraint says max 2. So only C starts at B? No, C starts at B. Was C at index 0? If C was at index 0, it is now skipped. This could cause the chain to terminate prematurely if the next segment in the chain happens to be at an index <= the current k before reset. By resetting to 0, we intend to scan all segments again to find the next link. But `k++` makes it 1. So index 0 is never re-checked. If the next segment in the chain is at index 0, it is missed. This is a bug.
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